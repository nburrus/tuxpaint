/* lightning.c

   Draws a lightning strike between the click
   and drag+release positions.

   Last modified: 2021.09.26
*/

#include <stdio.h>
#include <string.h>
#include <libintl.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

Mix_Chunk *snd_effect;
Uint8 lightning_r, lightning_g, lightning_b;
int sx, sy;


void lightning_drag(magic_api * api, int which, SDL_Surface * canvas,
                    SDL_Surface * snapshot, int ox, int oy, int x, int y, SDL_Rect * update_rect);
void lightning_line_callback_drag(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y);
void lightning_line_callback_release(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y);


Uint32 lightning_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int lightning_init(magic_api * api)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%s/sounds/magic/lightning.ogg", api->data_directory);
  snd_effect = Mix_LoadWAV(fname);

  return (1);
}

int lightning_get_tool_count(magic_api * api)
{
  return (1);
}


SDL_Surface *lightning_get_icon(magic_api * api, int which)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%s/images/magic/lightning.png", api->data_directory);

  return (IMG_Load(fname));
}

char *lightning_get_name(magic_api * api, int which)
{
  return strdup(gettext("Lightning"));
}

int lightning_get_group(magic_api * api, int which)
{
  return MAGIC_TYPE_ARTISTIC;
}

char *lightning_get_description(magic_api * api, int which, int mode)
{
  return strdup(gettext("Click, drag, and release to a lightning bolt between two points."));
}

int lightning_requires_colors(magic_api * api, int which)
{
  return 1;
}

int lightning_modes(magic_api * api, int which)
{
  return MODE_PAINT;
}

void lightning_shutdown(magic_api * api)
{
  if (snd_effect != NULL)
    Mix_FreeChunk(snd_effect);
}


void
lightning_click(magic_api * api, int which, int mode,
              SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y, SDL_Rect * update_rect)
{
  sx = x;
  sy = y;
  lightning_drag(api, which, canvas, snapshot, x, y, x, y, update_rect);
}


void
lightning_drag(magic_api * api, int which, SDL_Surface * canvas,
             SDL_Surface * snapshot, int ox, int oy, int x, int y, SDL_Rect * update_rect)
{
  /* FIXME: This could be made more efficient
     (only blit and update between (sx,sy) and (x,y), though
     it should also cover the area extending to (ox,oy),
     to avoid leaving trails */
  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  SDL_BlitSurface(snapshot, update_rect, canvas, update_rect);

  api->line((void *)api, which, canvas, snapshot, sx, sy, x, y, 1, lightning_line_callback_drag);
}


void
lightning_release(magic_api * api, int which,
                SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y, SDL_Rect * update_rect)
{
  /* FIXME: This could be made more efficient
     (only blit and update between (sx,sy) and (x,y), though
     it should also cover the area extending to (ox,oy),
     to avoid leaving trails */
  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;

  SDL_BlitSurface(snapshot, update_rect, canvas, update_rect);

  api->line((void *)api, which, canvas, snapshot, sx, sy, x, y, 1, lightning_line_callback_release);
  api->stopsound();
  api->playsound(snd_effect, (x * 255) / canvas->w, 255);
}

void lightning_set_color(magic_api * api, Uint8 r, Uint8 g, Uint8 b)
{
  lightning_r = r;
  lightning_g = g;
  lightning_b = b;
}


void lightning_line_callback_drag(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y)
{
  magic_api *api = (magic_api *) ptr;

  api->xorpixel(canvas, x, y);
}

void lightning_line_callback_release(void *ptr, int which, SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y)
{
  magic_api *api = (magic_api *) ptr;

  // FIXME
  api->putpixel(canvas, x, y, SDL_MapRGB(canvas->format, lightning_r, lightning_g, lightning_b));
}

void lightning_switchin(magic_api * api, int which, int mode, SDL_Surface * canvas)
{
}

void lightning_switchout(magic_api * api, int which, int mode, SDL_Surface * canvas)
{
}
