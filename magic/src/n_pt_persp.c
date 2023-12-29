/* n_pt_persp.c

   1-, 2-, and 3-point perspective line-drawing tools.
   (Work-in-progress; only handles 1-point at the moment)

   by Bill Kendrick <bill@newbreedsoftware.com>

   December 12, 2023 - December 29, 2023
*/


#include <stdio.h>
#include <string.h>
#include <libintl.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#define SNAP 10


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


enum {
  SND_SELECT,
  SND_DRAW_CLICK,
  SND_DRAW_RELEASE,
  NUM_SNDS
};

const char *sound_filenames[NUM_SNDS] = {
  "n_pt_persp_select.ogg",
  "n_pt_persp_click.ogg",
  "n_pt_persp_release.ogg",
};

const char *icon_filenames[NUM_TOOLS] = {
  "1pt_persp_select.png",
  "1pt_persp_draw.png",
  "2pt_persp_select.png",
  "2pt_persp_draw.png",
  "3pt_persp_select.png",
  "3pt_persp_draw.png",
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
float a2_valid_angle[8];
float a3_valid_angle[8];

/* Function prototypes: */
Uint32 n_pt_persp_api_version(void);
int n_pt_persp_init(magic_api * api, Uint8 disabled_features, Uint8 complexity_level);
int n_pt_persp_get_tool_count(magic_api * api);
SDL_Surface *n_pt_persp_get_icon(magic_api * api, int which);
char *n_pt_persp_get_name(magic_api * api, int which);
int n_pt_persp_get_group(magic_api * api, int which);
char *n_pt_persp_get_description(magic_api * api, int which, int mode);
int n_pt_persp_requires_colors(magic_api * api, int which);
int n_pt_persp_modes(magic_api * api, int which);
Uint8 n_pt_persp_accepted_sizes(magic_api * api, int which, int mode);
Uint8 n_pt_persp_default_size(magic_api * api, int which, int mode);
void n_pt_persp_shutdown(magic_api * api);
void n_pt_persp_click(magic_api * api, int which, int mode,
                      SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                      SDL_Rect * update_rect);
void n_pt_persp_vanish_pt_moved(magic_api * api, int which, SDL_Surface * canvas, SDL_Rect * update_rect);
void n_pt_persp_drag(magic_api * api, int which,
                     SDL_Surface * canvas, SDL_Surface * snapshot,
                     int old_x, int old_y, int x, int y,
                     SDL_Rect * update_rect);
void n_pt_persp_work(magic_api * api, int which,
                     SDL_Surface * canvas, int x, int y,
                     SDL_Rect * update_rect, int xor);
void n_pt_persp_release(magic_api * api, int which,
                        SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                        SDL_Rect * update_rect);
void n_pt_persp_set_color(magic_api * api, int which, SDL_Surface * canvas,
                          SDL_Surface * snapshot, Uint8 r, Uint8 g, Uint8 b,
                          SDL_Rect * update_rect);
void n_pt_persp_set_size(magic_api * api, int which, int mode,
                         SDL_Surface * canvas, SDL_Surface * last,
                         Uint8 size, SDL_Rect * update_rect);
void n_pt_persp_line_xor_callback(void *pointer, int which, SDL_Surface * canvas,
                                  SDL_Surface * snapshot, int x, int y);
void n_pt_persp_line_callback(void *pointer, int which, SDL_Surface * canvas,
                              SDL_Surface * snapshot, int x, int y);
void n_pt_persp_switchin(magic_api * api, int which, int mode,
                      SDL_Surface * canvas);
void n_pt_persp_switchout(magic_api * api, int which, int mode,
                       SDL_Surface * canvas);
void n_pt_persp_draw_points(magic_api * api, int which, SDL_Surface * canvas);
void n_pt_persp_draw_one_point(magic_api * api, SDL_Surface * canvas, int x, int y, int i);


Uint32 n_pt_persp_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}


