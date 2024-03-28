/* polyfill.c

   A Magic tool for Tux Paint that creates a filled polygon.
   by Bill Kendrick <bill@newbreedsoftware.com>

   Scanline polygon fill routine based on public-domain code
   by Darel Rex Finley, 2007 <https://alienryderflex.com/polygon_fill/>

   Last updated: March 28, 2024
*/


#include <stdio.h>
#include <string.h>
#include <libintl.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

enum {
  TOOL_POLYFILL,
  NUM_TOOLS
};

char * polyfill_names[NUM_TOOLS] = {
  gettext_noop("Filled Polygon"),
};

char * polyfill_descr[NUM_TOOLS] = {
  gettext_noop("Click multiple times in your picture to create a filled polygon. Click your starting position to complete the shape."),
};

char * polyfill_icon_filenames[NUM_TOOLS] = {
  "dither.png", // FIXME
};

char * polyfill_snd_filenames[NUM_TOOLS] = {
  "dither.ogg", // FIXME
};

#define SNAP_SIZE 16

#define MAX_PTS 17

SDL_Surface * polyfill_snapshot = NULL;
int polyfill_pt_x[MAX_PTS];
int polyfill_pt_y[MAX_PTS];
int polyfill_num_pts = 0;
int polyfill_editing = MAX_PTS;
int polyfill_dragged = 0;


Mix_Chunk *snd_effects[NUM_TOOLS];

Uint32 polyfill_color, polyfill_color_red, polyfill_color_green;


void polyfill_drag(magic_api * api, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int old_x, int old_y, int x, int y,
  SDL_Rect * update_rect);

void polyfill_line_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y);

void polyfill_draw_preview(magic_api * api, SDL_Surface * canvas, int show_handles);
void polyfill_draw_final(magic_api * api, SDL_Surface * canvas);


Uint32 polyfill_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int polyfill_init(magic_api * api, Uint8 disabled_features, Uint8 complexity_level)
{
  int i;
  char filename[1024];

  for (i = 0; i < NUM_TOOLS; i++) {
    snprintf(filename, sizeof(filename), "%ssounds/magic/%s", api->data_directory,
             polyfill_snd_filenames[i]);
    snd_effects[i] = Mix_LoadWAV(filename);
  }

  return (1);
}


int polyfill_get_tool_count(magic_api * api)
{
  return NUM_TOOLS;
}

SDL_Surface *polyfill_get_icon(magic_api * api, int which)
{
  char filename[1024];

  snprintf(filename, sizeof(filename), "%simages/magic/%s",
           api->data_directory, polyfill_icon_filenames[which]);

  return (IMG_Load(filename));
}


char *polyfill_get_name(magic_api * api, int which)
{
  return strdup(gettext(polyfill_names[which]));
}


int polyfill_get_group(magic_api * api, int which)
{
  return MAGIC_TYPE_ARTISTIC;
}


int polyfill_get_order(int which)
{
  return 610 + which; // FIXME
}


char *polyfill_get_description(magic_api * api, int which, int mode)
{
  return strdup(gettext(polyfill_descr[which]));
}


int polyfill_requires_colors(magic_api * api, int which)
{
  return 1;
}


int polyfill_modes(magic_api * api, int which)
{
  return MODE_PAINT;
}


Uint8 polyfill_accepted_sizes(magic_api * api, int which, int mode)
{
  return 1;
}


Uint8 polyfill_default_size(magic_api * api, int which, int mode)
{
  return 1;
}


void polyfill_shutdown(magic_api * api)
{
  int i;

  for (i = 0; i < NUM_TOOLS; i++)
  {
    if (snd_effects[i] != NULL)
    {
      Mix_FreeChunk(snd_effects[i]);
    }
  }

  if (polyfill_snapshot != NULL) {
    SDL_FreeSurface(polyfill_snapshot);
    polyfill_snapshot = NULL;
  }
}

