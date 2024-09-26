/*
  ascii.c

  Converts the image to ASCII art.

  Tux Paint - A simple drawing program for children.

  Copyright (c) 2024 by Bill Kendrick

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  (See COPYING.txt)

  Last updated: September 25, 2024
*/

#include <stdio.h>
#include <string.h>
#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

enum {
  TOOL_TYPEWRITER,
  TOOL_COMPUTER,
  NUM_TOOLS
};

char * ascii_tool_names[NUM_TOOLS] = {
  "Typewriter",
  "Computer",
};

char * ascii_tool_filenames[NUM_TOOLS] = {
  "typewriter",
  "computer",
};

static Mix_Chunk *ascii_snd[NUM_TOOLS];

/* For each variation, we'll have a bitmap with an arbitrary number
 * of potentially-proportionally-spaced characters (which we'll treat
 * as fixed-width), so we need to keep track of each character's X
 * poistion, how many characters there are, and the maximum width.
 */
SDL_Surface * ascii_bitmap[NUM_TOOLS];
int ascii_char_x[NUM_TOOLS][256];
int ascii_num_chars[NUM_TOOLS];
int ascii_char_maxwidth[NUM_TOOLS];

Uint32 ascii_api_version(void);
int ascii_init(magic_api * api, Uint8 disabled_features, Uint8 complexity_level);
int ascii_get_tool_count(magic_api * api);
SDL_Surface *ascii_get_icon(magic_api * api, int which);
char *ascii_get_name(magic_api * api, int which);
int ascii_get_group(magic_api * api, int which);
int ascii_get_order(int which);
char *ascii_get_description(magic_api * api, int which, int mode);

void ascii_drag(magic_api * api, int which, SDL_Surface * canvas,
              SDL_Surface * last, int ox, int oy, int x, int y, SDL_Rect * update_rect);

void ascii_click(magic_api * api, int which, int mode,
               SDL_Surface * canvas, SDL_Surface * last, int x, int y, SDL_Rect * update_rect);

void ascii_release(magic_api * api, int which,
                 SDL_Surface * canvas, SDL_Surface * last, int x, int y, SDL_Rect * update_rect);

void ascii_shutdown(magic_api * api);
void ascii_set_color(magic_api * api, int which, SDL_Surface * canvas,
                   SDL_Surface * last, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect);
int ascii_requires_colors(magic_api * api, int which);
void ascii_switchin(magic_api * api, int which, int mode, SDL_Surface * canvas);
void ascii_switchout(magic_api * api, int which, int mode, SDL_Surface * canvas);
int ascii_modes(magic_api * api, int which);
Uint8 ascii_accepted_sizes(magic_api * api, int which, int mode);
Uint8 ascii_default_size(magic_api * api, int which, int mode);
void ascii_set_size(magic_api * api, int which, int mode, SDL_Surface * canvas, SDL_Surface * last, Uint8 size,
                  SDL_Rect * update_rect);
void do_ascii_effect(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * last, int x, int y);


Uint32 ascii_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int ascii_init(magic_api * api, Uint8 disabled_features ATTRIBUTE_UNUSED, Uint8 complexity_level ATTRIBUTE_UNUSED)
{
  char fname[1024];
  int i, j, x, y, xx, w, num_chars, all_clear;
  Uint32 clear_pixel, pixel;
  Uint8 r, g, b;

  for (i = 0; i < NUM_TOOLS; i++)
  {
    ascii_snd[i] = NULL;
    ascii_bitmap[i] = NULL;
  }

  for (i = 0; i < NUM_TOOLS; i++)
  {
    /* FIXME */
    snprintf(fname, sizeof(fname), "%ssounds/magic/ascii-%s.ogg", api->data_directory, ascii_tool_filenames[i]);
    snprintf(fname, sizeof(fname), "%ssounds/magic/xor.ogg", api->data_directory);

    ascii_snd[i] = Mix_LoadWAV(fname);

    snprintf(fname, sizeof(fname), "%simages/magic/ascii-%s.png", api->data_directory, ascii_tool_filenames[i]);
    ascii_bitmap[i] = IMG_Load(fname);

    if (ascii_bitmap[i] == NULL)
    {
      fprintf(stderr, "Cannot load %s\n", fname);
      return(0);
    }

    clear_pixel = api->getpixel(ascii_bitmap[i], 0, 0);
    printf("%s; clear pixel %d\n", fname, clear_pixel);
    num_chars = 0;
    for (x = 0; x < ascii_bitmap[i]->w; x++)
    {
      ascii_char_x[i][num_chars] = x;

      do
      {
        all_clear = 1;
        for (y = 0; y < ascii_bitmap[i]->h /* && all_clear */; y++) {
          pixel = api->getpixel(ascii_bitmap[i], x, y);
          if (pixel != clear_pixel)
            all_clear = 0;
        }
        if (all_clear)
          x++;
      }
      while (all_clear && x < ascii_bitmap[i]->w);

      all_clear = 0;
      for (xx = x; xx < ascii_bitmap[i]->w && !all_clear; xx++)
      {
        all_clear = 1;
        for (y = 0; y < ascii_bitmap[i]->h /* && all_clear */; y++)
        {
          pixel = api->getpixel(ascii_bitmap[i], xx, y);
          if (pixel != clear_pixel)
          {
            all_clear = 0;
            SDL_GetRGB(pixel, ascii_bitmap[i]->format, &r, &g, &b);
            if (r == 255 && g == 0 && b == 255)
            {
              /* Magenta counts as a connecting pixel, but we
               * want it to appear as the clear color */
              api->putpixel(ascii_bitmap[i], xx, y, clear_pixel);
              printf("x");
            }
            else
            {
              printf("#");
            }
          }
          else
          {
            printf("-");
          }
        }
        printf("\n");
      }
      x = xx;
      num_chars++;
      printf(".......................................\n");
    }
    ascii_num_chars[i] = num_chars;
    printf("%s has %d characters\n", fname, num_chars);

    ascii_char_x[i][num_chars] = x;
    ascii_char_maxwidth[i] = 0;
    for (j = 0; j < num_chars; j++)
    {
      w = ascii_char_x[i][j + 1] - ascii_char_x[i][j];
      printf("%d->%d = %d\n", j, j + 1, w);
      if (w > ascii_char_maxwidth[i])
      {
        ascii_char_maxwidth[i] = w;
      }
    }

    printf("%s max char width is %d\n", fname, ascii_char_maxwidth[i]);
  }

  return (1);
}