int n_pt_persp_init(magic_api * api, Uint8 disabled_features ATTRIBUTE_UNUSED, Uint8 complexity_level)
{
  int i;
  char filename[1024];

  for (i = 0; i < NUM_SNDS; i++)
  {
    snprintf(filename, sizeof(filename), "%s/sounds/magic/%s", api->data_directory,
             sound_filenames[i]);
    sound_effects[i] = Mix_LoadWAV(filename);
  }

  /* Set default vanishing point positions: */

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
  a3_pt_x[0] = api->canvas_w * 1 / 20;
  a3_pt_y[0] = api->canvas_h * 19 / 20;

  a3_pt_x[1] = api->canvas_w * 19 / 20;
  a3_pt_y[1] = api->canvas_h * 19 / 20;

  a3_pt_x[2] = api->canvas_w / 2;
  a3_pt_y[2] = api->canvas_h * 1 / 20;

  a3_pt_cur = 0;

  n_pt_persp_snapshot = SDL_CreateRGBSurface(SDL_SWSURFACE, api->canvas_w, api->canvas_h,
                                             32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); // FIXME: Safe?
  if (n_pt_persp_snapshot == NULL) {
    fprintf(stderr, "n_pt_persp -- Could not create a 32-bit surface of size %d x %d!\n", api->canvas_w, api->canvas_h);
    return (0);
  }

  return (1);
}


int n_pt_persp_get_tool_count(magic_api * api ATTRIBUTE_UNUSED)
{
  return (NUM_TOOLS);
}


SDL_Surface *n_pt_persp_get_icon(magic_api * api, int which)
{
  char filename[1024];

  snprintf(filename, sizeof(filename), "%s/images/magic/%s",
           api->data_directory, icon_filenames[which]);

  return (IMG_Load(filename));
}


char *n_pt_persp_get_name(magic_api * api ATTRIBUTE_UNUSED, int which)
{
  return (strdup(gettext(tool_names[which])));
}


int n_pt_persp_get_group(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return (MAGIC_TYPE_PAINTING);
}


char *n_pt_persp_get_description(magic_api * api ATTRIBUTE_UNUSED, int which, int mode ATTRIBUTE_UNUSED)
{
  return (strdup(gettext(tool_descriptions[which])));
}


int n_pt_persp_requires_colors(magic_api * api ATTRIBUTE_UNUSED, int which)
{
  if (which == TOOL_1PT_DRAW || which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW)
    return 1;
  else
    return 0;
}


int n_pt_persp_modes(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return MODE_PAINT;
}

Uint8 n_pt_persp_accepted_sizes(magic_api * api ATTRIBUTE_UNUSED, int which, int mode ATTRIBUTE_UNUSED)
{
  if (which == TOOL_1PT_DRAW || which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW)
    return 4;
  else
    return 0;
}


Uint8 n_pt_persp_default_size(magic_api * api ATTRIBUTE_UNUSED,
                              int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED)
{
  return 1;
}


void n_pt_persp_shutdown(magic_api * api ATTRIBUTE_UNUSED)
{
  int i;

  if (n_pt_persp_snapshot != NULL) {
    SDL_FreeSurface(n_pt_persp_snapshot);
  }

  for (i = 0; i < NUM_SNDS; i++) {
    if (sound_effects[i] != NULL) {
      Mix_FreeChunk(sound_effects[i]);
    }
  }
}


