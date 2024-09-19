/*
  fractal.c

  Freehand paint tree-like, fractal-like patterns.

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

  Last updated: September 19, 2024
*/

#include <stdio.h>
#include <string.h>
#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

typedef struct pt_s {
  int x, y;
} pt_t;

#define MAX_PTS 1000
pt_t pts[MAX_PTS];
int num_pts = 0;

static Mix_Chunk *fractal_snd;
static int fractal_radius = 16;
int fractal_radius_cur;
Uint32 fractal_color;

Uint32 fractal_api_version(void);
int fractal_init(magic_api * api, Uint8 disabled_features, Uint8 complexity_level);
int fractal_get_tool_count(magic_api * api);
SDL_Surface *fractal_get_icon(magic_api * api, int which);
char *fractal_get_name(magic_api * api, int which);
int fractal_get_group(magic_api * api, int which);
int fractal_get_order(int which);
char *fractal_get_description(magic_api * api, int which, int mode);

void fractal_drag(magic_api * api, int which, SDL_Surface * canvas,
              SDL_Surface * last, int ox, int oy, int x, int y, SDL_Rect * update_rect);

void fractal_click(magic_api * api, int which, int mode,
               SDL_Surface * canvas, SDL_Surface * last, int x, int y, SDL_Rect * update_rect);

void fractal_release(magic_api * api, int which,
                 SDL_Surface * canvas, SDL_Surface * last, int x, int y, SDL_Rect * update_rect);

void fractal_shutdown(magic_api * api);
void fractal_set_color(magic_api * api, int which, SDL_Surface * canvas,
                   SDL_Surface * last, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect);
int fractal_requires_colors(magic_api * api, int which);
void fractal_switchin(magic_api * api, int which, int mode, SDL_Surface * canvas);
void fractal_switchout(magic_api * api, int which, int mode, SDL_Surface * canvas);
int fractal_modes(magic_api * api, int which);
Uint8 fractal_accepted_sizes(magic_api * api, int which, int mode);
Uint8 fractal_default_size(magic_api * api, int which, int mode);
void fractal_set_size(magic_api * api, int which, int mode, SDL_Surface * canvas, SDL_Surface * last, Uint8 size,
                  SDL_Rect * update_rect);
void do_fractal(magic_api * api, int which, SDL_Surface * canvas, int iter, int cx, int cy, float angle, float scale);

Uint32 fractal_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int fractal_init(magic_api * api, Uint8 disabled_features ATTRIBUTE_UNUSED, Uint8 complexity_level ATTRIBUTE_UNUSED)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%ssounds/magic/xor.ogg", api->data_directory); // FIXME
  fractal_snd = Mix_LoadWAV(fname);

  return (1);
}

int fractal_get_tool_count(magic_api * api ATTRIBUTE_UNUSED)
{
  return (1);
}

SDL_Surface *fractal_get_icon(magic_api * api, int which)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%simages/magic/xor.png", api->data_directory); // FIXME

  return (IMG_Load(fname));
}

char *fractal_get_name(magic_api * api ATTRIBUTE_UNUSED, int which)
{
  return (strdup(gettext_noop("Fractals")));
}

int fractal_get_group(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return MAGIC_TYPE_PAINTING;
}

int fractal_get_order(int which)
{
  return 801;
}

char *fractal_get_description(magic_api * api ATTRIBUTE_UNUSED, int which, int mode ATTRIBUTE_UNUSED)
{
  return (strdup(gettext_noop("Click and drag to draw an \"Exclusive Or\" (XOR) effect"))); // FIXME
}

static void do_fractal_circle(void *ptr, int which ATTRIBUTE_UNUSED,
                          SDL_Surface * canvas, SDL_Surface * last ATTRIBUTE_UNUSED, int x, int y)
{
  magic_api *api = (magic_api *) ptr;
  int xx, yy;
  for (yy = -fractal_radius_cur; yy < fractal_radius_cur; yy++)
  {
    for (xx = -fractal_radius_cur; xx < fractal_radius_cur; xx++)
    {
      if (api->in_circle(xx, yy, fractal_radius_cur))
      {
        if (!api->touched(xx + x, yy + y))
          api->putpixel(canvas, xx + x, yy + y, fractal_color);
      }
    }
  }
}

