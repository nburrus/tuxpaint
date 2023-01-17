/* rivulet.c

   Applys a lense effect like rivulets of water dripping
   down a pane of glass.  Applies an additive brush at
   the mouse pointer, and a subtractive brush slightly
   above (to simulate the water breaking up due to
   evaporation), only allowing the draw path to go downwards,
   and the left/right delta to change slightly (will not
   follow the mouse precisely).  Upon release, the lense
   effect will be applied.

   Last modified: 2023.01.16
*/

#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <math.h>

#include "tp_magic_api.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

Mix_Chunk *snd_effect = NULL;
SDL_Surface * rivulet_img_brush_add,
  * rivulet_img_brush_sub,
  * rivulet_img_angles;
int riv_x, riv_y;
Uint8 * riv_radii = NULL,
  * riv_angles = NULL;

Uint32 rivulet_api_version(void);
int rivulet_init(magic_api * api);
int rivulet_get_tool_count(magic_api * api);
SDL_Surface *rivulet_get_icon(magic_api * api, int which);
char *rivulet_get_name(magic_api * api, int which);
int rivulet_get_group(magic_api * api, int which);
char *rivulet_get_description(magic_api * api, int which, int mode);
int rivulet_requires_colors(magic_api * api, int which);
int rivulet_modes(magic_api * api, int which);
void rivulet_shutdown(magic_api * api);
void rivulet_click(magic_api * api, int which, int mode,
                     SDL_Surface * canvas, SDL_Surface * snapshot, int x,
                     int y, SDL_Rect * update_rect);
void rivulet_set_color(magic_api * api, Uint8 r, Uint8 g, Uint8 b);
void rivulet_drag(magic_api * api, int which, SDL_Surface * canvas,
                    SDL_Surface * snapshot, int ox, int oy, int x, int y,
                    SDL_Rect * update_rect);
void rivulet_line_callback_drag(void *ptr, int which, SDL_Surface * canvas,
                                  SDL_Surface * snapshot, int x, int y);
void rivulet_release(magic_api * api, int which, SDL_Surface * canvas,
                       SDL_Surface * snapshot, int x, int y,
                       SDL_Rect * update_rect);
void rivulet_switchin(magic_api * api, int which, int mode,
                        SDL_Surface * canvas);
void rivulet_switchout(magic_api * api, int which, int mode,
                         SDL_Surface * canvas);
void zero_riv_arrays(SDL_Surface * canvas);


Uint32 rivulet_api_version(void)
{
  return (TP_MAGIC_API_VERSION);
}

int rivulet_init(magic_api * api)
{
  char fname[1024];

  /* FIXME */
//  snprintf(fname, sizeof(fname), "%ssounds/magic/rivulet.ogg",
//           api->data_directory);
//  snd_effect = Mix_LoadWAV(fname);

  /* Load our images */
  snprintf(fname, sizeof(fname), "%simages/magic/rivulet-brush-add.png",
           api->data_directory);
  rivulet_img_brush_add = IMG_Load(fname);
  if (rivulet_img_brush_add == NULL)
  {
    fprintf(stderr, "Can't open %s\n", fname);
    return 0;
  }

  snprintf(fname, sizeof(fname), "%simages/magic/rivulet-brush-sub.png",
           api->data_directory);
  rivulet_img_brush_sub = IMG_Load(fname);
  if (rivulet_img_brush_sub == NULL)
  {
    fprintf(stderr, "Can't open %s\n", fname);
    return 0;
  }

  snprintf(fname, sizeof(fname), "%simages/magic/rivulet-brush-sub.png",
           api->data_directory);
  rivulet_img_angles = IMG_Load(fname);
  if (rivulet_img_angles == NULL)
  {
    fprintf(stderr, "Can't open %s\n", fname);
    return 0;
  }

  return (1);
}

int rivulet_get_tool_count(magic_api * api ATTRIBUTE_UNUSED)
{
  return (1);
}


SDL_Surface *rivulet_get_icon(magic_api * api, int which ATTRIBUTE_UNUSED)
{
  char fname[1024];

  snprintf(fname, sizeof(fname), "%simages/magic/rivulet.png",
           api->data_directory);

  return (IMG_Load(fname));
}

char *rivulet_get_name(magic_api * api ATTRIBUTE_UNUSED,
                         int which ATTRIBUTE_UNUSED)
{
  return strdup(gettext("Rivulet"));
}

int rivulet_get_group(magic_api * api ATTRIBUTE_UNUSED,
                        int which ATTRIBUTE_UNUSED)
{
  return MAGIC_TYPE_DISTORTS;
}

char *rivulet_get_description(magic_api * api ATTRIBUTE_UNUSED,
                                int which ATTRIBUTE_UNUSED,
                                int mode ATTRIBUTE_UNUSED)
{
  return(gettext("Click and drag to add water rivulets to your drawing"));
}

int rivulet_requires_colors(magic_api * api ATTRIBUTE_UNUSED,
                              int which ATTRIBUTE_UNUSED)
{
  return 0;
}

int rivulet_modes(magic_api * api ATTRIBUTE_UNUSED,
                    int which ATTRIBUTE_UNUSED)
{
  return MODE_PAINT;
}

