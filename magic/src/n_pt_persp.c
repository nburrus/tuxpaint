/* n_pt_persp.c

   1-, 2-, and 3-point perspective line-drawing tools.
   (Work-in-progress; only handles 1-point at the moment)

   by Bill Kendrick <bill@newbreedsoftware.com>

   December 12, 2023 - December 15, 2023
*/


#include <stdio.h>
#include <string.h>
#include <libintl.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"


enum
{
  TOOL_1PT_SELECT,
  TOOL_1PT_DRAW,
  TOOL_2PT_SELECT,
  TOOL_2PT_DRAW,
  TOOL_3PT_SELECT,
  TOOL_3PT_DRAW,
  NUM_TOOLS
};


const char *sound_filenames[NUM_TOOLS] = {
  "", // FIXME
  "", // FIXME
  "", // FIXME
  "", // FIXME
  "", // FIXME
  "", // FIXME
};

const char *icon_filenames[NUM_TOOLS] = {
  "perspective.png", // FIXME
  "perspective.png", // FIXME
  "perspective.png", // FIXME
  "perspective.png", // FIXME
  "perspective.png", // FIXME
  "perspective.png", // FIXME
};


const char *tool_names[NUM_TOOLS] = {
  gettext_noop("1-Point Select"),
  gettext_noop("1-Point Draw"),
  gettext_noop("2-Point Select"),
  gettext_noop("2-Point Draw"),
  gettext_noop("3-Point Select"),
  gettext_noop("3-Point Draw"),
};


const char *tool_descriptions[NUM_TOOLS] = {
  gettext_noop("Click in your drawing to pick a vanishing point for the 1-point perspective painting tool."),
  gettext_noop("Click and drag to draw lines with your 1-point perspective vanishing point."),
  gettext_noop("Click two places in your drawing to pick vanishing points for the 2-point perspective painting tool."),
  gettext_noop("Click and drag to draw lines with your 2-point perspective vanishing points."),
  gettext_noop("Click three places in your drawing to pick vanishing points for the 3-point perspective painting tool."),
  gettext_noop("Click and drag to draw lines with your 3-point perspective vanishing points."),
};


Mix_Chunk *sound_effects[NUM_TOOLS];

Uint8 n_pt_persp_r, n_pt_persp_g, n_pt_persp_b;
Uint8 n_pt_persp_size = 1;
SDL_Surface * n_pt_persp_snapshot = NULL;

int a1_pt_x, a1_pt_y;
int a2_pt_x[2], a2_pt_y[2], a2_pt_cur;
int a3_pt_x[3], a3_pt_y[3], a3_pt_cur;
int line_start_x, line_start_y;


void n_pt_persp_drag(magic_api * api, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int old_x, int old_y, int x, int y,
  SDL_Rect * update_rect);

void n_pt_persp_work(magic_api * api, int which,
                     SDL_Surface * canvas, int x, int y,
                     SDL_Rect * update_rect, int xor);

void n_pt_persp_line_xor_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y);

void n_pt_persp_line_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y);

void n_pt_persp_draw_points(magic_api * api, int which, SDL_Surface * canvas);

void n_pt_persp_draw_one_point(magic_api * api, SDL_Surface * canvas, int x, int y, int i);


Uint32 n_pt_persp_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}


int n_pt_persp_init(magic_api * api, Uint32 disabled_features)
{
  int i;
  char filename[1024];

  for (i = 0; i < NUM_TOOLS; i++)
  {
    snprintf(filename, sizeof(filename), "%s/sounds/magic/%s", api->data_directory,
             sound_filenames[i]);
    sound_effects[i] = Mix_LoadWAV(filename);
  }

  /* 1-pt perspective initial vanishing point: Center of canvas */
  a1_pt_x = api->canvas_w / 2;
  a1_pt_y = api->canvas_w / 2;

  /* 2-pt perspective initial vanishing points: Left and right, midway up/down the canvas */
  a2_pt_x[0] = 0;
  a2_pt_y[0] = api->canvas_h / 2;

  a2_pt_x[1] = api->canvas_w - 1;
  a2_pt_y[1] = api->canvas_h / 2;

  a2_pt_cur = 0;

  /* 3-pt perspective initial vanishing points: top center, and left and right near bottom of canvas */
  a3_pt_x[0] = api->canvas_w / 2;
  a3_pt_y[0] = 0;

  a3_pt_x[1] = 0;
  a3_pt_y[1] = api->canvas_h * 4 / 5;

  a3_pt_x[2] = api->canvas_w - 1;
  a3_pt_y[2] = api->canvas_h * 4 / 5;

  a3_pt_cur = 0;

  n_pt_persp_snapshot = SDL_CreateRGBSurface(SDL_SWSURFACE, api->canvas_w, api->canvas_h,
                                             32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); // FIXME: Safe?
  if (n_pt_persp_snapshot == NULL) {
    fprintf(stderr, "n_pt_persp -- Could not create a 32-bit surface of size %d x %d!\n", api->canvas_w, api->canvas_h);
    return (0);
  }

  return (1);
}