void n_pt_persp_click(magic_api * api, int which, int mode ATTRIBUTE_UNUSED,
                      SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                      SDL_Rect * update_rect)
{
  int pick, i;
  float dist, min_dist;

  pick = 0;
  min_dist = FLT_MAX;

  if (which == TOOL_1PT_SELECT) {
    /* Set position of 1-point perspective */
    a1_pt_x = x;
    a1_pt_y = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  } else if (which == TOOL_2PT_SELECT) {
    /* Pick closest 2-point perspective & move it */

    for (i = 0; i < 2; i++) {
      dist = sqrt(pow(a2_pt_x[i] - x, 2) + pow(a2_pt_y[i] - y, 2));
      if (dist < min_dist) {
        pick = i;
        min_dist = dist;
      }
    }

    a2_pt_cur = pick;

    a2_pt_x[a2_pt_cur] = x;
    a2_pt_y[a2_pt_cur] = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  } else if (which == TOOL_3PT_SELECT) {
    /* Pick closest 3-point perspective & move it */
    for (i = 0; i < 3; i++) {
      dist = sqrt(pow(a3_pt_x[i] - x, 2) + pow(a3_pt_y[i] - y, 2));
      if (dist < min_dist) {
        pick = i;
        min_dist = dist;
      }
    }

    a3_pt_cur = pick;

    a3_pt_x[a3_pt_cur] = x;
    a3_pt_y[a3_pt_cur] = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  } else {
    int i;

    api->playsound(sound_effects[SND_DRAW_CLICK], (x * 255) / canvas->w, 255);

    /* Start drawing a line */
    SDL_BlitSurface(canvas, NULL, n_pt_persp_snapshot, NULL);

    if (which == TOOL_2PT_DRAW) {
      /* Horizon between vanishing points, and perpendicular (rise above/below) */
      a2_valid_angle[0] = atan2(a2_pt_y[1] - a2_pt_y[0], a2_pt_x[1] - a2_pt_x[0]);
      a2_valid_angle[1] = a2_valid_angle[0] + M_PI;
      a2_valid_angle[2] = a2_valid_angle[0] + (M_PI / 2.0);
      a2_valid_angle[3] = a2_valid_angle[0] + (M_PI / 2.0) + M_PI;

      /* Angles that point toward the two vanishing points */
      if (x == a2_pt_x[0]) {
        x++;
      }
      if (x == a2_pt_x[1]) {
        x++;
      }
      a2_valid_angle[4] = atan2(a2_pt_y[0] - y, a2_pt_x[0] - x);
      a2_valid_angle[5] = a2_valid_angle[4] + M_PI;
      a2_valid_angle[6] = atan2(a2_pt_y[1] - y, a2_pt_x[1] - x);
      a2_valid_angle[7] = a2_valid_angle[6] + M_PI;

      for (i = 0; i < 8; i++) {
        if (a2_valid_angle[i] > M_PI) {
          a2_valid_angle[i] -= (M_PI * 2);
        }
      }
    } else if (which == TOOL_3PT_DRAW) {
      /* Horizon between vanishing points, and perpendicular (rise above/below) */
      a3_valid_angle[0] = atan2(a3_pt_y[1] - a3_pt_y[0], a3_pt_x[1] - a3_pt_x[0]);
      a3_valid_angle[1] = a3_valid_angle[0] + M_PI;

      /* Angles that point toward the three vanishing points */
      a3_valid_angle[2] = atan2(a3_pt_y[0] - y, a3_pt_x[0] - x);
      a3_valid_angle[3] = a3_valid_angle[2] + M_PI;
      a3_valid_angle[4] = atan2(a3_pt_y[1] - y, a3_pt_x[1] - x);
      a3_valid_angle[5] = a3_valid_angle[4] + M_PI;
      a3_valid_angle[6] = atan2(a3_pt_y[2] - y, a3_pt_x[2] - x);
      a3_valid_angle[7] = a3_valid_angle[6] + M_PI;

      for (i = 0; i < 8; i++) {
        if (a3_valid_angle[i] > M_PI) {
          a3_valid_angle[i] -= (M_PI * 2);
        }
      }
    }

    line_start_x = x;
    line_start_y = y;
    n_pt_persp_drag(api, which, canvas, snapshot, x, y, x, y, update_rect);
  }
}


void n_pt_persp_vanish_pt_moved(magic_api * api, int which, SDL_Surface * canvas, SDL_Rect * update_rect) {
  SDL_BlitSurface(n_pt_persp_snapshot, NULL, canvas, NULL);
  n_pt_persp_draw_points(api, which, canvas);

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  api->playsound(sound_effects[SND_SELECT], 128, 255);
}