void rivulet_shutdown(magic_api * api ATTRIBUTE_UNUSED)
{
  if (snd_effect != NULL)
    Mix_FreeChunk(snd_effect);

  if (rivulet_img_brush_add != NULL)
    SDL_FreeSurface(rivulet_img_brush_add);

  if (rivulet_img_brush_sub != NULL)
    SDL_FreeSurface(rivulet_img_brush_add);

  if (rivulet_img_angles != NULL)
    SDL_FreeSurface(rivulet_img_angles);

  if (riv_radii != NULL)
    free(riv_radii);

  if (riv_angles != NULL)
    free(riv_angles);
}


void
rivulet_click(magic_api * api, int which, int mode ATTRIBUTE_UNUSED,
                SDL_Surface * canvas, SDL_Surface * snapshot, int x, int y,
                SDL_Rect * update_rect)
{
  riv_x = x;
  riv_y = y;

  if (riv_radii == NULL)
    return;

  if (snd_effect != NULL)
    {
      api->stopsound();
      api->playsound(snd_effect, (x * 255) / canvas->w, 255);
    }

  rivulet_drag(api, which, canvas, snapshot, x, y, x, y, update_rect);
}


void
rivulet_drag(magic_api * api ATTRIBUTE_UNUSED, int which, SDL_Surface * canvas,
               SDL_Surface * snapshot, int ox ATTRIBUTE_UNUSED,
               int oy ATTRIBUTE_UNUSED, int x, int y, SDL_Rect * update_rect)
{
  int old_riv_x, old_riv_y;

  if (riv_radii == NULL)
    return;

  /* Don't go backwards */
  if (y < riv_y)
    return;

  /* Don't stray too far left/right */
  if (x < riv_x - 2)
    x = riv_x - 2;
  if (x > riv_x + 2)
    x = riv_x + 2;

  old_riv_x = riv_x;
  old_riv_y = riv_y;

  riv_x = x;
  riv_y = y;

  api->line((void *) api, which, canvas, snapshot, old_riv_x, old_riv_y, riv_x, riv_y, 1,
            rivulet_line_callback_drag);

  /* FIXME */
  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}


void
rivulet_release(magic_api * api, int which ATTRIBUTE_UNUSED,
                  SDL_Surface * canvas, SDL_Surface * snapshot,
                  int x, int y, /* ignored and reused in a for-loop */
                  SDL_Rect * update_rect)
{
  int src_x, src_y;
  Uint8 radius, angle;
  Uint32 pix;

  if (riv_radii == NULL)
    return;

  /* Undo all of the placeholder drawings */
  SDL_BlitSurface(snapshot, NULL, canvas, NULL);

  /* Apply the lense effect */
  for (y = 0; y < canvas->h; y++)
  {
    for (x = 0; x < canvas->w; x++)
    {
      radius = riv_radii[(y * canvas->w) + x];
      angle = riv_angles[(y * canvas->w) + x];

      /* FIXME */
      src_x = x - 10;
      src_y = y - 10;

      pix = api->getpixel(snapshot, src_x, src_y);
      api->putpixel(canvas, x, y, pix);
    }
  }

  update_rect->x = 0;
  update_rect->y = 0;
  update_rect->w = canvas->w;
  update_rect->h = canvas->h;
}


void rivulet_set_color(magic_api * api ATTRIBUTE_UNUSED,
                         Uint8 r ATTRIBUTE_UNUSED, Uint8 g ATTRIBUTE_UNUSED, Uint8 b ATTRIBUTE_UNUSED)
{
}


void rivulet_line_callback_drag(void *ptr ATTRIBUTE_UNUSED, int which ATTRIBUTE_UNUSED,
                                  SDL_Surface * canvas,
                                  SDL_Surface * snapshot ATTRIBUTE_UNUSED,
                                  int x, int y)
{
  SDL_Rect dest;

  dest.x = x - rivulet_img_brush_add->w / 2;
  dest.y = y - rivulet_img_brush_add->h / 2;
  dest.w = rivulet_img_brush_add->w;
  dest.h = rivulet_img_brush_add->h;

  SDL_BlitSurface(rivulet_img_brush_add, NULL, canvas, &dest);

}

void rivulet_switchin(magic_api * api ATTRIBUTE_UNUSED,
                        int which ATTRIBUTE_UNUSED, int mode ATTRIBUTE_UNUSED,
                        SDL_Surface * canvas)
{
  if (riv_radii == NULL)
    {
      riv_radii = (Uint8 *) malloc(sizeof(Uint8) * canvas->w * canvas->h);
      if (riv_radii == NULL)
        {
          fprintf(stderr, "rivulet: Cannot malloc() riv_radii!\n");
          return;
        }

      riv_angles = (Uint8 *) malloc(sizeof(Uint8) * canvas->w * canvas->h);
      if (riv_angles == NULL)
        {
          free(riv_radii);
          riv_radii = NULL;
          fprintf(stderr, "rivulet: Cannot malloc() riv_angles!\n");
          return;
        }
    }

  zero_riv_arrays(canvas);
}

void rivulet_switchout(magic_api * api ATTRIBUTE_UNUSED,
                         int which ATTRIBUTE_UNUSED,
                         int mode ATTRIBUTE_UNUSED,
                         SDL_Surface * canvas ATTRIBUTE_UNUSED)
{
}

void zero_riv_arrays(SDL_Surface * canvas)
{
  memset(riv_radii, 0, (canvas->w * canvas->h));
  memset(riv_angles, 0, (canvas->w * canvas->h));
}
