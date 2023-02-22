/* colorsep.c

   Color separation effect (a la red/cyan aka red/blue 3D glasses).
   Bill Kendrick

   Last updated: February 21, 2023
*/

#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <math.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

enum {
  COLORSEP_MODE_RED_CYAN,
  COLORSEP_MODE_GREEN_PURPLE,
  COLORSEP_MODE_BLUE_YELLOW
};

Mix_Chunk *snd_effect = NULL;
int colorsep_click_x, colorsep_click_y;
int colorsep_mode = COLORSEP_MODE_RED_CYAN;

Uint32 colorsep_api_version(void);
int colorsep_init(magic_api * api);
int colorsep_get_tool_count(magic_api * api);
SDL_Surface *colorsep_get_icon(magic_api * api, int which);
char *colorsep_get_name(magic_api * api, int which);
int colorsep_get_group(magic_api * api, int which);
char *colorsep_get_description(magic_api * api, int which, int mode);
int colorsep_requires_colors(magic_api * api, int which);
int colorsep_modes(magic_api * api, int which);
void colorsep_shutdown(magic_api * api);
void colorsep_click(magic_api * api, int which, int mode,
                     SDL_Surface * canvas, SDL_Surface * snapshot, int x,
                     int y, SDL_Rect * update_rect);
void colorsep_set_color(magic_api * api, int which, SDL_Surface * canvas,
                    SDL_Surface * last, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect);
void colorsep_drag(magic_api * api, int which, SDL_Surface * canvas,
                    SDL_Surface * snapshot, int ox, int oy, int x, int y,
                    SDL_Rect * update_rect);
void colorsep_release(magic_api * api, int which, SDL_Surface * canvas,
                       SDL_Surface * snapshot, int x, int y,
                       SDL_Rect * update_rect);
void colorsep_switchin(magic_api * api, int which, int mode,
                        SDL_Surface * canvas);
void colorsep_switchout(magic_api * api, int which, int mode,
                         SDL_Surface * canvas);


Uint32 colorsep_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int colorsep_init(magic_api * api)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%ssounds/magic/colorsep.ogg",
           api->data_directory);
  snd_effect = Mix_LoadWAV(fname);

  return (1);
}

int colorsep_get_tool_count(magic_api * api ATTRIBUTE_UNUSED)
{
  return (1);
}


SDL_Surface *colorsep_get_icon(magic_api * api, int which ATTRIBUTE_UNUSED)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%simages/magic/colorsep.png",
           api->data_directory);

  return (IMG_Load(fname));
}

char *colorsep_get_name(magic_api * api ATTRIBUTE_UNUSED,
                         int which ATTRIBUTE_UNUSED)
{
  return strdup(gettext("Color Sep."));
}

int colorsep_get_group(magic_api * api ATTRIBUTE_UNUSED,
                        int which ATTRIBUTE_UNUSED)
{
  return MAGIC_TYPE_COLOR_FILTERS;
}

char *colorsep_get_description(magic_api * api ATTRIBUTE_UNUSED,
                                int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED)
{
  return strdup(gettext("Click and drag to separate your picture's colors (based on your color choice: red from cyan, green from purple, or blue from yellow)."));
}

int colorsep_requires_colors(magic_api * api ATTRIBUTE_UNUSED,
                              int which ATTRIBUTE_UNUSED)
{
  return 1;
}

int colorsep_modes(magic_api * api ATTRIBUTE_UNUSED,
                    int which ATTRIBUTE_UNUSED)
{
  return MODE_PAINT;
}

void colorsep_shutdown(magic_api * api ATTRIBUTE_UNUSED)
{
  if (snd_effect != NULL)
    Mix_FreeChunk(snd_effect);
}

void
colorsep_click(magic_api * api, int which, int mode ATTRIBUTE_UNUSED,
                SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                SDL_Rect * update_rect)
{
  if (snd_effect != NULL)
    api->stopsound();

  /* (Start off as if they clicked off to the side a little, so that
   * quick click+release will split the image bit by bit */
  colorsep_click_x = x;
  colorsep_click_y = y;
  colorsep_drag(api, which, canvas, snapshot, x, y, x - 10, y, update_rect);
}


void
colorsep_drag(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, SDL_Surface * canvas,
              SDL_Surface * snapshot, int ox ATTRIBUTE_UNUSED, int oy ATTRIBUTE_UNUSED,
              int x, int y, SDL_Rect * update_rect)
{
  int xx, yy, offset_x, offset_y;
  Uint8 r1, g1, b1, r2, g2, b2;

  offset_x = colorsep_click_x - x;
  offset_y = colorsep_click_y - y;

  api->playsound(snd_effect, (((-offset_x * 255) / canvas->w) + 128), 255);

  for (yy = 0; yy < canvas->h; yy++) {
    for (xx = 0; xx < canvas->w; xx++) {
      SDL_GetRGB(api->getpixel(snapshot, xx + offset_x / 2, yy + offset_y / 2), snapshot->format, &r1, &g1, &b1);
      SDL_GetRGB(api->getpixel(snapshot, xx - offset_x / 2, yy - offset_y / 2), snapshot->format, &r2, &g2, &b2);

      if (colorsep_mode == COLORSEP_MODE_RED_CYAN) {
        api->putpixel(canvas, xx, yy, SDL_MapRGB(canvas->format, r1, g2, b2));
      } else if (colorsep_mode == COLORSEP_MODE_GREEN_PURPLE) {
        api->putpixel(canvas, xx, yy, SDL_MapRGB(canvas->format, r2, g1, b2));
      } else if (colorsep_mode == COLORSEP_MODE_BLUE_YELLOW) {
        api->putpixel(canvas, xx, yy, SDL_MapRGB(canvas->format, r2, g2, b1));
      }
    }
  }

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}


void colorsep_release(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                  SDL_Surface * canvas ATTRIBUTE_UNUSED,
                  SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                  int x ATTRIBUTE_UNUSED, int y ATTRIBUTE_UNUSED,
                  SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
}


void colorsep_set_color(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                      SDL_Surface * canvas ATTRIBUTE_UNUSED,
                      SDL_Surface * last ATTRIBUTE_UNUSED,
                      Uint8 r, Uint8 g, Uint8 b,
                      SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
  r >>= 4;
  g >>= 4;
  b >>= 4;

  /* If the color chosen is very strong in some colors, separate it */
  if ((r > g && r > b) || (b > r && g > r)) {
    colorsep_mode = COLORSEP_MODE_RED_CYAN;
  } else if ((g > r && g > b) || (r > g && b > g)) {
    colorsep_mode = COLORSEP_MODE_GREEN_PURPLE;
  } else if ((b > r && b > g) || (r > b && g > b)) {
    colorsep_mode = COLORSEP_MODE_BLUE_YELLOW;
  } else {
    /* No winner? Default to the most comment, red/cyan */
    colorsep_mode = COLORSEP_MODE_RED_CYAN;
  }
}


void colorsep_switchin(magic_api * api ATTRIBUTE_UNUSED,
                        int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED,
                        SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

void colorsep_switchout(magic_api * api ATTRIBUTE_UNUSED,
                         int which ATTRIBUTE_UNUSED,
                         int mode ATTRIBUTE_UNUSED,
                         SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}