/* Affect the canvas on drag: */
void n_pt_persp_drag(magic_api * api, int which,
                     SDL_Surface * canvas, SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                     int old_x ATTRIBUTE_UNUSED, int old_y ATTRIBUTE_UNUSED,
                     int x, int y, SDL_Rect * update_rect)
{
  int i, x1, y1, x2, y2;
  float slope;

  /* Draw the line (preview) */
  n_pt_persp_work(api, which, canvas, x, y, update_rect, 1);

  /* Show some guides */
  if (which == TOOL_1PT_DRAW) {
    /* 1-point perspective - draw */

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
  } else if (which == TOOL_2PT_DRAW) {
    /* 2-point perspective - draw */
    n_pt_persp_draw_points(api, TOOL_2PT_SELECT, canvas);

    slope = ((float) a2_pt_y[0] - (float) a2_pt_y[1]) / ((float) a2_pt_x[0] - (float) a2_pt_x[1]);

    /* Horizon line (from the cursor) */
    x1 = 0;
    y1 = y - (x * slope);
    x2 = canvas->w;
    y2 = y + ((canvas->w - x) * slope);
    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 5,
              n_pt_persp_line_xor_callback);

    /* Perpendicular-to-horizon line (from the cursor) */
    if (slope == 0.0 || slope == M_PI) {
      x1 = x;
      y1 = 0;
      x2 = x;
      y2 = canvas->h;
    } else {
      float perp_slope = -(slope);

      x1 = x - (y * perp_slope);
      y1 = 0;
      x2 = x + ((canvas->h - y) * perp_slope);
      y2 = canvas->h;
    }

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 5,
              n_pt_persp_line_xor_callback);

    /* Diagonal lines from cursor to the vanishing points */
    for (i = 0; i < 2; i++) {
      if (x != a2_pt_x[i]) {
        slope = ((float) y - (float) a2_pt_y[i]) / ((float) x - (float) a2_pt_x[i]);

        x1 = 0;
        y1 = a2_pt_y[i] - (a2_pt_x[i] * slope);
        x2 = canvas->w;
        y2 = a2_pt_y[i] + ((canvas->w - a2_pt_x[i]) * slope);

        api->line((void *) api, which, canvas, NULL,
                  x1, y1, x2, y2, 2,
                  n_pt_persp_line_xor_callback);
      }
    }
  } else if (which == TOOL_3PT_DRAW) {
    /* 3-point perspective - draw */

    n_pt_persp_draw_points(api, TOOL_3PT_SELECT, canvas);

    /* Horizon line (from the cursor) */
    slope = ((float) a3_pt_y[0] - (float) a3_pt_y[1]) / ((float) a3_pt_x[0] - (float) a3_pt_x[1]);
    x1 = 0;
    y1 = y - (x * slope);
    x2 = canvas->w;
    y2 = y + ((canvas->w - x) * slope);
    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 5,
              n_pt_persp_line_xor_callback);

    /* N.B. No "vertical" line; the 3rd vanishing point defines "up" and "down" */

    /* Diagonal lines from cursor to the vanishing points */
    for (i = 0; i < 3; i++) {
      if (x != a3_pt_x[i]) {
        slope = ((float) y - (float) a3_pt_y[i]) / ((float) x - (float) a3_pt_x[i]);

        x1 = 0;
        y1 = a3_pt_y[i] - (a3_pt_x[i] * slope);
        x2 = canvas->w;
        y2 = a3_pt_y[i] + ((canvas->w - a3_pt_x[i]) * slope);

        api->line((void *) api, which, canvas, NULL,
                  x1, y1, x2, y2, 2,
                  n_pt_persp_line_xor_callback);
      }
    }
  } else if (which == TOOL_1PT_SELECT) {
    /* 1-point perspective - select */
    a1_pt_x = x;
    a1_pt_y = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  } else if (which == TOOL_2PT_SELECT) {
    /* 2-point perspective - select */
    a2_pt_x[a2_pt_cur] = x;
    a2_pt_y[a2_pt_cur] = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  } else if (which == TOOL_3PT_SELECT) {
    /* 3-point perspective - select */
    a3_pt_x[a3_pt_cur] = x;
    a3_pt_y[a3_pt_cur] = y;

    n_pt_persp_vanish_pt_moved(api, which, canvas, update_rect);
  }
}