int n_pt_persp_get_tool_count(magic_api * api)
{
  return 2; // FIXME
  //return (NUM_TOOLS);
}


SDL_Surface *n_pt_persp_get_icon(magic_api * api, int which)
{
  char filename[1024];

  snprintf(filename, sizeof(filename), "%s/images/magic/%s",
           api->data_directory, icon_filenames[which]);

  return (IMG_Load(filename));
}


char *n_pt_persp_get_name(magic_api * api, int which)
{
  return (strdup(gettext(tool_names[which])));
}


int n_pt_persp_get_group(magic_api * api, int which)
{
  return (MAGIC_TYPE_PAINTING);
}


char *n_pt_persp_get_description(magic_api * api, int which, int mode)
{
  return (strdup(gettext(tool_descriptions[which])));
}


int n_pt_persp_requires_colors(magic_api * api, int which)
{
  if (which == TOOL_1PT_DRAW || which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW)
    return 1;
  else
    return 0;
}


int n_pt_persp_modes(magic_api * api, int which)
{
  if (which == TOOL_1PT_DRAW || which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW)
    return MODE_PAINT;
  else
    return MODE_FULLSCREEN;
}

Uint8 n_pt_persp_accepted_sizes(magic_api * api, int which, int mode)
{
  if (which == TOOL_1PT_DRAW || which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW)
    return 4;
  else
    return 0;
}


Uint8 n_pt_persp_default_size(magic_api * api, int which, int mode)
{
  return 1;
}


void n_pt_persp_shutdown(magic_api * api)
{
  int i;

  if (n_pt_persp_snapshot != NULL) {
    SDL_FreeSurface(n_pt_persp_snapshot);
  }

  for (i = 0; i < NUM_TOOLS; i++) {
    if (sound_effects[i] != NULL) {
      Mix_FreeChunk(sound_effects[i]);
    }
  }
}


void n_pt_persp_click(magic_api * api, int which, int mode,
                      SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                      SDL_Rect * update_rect)
{
  if (which == TOOL_1PT_SELECT) {
    /* Set position of 1-point perspective */
    a1_pt_x = x;
    a1_pt_y = y;
  } else if (which == TOOL_2PT_SELECT) {
    /* Set next position of 2-point perspective */
    a2_pt_x[a2_pt_cur] = x;
    a2_pt_y[a2_pt_cur] = y;
    a2_pt_cur = (a2_pt_cur + 1) % 2;
  } else if (which == TOOL_3PT_SELECT) {
    /* Set next position of 3-point perspective */
    a3_pt_x[a3_pt_cur] = x;
    a3_pt_y[a3_pt_cur] = y;
    a3_pt_cur = (a3_pt_cur + 1) % 3;
  } else {
    /* Start drawing a line */
    SDL_BlitSurface(canvas, NULL, n_pt_persp_snapshot, NULL);

    line_start_x = x;
    line_start_y = y;
    n_pt_persp_drag(api, which, canvas, snapshot, x, y, x, y, update_rect);

    return;
  }

  /* Still here? Draw points */

  SDL_BlitSurface(n_pt_persp_snapshot, NULL, canvas, NULL);
  n_pt_persp_draw_points(api, which, canvas);

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}


/* Affect the canvas on drag: */
void n_pt_persp_drag(magic_api * api, int which,
                     SDL_Surface * canvas, SDL_Surface * snapshot,
                     int old_x, int old_y, int x, int y,
                     SDL_Rect * update_rect)
{
  /* Draw the line (preview) */
  n_pt_persp_work(api, which, canvas, x, y, update_rect, 1);

  /* Show some guides */
  if (which == TOOL_1PT_DRAW) {
    /* 1-point perspective */

    /* Horizontal line (horizon) */
    if (y != a1_pt_y) {
      api->line((void *) api, which, canvas, NULL,
                0, a1_pt_y, canvas->w - 1, a1_pt_y, 12,
                n_pt_persp_line_xor_callback);
    }

    /* Horizontal line (from cursor) */
    api->line((void *) api, which, canvas, NULL,
              0, y, canvas->w - 1, y, 6,
              n_pt_persp_line_xor_callback);

    /* Vertical line */
    api->line((void *) api, which, canvas, NULL,
              x, 0, x, canvas->h - 1, 6,
              n_pt_persp_line_xor_callback);

    /* Diagonal line to the vanishing point */
    api->line((void *) api, which, canvas, NULL,
              x, y, a1_pt_x, a1_pt_y, 12,
              n_pt_persp_line_xor_callback);
  }
}

#define SNAP 10