void
polyfill_click(magic_api * api, int which, int mode,
              SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
              SDL_Rect * update_rect)
{
  int i;

  polyfill_dragged = 0;

  printf("Click.  num_pts = %d\n", polyfill_num_pts);

  /* See if we're clicking a pre-existing point, to edit it? */
  polyfill_editing = MAX_PTS;
  for (i = 0; i < polyfill_num_pts && polyfill_editing == MAX_PTS; i++) {
    if (abs(x - polyfill_pt_x[i]) <= SNAP_SIZE &&
        abs(y - polyfill_pt_y[i]) <= SNAP_SIZE) {
      polyfill_editing = i;
    }
  }

  if (polyfill_editing != MAX_PTS) {
    printf("Clicked %d to edit it\n", polyfill_editing);
    polyfill_draw_preview(api, canvas, 1);
    return;
  }

  /* Trying to add a new point? */
  if (polyfill_num_pts < MAX_PTS) {
    printf("Adding new point %d\n", polyfill_num_pts);

    polyfill_pt_x[polyfill_num_pts] = x;
    polyfill_pt_y[polyfill_num_pts] = y;
    polyfill_editing = polyfill_num_pts;
    polyfill_num_pts++;

    /* Add the new point */
    polyfill_drag(api, which, canvas, snapshot, x, y, x, y, update_rect);
  } else {
    /* Out of points! */
    printf("Out of space for new points!\n");
  }
}


void
polyfill_drag(magic_api * api, int which,
             SDL_Surface * canvas, SDL_Surface * snapshot,
             int old_x, int old_y, int x, int y,
             SDL_Rect * update_rect)
{
  polyfill_dragged = 1;

  if (polyfill_editing >= MAX_PTS)
    return;

  polyfill_pt_x[polyfill_editing] = x;
  polyfill_pt_y[polyfill_editing] = y;

  polyfill_draw_preview(api, canvas, 1);

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}

void polyfill_draw_preview(magic_api * api, SDL_Surface * canvas, int show_handles) {
  int i, xx, yy, max;
  SDL_Rect dest;

  if (polyfill_snapshot == NULL)
    return;

  SDL_BlitSurface(polyfill_snapshot, NULL, canvas, NULL);

  for (i = 0; i < polyfill_num_pts - 1; i++) {
    api->line((void *) api, 0 /* which */, canvas, NULL /* snapshot */,
              polyfill_pt_x[i], polyfill_pt_y[i],
              polyfill_pt_x[i + 1], polyfill_pt_y[i + 1],
              1,
              polyfill_line_callback);
  }

  if (show_handles) {
    for (i = 1; i < polyfill_num_pts - 1; i++) {
      for (yy = -4; yy <= 4; yy++) {
        for (xx = -4; xx <= 4; xx++) {
          api->xorpixel(canvas, polyfill_pt_x[i] + xx, polyfill_pt_y[i] + yy);
        }
      }
    }

    if (polyfill_num_pts > 0) {
      dest.x = polyfill_pt_x[0] - SNAP_SIZE;
      dest.y = polyfill_pt_y[0] - SNAP_SIZE;
      dest.w = SNAP_SIZE * 2;
      dest.h = SNAP_SIZE * 2;
      SDL_FillRect(canvas, &dest, polyfill_color_green);
    }

    if (polyfill_num_pts > 1) {
      dest.x = polyfill_pt_x[polyfill_num_pts - 1] - SNAP_SIZE;
      dest.y = polyfill_pt_y[polyfill_num_pts - 1] - SNAP_SIZE;
      dest.w = SNAP_SIZE * 2;
      dest.h = SNAP_SIZE * 2;
      SDL_FillRect(canvas, &dest, polyfill_color_red);
    }
  }

  //SDL_UpdateRect(canvas, 0, 0, canvas->w, canvas->h);
}