void n_pt_persp_work(magic_api * api, int which,
                     SDL_Surface * canvas, int x, int y,
                     SDL_Rect * update_rect, int xor)
{
  int x1, y1, x2, y2;
  float slope, slope2;
  int i, best_angle_idx;
  float cursor_angle, diff, best_diff;
  /* SDL_Rect area_rect; */

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
  } else if (which == TOOL_2PT_DRAW || which == TOOL_3PT_DRAW) {
    float * valid_angle;

    /* 2- & 3-point perspective */

    if (which == TOOL_2PT_DRAW) {
      valid_angle = a2_valid_angle;
    } else {
      valid_angle = a3_valid_angle;
    }

    /* Find the valid angle that the drawn angle fits best to */
    cursor_angle = atan2f(y - line_start_y, x - line_start_x);

    best_angle_idx = -1;
    best_diff = M_PI * 2;

    for (i = 0; i < 8; i++) {
      diff = fabs(cursor_angle - valid_angle[i]);

      if (diff < best_diff) {
        best_angle_idx = i;
        best_diff = diff;
      }
    }

    if (best_angle_idx == -1) {
      printf("???\n");
      return;
    }

    /* Calculate a line segment, so we can determine the slope */
    x1 = line_start_x;
    y1 = line_start_y;
    x2 = line_start_x + cos(valid_angle[best_angle_idx]) * 1000;
    y2 = line_start_y + sin(valid_angle[best_angle_idx]) * 1000;

    if (abs(x2 - x1) >= 2) {
      slope = ((float) y2 - (float) y1) / ((float) x2 - (float) x1);
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
    } else {
      x2 = x1;
      y2 = y;
    }
  }

  SDL_BlitSurface(n_pt_persp_snapshot, NULL, canvas, NULL);

  /* Draw the line */

  if (xor) {
    /* Still moving; use XOR */

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 3,
              n_pt_persp_line_xor_callback);
  } else {
    /* Released; draw the line for real */

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 1,
              n_pt_persp_line_callback);
  }

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}


void n_pt_persp_release(magic_api * api, int which,
                        SDL_Surface * canvas, SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                        int x, int y, SDL_Rect * update_rect)
{
  if (which == TOOL_1PT_SELECT) {
    /* 1-point perspective - vanishing point drag released */
    api->stopsound();
  } else if (which == TOOL_2PT_SELECT) {
    /* 2-point perspective - vanishing point drag released */
    if (abs(a2_pt_x[0] - a2_pt_x[1]) < SNAP) {
      if (a2_pt_x[0] <= a2_pt_x[1]) {
        a2_pt_x[0] -= (SNAP / 2);
        a2_pt_x[1] += (SNAP / 2);
      } else {
        a2_pt_x[0] += (SNAP / 2);
        a2_pt_x[1] -= (SNAP / 2);
      }
    }
    api->stopsound();
  } else if (which == TOOL_3PT_SELECT) {
    /* 3-point perspective - vanishing point drag released */
    api->stopsound();
  } else {
    /* Draw the line (for real) */
    n_pt_persp_work(api, which, canvas, x, y, update_rect, 0);

    api->playsound(sound_effects[SND_DRAW_RELEASE], (x * 255) / canvas->w, 255);
  }
}


void n_pt_persp_set_color(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                          SDL_Surface * canvas ATTRIBUTE_UNUSED,
                          SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                          Uint8 r, Uint8 g, Uint8 b,
                          SDL_Rect * update_rect ATTRIBUTE_UNUSED)
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


void n_pt_persp_line_xor_callback(void *pointer, int which ATTRIBUTE_UNUSED, SDL_Surface * canvas,
                                  SDL_Surface * snapshot ATTRIBUTE_UNUSED, int x, int y)
{
  magic_api *api = (magic_api *) pointer;

  api->xorpixel(canvas, x, y);
  api->xorpixel(canvas, x + 1, y + 1);
}

void n_pt_persp_line_callback(void *pointer ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                              SDL_Surface * canvas, SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                              int x, int y)
{
  SDL_Rect r;

  r.x = x - n_pt_persp_size / 2;
  r.y = y - n_pt_persp_size / 2;
  r.w = n_pt_persp_size;
  r.h = n_pt_persp_size;

  SDL_FillRect(canvas, &r, SDL_MapRGB(canvas->format, n_pt_persp_r, n_pt_persp_g, n_pt_persp_b));
}