void do_fractal(magic_api * api, int which, SDL_Surface * canvas, int iter, int cx, int cy, float angle, float scale)
{
  int i, x1, y1, x2, y2;

  for (i = 0; i < num_pts - 1; i++) {
    x1 = pts[i].x - cx;
    y1 = pts[i].y - cy;
    x2 = pts[i + 1].x - cx;
    y2 = pts[i + 1].y - cy;

    x1 = x1 * scale;
    y1 = y1 * scale;
    x2 = x2 * scale;
    y2 = y2 * scale;

    x1 = (cos(angle * M_PI / 180.0) * x1) - (sin(angle * M_PI / 180.0) * y1);
    y1 = (cos(angle * M_PI / 180.0) * y1) + (sin(angle * M_PI / 180.0) * x1);
    x2 = (cos(angle * M_PI / 180.0) * x2) - (sin(angle * M_PI / 180.0) * y2);
    y2 = (cos(angle * M_PI / 180.0) * y2) + (sin(angle * M_PI / 180.0) * x2);

    x1 += cx;
    y1 += cy;
    x2 += cx;
    y2 += cy;

    fractal_radius_cur = iter;
    api->line((void *)api, which, canvas, NULL, x1, y1, x2, y2, 1, do_fractal_circle);
  }

  if (iter > 1) {
    angle += 15.0;
    do_fractal(api, which, canvas, iter - 1, x1, y1, angle, scale * 1.1);
  }
}

void fractal_drag(magic_api * api, int which, SDL_Surface * canvas,
              SDL_Surface * last, int ox, int oy, int x, int y, SDL_Rect * update_rect)
{
  if (num_pts < MAX_PTS) {
    pts[num_pts].x = x;
    pts[num_pts].y = y;
    num_pts++;
  }

//  SDL_BlitSurface(last, NULL, canvas, NULL);

  do_fractal(api, which, canvas, fractal_radius, x, y, 0.0, 1.0);

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  api->playsound(fractal_snd, (x * 255) / canvas->w, 255);
}

void fractal_click(magic_api * api, int which, int mode,
               SDL_Surface * canvas, SDL_Surface * last ATTRIBUTE_UNUSED, int x, int y, SDL_Rect * update_rect)
{
  num_pts = 0;
  fractal_drag(api, which, canvas, last, x, y, x, y, update_rect);
}

void fractal_release(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                 SDL_Surface * canvas ATTRIBUTE_UNUSED,
                 SDL_Surface * last ATTRIBUTE_UNUSED, int x ATTRIBUTE_UNUSED,
                 int y ATTRIBUTE_UNUSED, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
}

void fractal_shutdown(magic_api * api ATTRIBUTE_UNUSED)
{
  if (fractal_snd != NULL)
    Mix_FreeChunk(fractal_snd);
}

void fractal_set_color(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED,
                   SDL_Surface * last ATTRIBUTE_UNUSED, Uint8 r, Uint8 g, Uint8 b, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
  fractal_color = SDL_MapRGB(canvas->format, r, g, b);
}

int fractal_requires_colors(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return 1;
}

void fractal_switchin(magic_api * api ATTRIBUTE_UNUSED,
                  int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

void fractal_switchout(magic_api * api ATTRIBUTE_UNUSED,
                   int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED, SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

int fractal_modes(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED)
{
  return (MODE_PAINT);
}


Uint8 fractal_accepted_sizes(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode)
{
  if (mode == MODE_PAINT)
    return 8;
  else
    return 0;
}

Uint8 fractal_default_size(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED)
{
  return 4;
}

void fractal_set_size(magic_api * api ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED,
                  SDL_Surface * canvas ATTRIBUTE_UNUSED, SDL_Surface * last ATTRIBUTE_UNUSED,
                  Uint8 size ATTRIBUTE_UNUSED, SDL_Rect * update_rect ATTRIBUTE_UNUSED)
{
  fractal_radius = size + 1;
}
