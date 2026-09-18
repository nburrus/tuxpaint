# SDL3 Surface build

This branch carries Pere Pujal i Carabantes's SDL3 port snapshot
(`90843bf70`) on top of the official Tux Paint Git history, plus fixes tested
on a Surface Pro 6. The installed copy on that machine lives in
`/opt/tuxpaint-sdl3`, with launchers in `/opt/bin`.

The fullscreen launcher uses `--fullscreen=yes --nofancycursors`. On the
Surface's Wayland session, changing Tux Paint's custom cursors caused pen
events to stop arriving. The plain cursor setting kept pen input responsive.

The Makefile generates 8-bit PNG starter and template thumbnails. This
SDL3_image build writes past its destination buffer when opening the 16-bit
thumbnails produced by ImageMagick's `+depth` option; pressing New then
crashed. AddressSanitizer found the overrun, and loading all generated 8-bit
thumbnails under AddressSanitizer completed without errors.

The build also converts sub-byte indexed surfaces before thumbnailing and
converts the Emitter plugin's paletted surface to RGBA before scaling. Both
changes fix startup memory errors found with AddressSanitizer.