void n_pt_persp_work(magic_api * api, int which,
                     SDL_Surface * canvas, int x, int y,
                     SDL_Rect * update_rect, int xor)
{
  int portion_x1, portion_y1, portion_x2, portion_y2, portion_w, portion_h;
  int x1, y1, x2, y2;
  float slope, slope2;
  SDL_Rect area_rect;

  if (n_pt_persp_snapshot == NULL)
    return;

  /* Adhere x & y to perspective! */

  x1 = y1 = x2 = y2 = 0;

  if (which == TOOL_1PT_DRAW) {
    /* 1-point perspective */

    x1 = line_start_x;
    y1 = line_start_y;

    if (abs(line_start_x - x) <= SNAP) {
      /* Vertical */
      x2 = x1;
      y2 = y;
    } else if (abs(line_start_y - y) <= SNAP) {
      /* Horizontal */
      x2 = x;
      y2 = y1;
    } else {
      /* Diagonal */

      slope = ((float) y1 - (float) a1_pt_y) / ((float) x1 - (float) a1_pt_x);
      x2 = x;
      y2 = line_start_y + (slope * (x - line_start_x));

      /* Don't go past our cursor's Y */
      if ((y < line_start_y && y2 < y) ||
          (y > line_start_y && y2 > y)) {
        if (slope != 0.0) {
          y2 = y;
          x2 = ((y - line_start_y) / slope) + line_start_x;
        }
      }

      /* Snap to horizontal if cursor is on the wrong side */
      slope2 = ((float) line_start_y - (float) y) / ((float) line_start_x - (float) x);
      if ((slope2 > 0.00 && slope < 0.00) ||
          (slope2 < 0.00 && slope > 0.00)) {
        x2 = x;
        y2 = y1;
      }
    }
  } else if (which == TOOL_2PT_DRAW) {
    /* 2-point perspective */

    /* FIXME */
    return;
  } else if (which == TOOL_3PT_DRAW) {
    /* 3-point perspective */

    /* FIXME */
    return;
  }

  portion_x1 = x1;
  portion_y1 = y1;
  portion_x2 = x2;
  portion_y2 = y2;

  if (portion_x1 > portion_x2)
  {
    int temp = portion_x1;

    portion_x1 = portion_x2;
    portion_x2 = temp;
  }
  if (portion_y1 > portion_y2)
  {
    int temp = portion_y1;

    portion_y1 = portion_y2;
    portion_y2 = temp;
  }

  portion_w = (portion_x2 - portion_x1) + 1;
  portion_h = (portion_y2 - portion_y1) + 1;

  /* FIXME: Not working correctly!? -bjk 2023.12.13 */
  area_rect.x = portion_x1;
  area_rect.y = portion_y1;
  area_rect.w = portion_w;
  area_rect.h = portion_h;

  SDL_BlitSurface(n_pt_persp_snapshot, NULL /* FIXME &area_rect */, canvas, NULL /* FIXME &area_rect */);

  /* Draw the line */

  if (xor) {
    /* Still moving; use XOR */

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 3,
              n_pt_persp_line_xor_callback);

    update_rect->x = portion_x1;
    update_rect->y = portion_y1;
    update_rect->w = portion_w + 1;
    update_rect->h = portion_h + 1;
  } else {
    /* Released; draw the line for real */

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 1,
              n_pt_persp_line_callback);

    update_rect->x = portion_x1 - n_pt_persp_size;
    update_rect->y = portion_y1 - n_pt_persp_size;
    update_rect->w = portion_w + n_pt_persp_size;
    update_rect->h = portion_h + n_pt_persp_size;
  }

  /* FIXME */
  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  api->playsound(sound_effects[which],
    (x * 255) / canvas->w, 255);
}


void n_pt_persp_release(magic_api * api, int which,
                        SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                        SDL_Rect * update_rect)
{
  /* Draw the line (for real) */
  n_pt_persp_work(api, which, canvas, x, y, update_rect, 0);
}


void n_pt_persp_set_color(magic_api * api, int which, SDL_Surface * canvas, SDL_Surface * snapshot, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect)
{
  n_pt_persp_r = r;
  n_pt_persp_g = g;
  n_pt_persp_b = b;
}


void n_pt_persp_set_size(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED,
                         SDL_Surface * canvas ATTRIBUTE_UNUSED, SDL_Surface * last ATTRIBUTE_UNUSED,
                         Uint8 size, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
  n_pt_persp_size = ((size - 1) * 2) + 1;
}


void n_pt_persp_line_xor_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y)
{
  magic_api *api = (magic_api *) pointer;
  Uint8 r, g, b;

  SDL_GetRGB(api->getpixel(canvas, x, y), canvas->format, &r, &g, &b);
  r ^= 255;
  g ^= 255;
  b ^= 255;
  api->putpixel(canvas, x, y, SDL_MapRGB(canvas->format, r, g, b));

  SDL_GetRGB(api->getpixel(canvas, x + 1, y + 1), canvas->format, &r, &g, &b);
  r ^= 255;
  g ^= 255;
  b ^= 255;
  api->putpixel(canvas, x + 1, y + 1, SDL_MapRGB(canvas->format, r, g, b));
}