void n_pt_persp_switchin(magic_api * api, int which, int mode ATTRIBUTE_UNUSED,
                         SDL_Surface * canvas)
{
  if (which == TOOL_1PT_SELECT || which == TOOL_2PT_SELECT || which == TOOL_3PT_SELECT) {
    SDL_BlitSurface(canvas, NULL, n_pt_persp_snapshot, NULL);

    n_pt_persp_draw_points(api, which, canvas);
  }
}

void n_pt_persp_switchout(magic_api * api ATTRIBUTE_UNUSED, int which, int mode ATTRIBUTE_UNUSED,
                          SDL_Surface * canvas)
{
  if (which == TOOL_1PT_SELECT || which == TOOL_2PT_SELECT || which == TOOL_3PT_SELECT) {
    SDL_BlitSurface(n_pt_persp_snapshot, NULL, canvas, NULL);
  }
}

void n_pt_persp_draw_points(magic_api * api, int which, SDL_Surface * canvas) {
  int i, l, m, x1, y1, x2, y2, x;
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
          int xx, yy1, yy2;
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

    /* Horizon line (vanishing point) */
    slope = ((float) a2_pt_y[0] - (float) a2_pt_y[1]) / ((float) a2_pt_x[0] - (float) a2_pt_x[1]);
    x1 = 0;
    y1 = a2_pt_y[0] - (a2_pt_x[0] * slope);
    x2 = canvas->w;
    y2 = a2_pt_y[0] + ((canvas->w - a2_pt_x[0]) * slope);

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 12,
              n_pt_persp_line_xor_callback);

    x = (a2_pt_x[0] + a2_pt_x[1]) / 2;

    /* Perpendicular-to-horizon line */
    if (slope == 0.0 || slope == M_PI) {
      x1 = x;
      y1 = 0;
      x2 = x;
      y2 = canvas->h;
    } else {
      float perp_slope = -(slope);
      int y;

      x = (a2_pt_x[0] + a2_pt_x[1]) / 2;
      y = (a2_pt_y[0] + a2_pt_y[1]) / 2;

      x1 = x - (y * perp_slope);
      y1 = 0;
      x2 = x + ((canvas->h - y) * perp_slope);
      y2 = canvas->h;
    }

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 12,
              n_pt_persp_line_xor_callback);

    api->line((void *) api, which, canvas, NULL,
              a2_pt_x[0], a2_pt_y[0], x2, y2, 12,
              n_pt_persp_line_xor_callback);

    api->line((void *) api, which, canvas, NULL,
              a2_pt_x[1], a2_pt_y[1], x2, y2, 12,
              n_pt_persp_line_xor_callback);

    api->line((void *) api, which, canvas, NULL,
              x1, y1, a2_pt_x[0], a2_pt_y[0], 12,
              n_pt_persp_line_xor_callback);

    api->line((void *) api, which, canvas, NULL,
              x1, y1, a2_pt_x[1], a2_pt_y[1], 12,
              n_pt_persp_line_xor_callback);
  } else if (which == TOOL_3PT_SELECT) {
    /* 3-point perspective */

    for (i = 0; i < 3; i++) {
      n_pt_persp_draw_one_point(api, canvas, a3_pt_x[i], a3_pt_y[i], i);
    }

    /* Horizon line (vanishing point) */
    slope = ((float) a3_pt_y[0] - (float) a3_pt_y[1]) / ((float) a3_pt_x[0] - (float) a3_pt_x[1]);
    x1 = 0;
    y1 = a3_pt_y[0] - (a3_pt_x[0] * slope);
    x2 = canvas->w;
    y2 = a3_pt_y[0] + ((canvas->w - a3_pt_x[0]) * slope);

    api->line((void *) api, which, canvas, NULL,
              x1, y1, x2, y2, 12,
              n_pt_persp_line_xor_callback);

    for (i = 0; i < 6; i++) {
      x1 = a3_pt_x[0] + (((a3_pt_x[1] - a3_pt_x[0]) / 5) * i);
      y1 = a3_pt_y[0] + ((x1 - a3_pt_x[0]) * slope);
      x2 = a3_pt_x[2];
      y2 = a3_pt_y[2];

      api->line((void *) api, which, canvas, NULL,
                x1, y1, x2, y2, 12,
                n_pt_persp_line_xor_callback);
    }
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