void
polyfill_release(magic_api * api, int which,
                SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                SDL_Rect * update_rect)
{
  int i;

  if (polyfill_snapshot == NULL)
    return;

  if (polyfill_editing >= MAX_PTS)
    return;

  printf("Release while editing %d\n", polyfill_editing);

  /* If they simply clicked the first point (without
     drawing to move it), and there are enough points, consider
     it a final placement of a new point! */
  if (polyfill_editing == 0 && polyfill_dragged == 0 && polyfill_num_pts > 2 && polyfill_num_pts < MAX_PTS) {
    printf("Clicked first point to end polygon!\n");
    polyfill_pt_x[polyfill_num_pts] = polyfill_pt_x[0];
    polyfill_pt_y[polyfill_num_pts] = polyfill_pt_y[0];
    polyfill_editing = polyfill_num_pts;
    polyfill_num_pts++;
  }

  /* Moved (or placed) the final spot at the beginning? */
  if (polyfill_num_pts > 2 &&
      (
       (polyfill_editing == polyfill_num_pts - 1 &&
        abs(x - polyfill_pt_x[0]) <= SNAP_SIZE &&
        abs(y - polyfill_pt_y[0]) <= SNAP_SIZE) ||
       (polyfill_editing == 0 &&
        abs(x - polyfill_pt_x[polyfill_num_pts - 1]) <= SNAP_SIZE &&
        abs(y - polyfill_pt_y[polyfill_num_pts - 1]) <= SNAP_SIZE)
      )
  ) {
    printf("Ending the polygon!\n");

    /* Snap the points */
    if (polyfill_editing == 0) {
      polyfill_pt_x[0] = polyfill_pt_x[polyfill_num_pts - 1];
      polyfill_pt_y[0] = polyfill_pt_y[polyfill_num_pts - 1];
    } else {
      polyfill_pt_x[polyfill_num_pts - 1] = polyfill_pt_x[0];
      polyfill_pt_y[polyfill_num_pts - 1] = polyfill_pt_y[0];
    }

    polyfill_draw_final(api, canvas);

    polyfill_num_pts = 0;
    polyfill_editing = MAX_PTS;

    /* Update snapshot ahead of next polygon */
    SDL_BlitSurface(canvas, NULL, polyfill_snapshot, NULL);
  } else {
    /* Did not move (or place) the final spot at the beginning */

    /* Did we stick to points together? We can merge them */
    if (polyfill_num_pts > 2) {
      int to_merge = MAX_PTS;

      for (i = polyfill_editing - 1; i < polyfill_editing + 1; i++) {
        if (i >= 0 && i < polyfill_num_pts - 1) {
          if (abs(polyfill_pt_x[i] - polyfill_pt_x[i + 1]) <= SNAP_SIZE &&
              abs(polyfill_pt_y[i] - polyfill_pt_y[i + 1]) <= SNAP_SIZE) {
            printf("%d & %d can be merged\n", i, i + 1);
            to_merge = i;
          }
        }
      }

      if (to_merge != MAX_PTS) {
        printf("Merging %d with %d\n", to_merge, to_merge + 1);
        for (i = to_merge; i < polyfill_num_pts - 1; i++) {
          polyfill_pt_x[i] = polyfill_pt_x[i + 1];
          polyfill_pt_y[i] = polyfill_pt_y[i + 1];
        }
        polyfill_num_pts--;
      }
    }

    polyfill_draw_preview(api, canvas, 1);
  }

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}

void polyfill_set_color(magic_api * api, int which, SDL_Surface * canvas, SDL_Surface * snapshot, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect)
{
  polyfill_color = SDL_MapRGB(canvas->format, r, g, b);
  polyfill_draw_preview(api, canvas, 1);
}

void polyfill_set_size(magic_api * api, int which, int mode, SDL_Surface * canvas, SDL_Surface * snapshot, Uint8 size, SDL_Rect * update_rect)
{
}


