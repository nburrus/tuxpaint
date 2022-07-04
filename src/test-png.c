/*
  test-png.c

  A tiny test program that opens a PNG file using libpng
  library.  If any warnings come back, this can help us tell
  when any images include oddities that would cause Tux Paint
  to echo warnings (via SDL_image->libpng) to stderr when it
  goes to load them.

  See https://sourceforge.net/p/tuxpaint/bugs/252/

  Bill Kendrick <bill@newbreedsoftware.com>

  (Based loosely on example code by Yoshimasa Niwa, https://gist.github.com/niw,
  located at https://gist.github.com/niw/5963798, which itself was based on
  code by Guillaume Cottenceau found at http://zarb.org/~gc/html/libpng.html)

  2022-07-03 - 2022-07-03
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <png.h>

int main(int argc, char * argv[]) {
  int i;
  FILE * fi;
  png_structp png;
  png_infop info;

  /* Usage output */
  if (argc == 1 || strcmp(argv[1], "--help") == 0) {
    fprintf(stderr, "Usage: %s file.png [file.png ...]\n", argv[0]);
    exit(1);
  }


  /* Redirect stderr to stdout, so libpng's warnings can
     be in the same stream as our's (where we report each
     file's filename); allows more easily dumping to a file,
     piping through `| less`, etc. */
  dup2(STDOUT_FILENO, STDERR_FILENO);


  /* Open each PNG image!... */
  for (i = 1; i < argc; i++) {
    printf("%5d ------------------------------------------------------------------\n", i);
    printf("%s\n", argv[i]);

    /* Open the file */
    fi = fopen(argv[i], "rb");
    if (fi == NULL) {
      printf("Cannot open\n");
    } else {
      /* Prepare PNG library stuff... */
      png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
      if (!png) {
        fprintf(stderr, "Cannot png_create_read_struct()!\n");
        exit(1);
      }

      info = png_create_info_struct(png);
      if (!info) {
        fprintf(stderr, "Cannot png_create_info_struct()!\n");
        exit(1);
      }

      if (setjmp(png_jmpbuf(png))) {
        fprintf(stderr, "Cannot setjmp(png_jmpbuf(png)))!\n");
        exit(1);
      }

      /* Read the PNG's info */
      png_init_io(png, fi);
      png_read_info(png, info);

      /* *** At this point, libpng would have reported issues *** */

      /* (We could do additional things, like reporting image
         dimensions, color depth, etc., but I don't see any reason to
         care right now.  -bjk 2022.07.03) */

      /* Close and move on to the next file */
      png_destroy_read_struct(&png, &info, NULL);
      fclose(fi);
    }

    printf("\n");
    fflush(stdout);
  }

  return(0);
}