int ascii_get_tool_count(magic_api * api ATTRIBUTE_UNUSED)
{
  return (1);
}

SDL_Surface *ascii_get_icon(magic_api * api, int which)
{
  char fname[1024];

  /* FIXME */
  snprintf(fname, sizeof(fname), "%ssounds/magic/ascii-icon-%s.ogg", api->data_directory, ascii_tool_filenames[which]);
  snprintf(fname, sizeof(fname), "%simages/magic/xor.png", api->data_directory);

  return (IMG_Load(fname));
}

char *ascii_get_name(magic_api * api ATTRIBUTE_UNUSED, int which)
{
  char tmp[1024];

  snprintf(tmp, sizeof(tmp), gettext("ASCII %s"), ascii_tool_names[which]);
  return(strdup(tmp));
}

int ascii_get_group(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return MAGIC_TYPE_DISTORTS;
}

int ascii_get_order(int which)
{
  return 800 + which; // FIXME
}

char *ascii_get_description(magic_api * api ATTRIBUTE_UNUSED, int which, int mode)
{
  char tmp[1024];

  if (mode == MODE_PAINT)
    snprintf(tmp, sizeof(tmp), gettext("Click and drag to transform parts of your drawing to ASCII art (%s style)."), ascii_tool_names[which]);
  else
    snprintf(tmp, sizeof(tmp), gettext("Click to transform your entire drawing to ASCII art (%s style)."), ascii_tool_names[which]);

  return(strdup(tmp));
}

void ascii_drag(magic_api * api, int which, SDL_Surface * canvas,
              SDL_Surface * last, int ox, int oy, int x, int y, SDL_Rect * update_rect)
{
  api->line((void *)api, which, canvas, last, ox, oy, x, y, 1, do_ascii_effect);

  /* FIXME */
  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  api->playsound(ascii_snd[which], (x * 255) / canvas->w, 255);
}

void ascii_click(magic_api * api, int which, int mode,
               SDL_Surface * canvas, SDL_Surface * last, int x, int y, SDL_Rect * update_rect)
{
  if (mode == MODE_PAINT)
    ascii_drag(api, which, canvas, last, x, y, x, y, update_rect);
  else
  {
    int xx, yy;

    for (yy = 0; yy < canvas->h; yy++)
      for (xx = 0; xx < canvas->w; xx++)
        do_ascii_effect(api, which, canvas, last, xx, yy);

    update_rect->x = 0;
    update_rect->y = 0;
    update_rect->w = canvas->w;
    update_rect->h = canvas->h;
    api->playsound(ascii_snd[which], (x * 255) / canvas->w, 255);
  }
}

void ascii_release(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                 SDL_Surface * canvas ATTRIBUTE_UNUSED,
                 SDL_Surface * last ATTRIBUTE_UNUSED, int x ATTRIBUTE_UNUSED,
                 int y ATTRIBUTE_UNUSED, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
}

void ascii_shutdown(magic_api * api ATTRIBUTE_UNUSED)
{
  int i;

  for (i = 0; i < NUM_TOOLS; i++)
  {
    if (ascii_snd[i] != NULL)
      Mix_FreeChunk(ascii_snd[i]);
    if (ascii_bitmap[i] != NULL)
      SDL_FreeSurface(ascii_bitmap[i]);
  }
}

void ascii_set_color(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED,
                   SDL_Surface * last ATTRIBUTE_UNUSED, Uint8 r ATTRIBUTE_UNUSED, Uint8 g ATTRIBUTE_UNUSED,
                   Uint8 b ATTRIBUTE_UNUSED, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
}

int ascii_requires_colors(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return 0;
}

void ascii_switchin(magic_api * api ATTRIBUTE_UNUSED,
                  int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

void ascii_switchout(magic_api * api ATTRIBUTE_UNUSED,
                   int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

int ascii_modes(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return (MODE_PAINT | MODE_FULLSCREEN);
}


Uint8 ascii_accepted_sizes(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED)
{
  return 0;
}

Uint8 ascii_default_size(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED)
{
  return 0;
}

void ascii_set_size(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED,
                  SDL_Surface * canvas ATTRIBUTE_UNUSED, SDL_Surface * last ATTRIBUTE_UNUSED,
                  Uint8 size ATTRIBUTE_UNUSED, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
}

void do_ascii_effect(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * last, int x, int y)
{
  magic_api *api = (magic_api *) ptr;
}