void n_pt_persp_line_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y)
{
  magic_api *api = (magic_api *) pointer;
  SDL_Rect r;

  r.x = x - n_pt_persp_size;
  r.y = y - n_pt_persp_size;
  r.w = n_pt_persp_size * 2;
  r.h = n_pt_persp_size * 2;

  SDL_FillRect(canvas, &r, SDL_MapRGB(canvas->format, n_pt_persp_r, n_pt_persp_g, n_pt_persp_b));
}

void n_pt_persp_switchin(magic_api * api, int which, int mode,
                      SDL_Surface * canvas)
{
  if (which == TOOL_1PT_SELECT || which == TOOL_2PT_SELECT || which == TOOL_3PT_SELECT) {
    SDL_BlitSurface(canvas, NULL, n_pt_persp_snapshot, NULL);

    n_pt_persp_draw_points(api, which, canvas);
  }
}

void n_pt_persp_switchout(magic_api * api, int which, int mode,
                       SDL_Surface * canvas)
{
  if (which == TOOL_1PT_SELECT || which == TOOL_2PT_SELECT || which == TOOL_3PT_SELECT) {
    SDL_BlitSurface(n_pt_persp_snapshot, NULL, canvas, NULL);
  }
}

void n_pt_persp_draw_points(magic_api * api, int which, SDL_Surface * canvas) {
  int i, l, m, x1, y1, x2, y2;
  float slope;

  if (which == TOOL_1PT_SELECT) {
    /* 1-point perspective */

    n_pt_persp_draw_one_point(api, canvas, a1_pt_x, a1_pt_y, 0);

    for (l = 0; l < 5; l++) {
      /* Diagonal from left to right sides of canvas */

      y1 = (a1_pt_y - (canvas->h / 2)) + (canvas->h / 5) * l + (canvas->h / 10);

      if (a1_pt_x > canvas->w / 2) {
        x1 = 0;
        x2 = canvas->w - 1;
      } else {
        x1 = canvas->w - 1;
        x2 = 0;
      }

      slope = ((float) a1_pt_y - (float) y1) / ((float) a1_pt_x - (float) x1);
      y2 = y1 + (x2 - x1) * slope;

      api->line((void *) api, which, canvas, NULL,
                x1, y1, x2, y2, 6,
                n_pt_persp_line_xor_callback);

      /* Some vertical lines between the diagonals */
      if (l == 0) {
        for (m = 0; m < 8; m++) {
          int xx, yy1, yy2, mm;
          int m_scale[8] = {-8,-4,-2,-1,1,2,4,8};

          xx = a1_pt_x + ((float) (canvas->w / 10) * (float) m_scale[m]);
          yy1 = a1_pt_y + (a1_pt_x - xx) * slope;
          yy2 = a1_pt_y + (xx - a1_pt_x) * slope;

          api->line((void *) api, which, canvas, NULL,
                    xx, yy1, xx, yy2, 3,
                    n_pt_persp_line_xor_callback);
        }
      }
    }
  } else if (which == TOOL_2PT_SELECT) {
    /* 2-point perspective */

    for (i = 0; i < 2; i++) {
      n_pt_persp_draw_one_point(api, canvas, a2_pt_x[i], a2_pt_y[i], i);
    }

    /* FIXME: Draw a grid */
  } else if (which == TOOL_3PT_SELECT) {
    /* 2-point perspective */

    for (i = 0; i < 3; i++) {
      n_pt_persp_draw_one_point(api, canvas, a3_pt_x[i], a3_pt_y[i], i);
    }

    /* FIXME: Draw a grid */
  }
}

#define DOT_WIDTH 12

void n_pt_persp_draw_one_point(magic_api * api, SDL_Surface * canvas, int x, int y, int i) {
  int xx, yy;
  Uint8 r, g, b;

  for (yy = -(DOT_WIDTH + i); yy <= DOT_WIDTH + i; yy++) {
    for (xx = -(DOT_WIDTH + i) + (yy % 2); xx <= DOT_WIDTH + i; xx += 2) {
      if (api->in_circle(xx, yy, DOT_WIDTH) && abs(xx) >= i && abs(yy) >= i) {
        SDL_GetRGB(api->getpixel(canvas, x + xx, y + yy), canvas->format, &r, &g, &b);
        r ^= 255;
        g ^= 255;
        b ^= 255;
        api->putpixel(canvas, x + xx, y + yy, SDL_MapRGB(canvas->format, r, g, b));
      }
    }
  }
}
