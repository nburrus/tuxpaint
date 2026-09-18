# Tux Paint SDL3 build for the Surface Pro 6

This repository's `main` branch starts from the official SourceForge Git history
(`upstream`), applies Pere Pujal i Carabantes's SDL3 snapshot (`90843bf70`),
and adds the Surface fixes. `origin` is `git@github.com:nburrus/tuxpaint.git`.
The port and fixes are in commits `b62cd30fc` and `615c71cde`; the SDL eraser
patch was recorded in `425ad968a`.

## What was changed in Tux Paint

- Ported the application and plugins from SDL2 to SDL3, including rendering,
  input events, audio, image/font handling, and build linkage.
- Converted SDL window coordinates to renderer coordinates, including the
  fullscreen letterbox area, so touch, mouse, and pen select the right point.
- Converted sub-byte indexed thumbnails and Emitter's paletted surface before
  scaling. AddressSanitizer found memory errors in the old paths.
- Made ImageMagick generate 8-bit starter/template thumbnails (`-depth 8` in
  `Makefile`). The installed SDL3_image build overflowed on 16-bit thumbnails;
  pressing New could crash. Existing installed thumbnails were converted too.
- The reversed pen end selects Tux Paint's eraser when SDL reports an eraser
  pen-down event.

The SDL3 port still uses the local SDL3_gfx, SDL3_Pango, and SDL3_mixer builds
alongside SDL3_image and SDL3_ttf. Those dependency binaries are staged in
`/home/nb/Perso/surface/package-opt/opt/tuxpaint-sdl3/lib`; they are not
committed to this source repository.

## SDL Wayland eraser patch

The installed private SDL is based on SDL 3.4.2. Its Wayland tablet handler
records tool subtype `SDL_PEN_TYPE_ERASER` but passes `false` to all three
`SDL_SendPenTouch` calls. Apply
`patches/SDL-3.4.2-wayland-eraser.patch` with `patch -p1` at the root of the
SDL 3.4.2 source tree, then build SDL with Wayland and shared libraries enabled.
The resulting `libSDL3.so.0` belongs in `/opt/tuxpaint-sdl3/lib`, where the
Tux Paint wrapper loads it via `LD_LIBRARY_PATH`. System SDL is untouched.
The patch also applies to the official SDL 3.4.16 release. A patched 3.4.16
trial did not solve Alicia's fullscreen pen loss, so 3.4.2 remains installed.
A probe verified eraser events from the reversed end and normal events from
the drawing tip with the patched library.

Example SDL rebuild from a matching release source tree:

```sh
cd /path/to/SDL3-3.4.2
patch -p1 < /home/nb/Perso/tuxpaint/patches/SDL-3.4.2-wayland-eraser.patch
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=ON -DSDL_WAYLAND=ON
cmake --build build -j
# Copy build/libSDL3.so.0.4.2 as /opt/tuxpaint-sdl3/lib/libSDL3.so.0
```

Check the actual library path in `build/` before copying; CMake output paths
vary by generator. Do not overwrite the system SDL library.

## Installation on this machine

The built application is in `/opt/tuxpaint-sdl3`. `/opt/bin/tuxpaint` and
`/opt/bin/tuxpaint-fullscreen` are symlinks to its wrappers. The first wrapper
sets the private library path. The fullscreen wrapper adds
`--fullscreen=yes --nofancycursors`. Source and staged binaries also remain
under `/home/nb/Perso/surface`; `install-tuxpaint-sdl3.sh` there copies the
staged tree into `/opt/tuxpaint-sdl3` and checks `--version`. The staged tree
is a local build artifact, not part of this Git repository. Rebuilding from a
fresh clone also requires the SDL3 dependencies listed above and the standard
Tux Paint build dependencies. Use `make PREFIX=/opt/tuxpaint-sdl3` and
`make install PREFIX=/opt/tuxpaint-sdl3` once those dependencies are available.

## Alicia's pen and desktop launcher

Alicia's GNOME Wayland session loses pen taps after the pen leaves proximity
in SDL fullscreen mode. Alt-Tab away and back restores them. A Wayland protocol
trace showed hover returning to Tux Paint, but no `zwp_tablet_tool_v2.down`
for taps until focus changed. The pen works in other applications and in Tux
Paint windowed mode. SDL 3.4.16, native fullscreen, matched 1368x912 canvas,
`--dontgrab`, a named window, and disabling mouse warps did not fix the loss.
The matched canvas fixed drawing alignment but not the pen issue. Fullscreen
remains available for investigation; windowed mode is the reliable choice for
Alicia.

Run `sudo sh /home/nb/Perso/tuxpaint/install-alicia-tuxpaint-windowed-icon.sh`
on the host to replace Alicia's fullscreen desktop icon with one windowed icon.
It launches 1280x800 with `--nofancycursors --dontgrab --simpleshapes`.
`--simpleshapes` removes the shape rotation step. This launcher script is
committed; installing it changes only Alicia's desktop entry.