void polyfill_line_callback(void *pointer, int which, SDL_Surface * canvas,
  SDL_Surface * snapshot, int x, int y)
{
  SDL_Rect dest;

  magic_api *api = (magic_api *) pointer;

  dest.x = x - 1;
  dest.y = y - 1;
  dest.w = 3;
  dest.h = 3;

  SDL_FillRect(canvas, &dest, polyfill_color);
}


void polyfill_switchin(magic_api * api, int which, int mode,
                      SDL_Surface * canvas)
{
  polyfill_color_red = SDL_MapRGB(canvas->format, 255, 0, 0);
  polyfill_color_green = SDL_MapRGB(canvas->format, 0, 255, 0);

  if (polyfill_snapshot == NULL) {
    polyfill_snapshot = SDL_CreateRGBSurface(SDL_SWSURFACE, canvas->w, canvas->h,
      canvas->format->BitsPerPixel, canvas->format->Rmask,
      canvas->format->Gmask, canvas->format->Bmask, canvas->format->Amask);
  }

  if (polyfill_snapshot != NULL) {
    SDL_BlitSurface(canvas, NULL, polyfill_snapshot, NULL);
  }
}

void polyfill_switchout(magic_api * api, int which, int mode,
                       SDL_Surface * canvas)
{
  polyfill_num_pts = 0;
  polyfill_editing = MAX_PTS;
}

/* Based on public-domain code by Darel Rex Finley, 2007
   https://alienryderflex.com/polygon_fill/
*/
void polyfill_draw_final(magic_api * api, SDL_Surface * canvas) {
  int i, j, ymin, ymax, y, nodes, swap;
  int nodeX[256];
  SDL_Rect rect;

  SDL_BlitSurface(polyfill_snapshot, NULL, canvas, NULL);

  ymin = canvas->w;
  ymax = 0;
  for (i = 0; i < polyfill_num_pts; i++) {
    if (polyfill_pt_y[i] < ymin) {
      ymin = polyfill_pt_y[i];
    }
    if (polyfill_pt_y[i] > ymax) {
      ymax = polyfill_pt_y[i];
    }
  }
  printf("ymin %d -> ymax %d\n", ymin, ymax);

  for (y = ymin; y <= ymax; y++) {
    nodes = 0;
    j = polyfill_num_pts - 2;

    for (i = 0; i < polyfill_num_pts - 1; i++) {
      if ((polyfill_pt_y[i] < y && polyfill_pt_y[j] >= y) ||
          (polyfill_pt_y[j] < y && polyfill_pt_y[i] >= y)) {
        nodeX[nodes++] = (int)
          (
           (double) polyfill_pt_x[i] +
           (double) (y - polyfill_pt_y[i]) /
           (double) (polyfill_pt_y[j] - polyfill_pt_y[i]) *
           (double) (polyfill_pt_x[j] - polyfill_pt_x[i])
          );
      }

      j = i;
    }

    // Sort the nodes, via a simple “Bubble” sort.
    i = 0;
    while (i < nodes - 1) {
      if (nodeX[i] > nodeX[i+1]) {
        swap = nodeX[i];
        nodeX[i] = nodeX[i + 1];
        nodeX[i + 1] = swap;
        if (i)
          i--;
      } else {
        i++;
      }
    }

    // Fill the pixels between node pairs.
    for (i = 0; i < nodes; i += 2) {
      if (nodeX[i] >= canvas->w)
        break;

      if (nodeX[i + 1] > 0) {
        if (nodeX[i] < 0)
          nodeX[i] = 0;
        if (nodeX[i + 1] > canvas->w - 1)
          nodeX[i + 1] = canvas->w - 1;

        rect.x = nodeX[i];
        rect.y = y;
        rect.w = nodeX[i + 1] - nodeX[i] + 1;
        rect.h = 1;
        SDL_FillRect(canvas, &rect, polyfill_color);
      }
    }
  }
}
