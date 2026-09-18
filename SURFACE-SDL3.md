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

## Surface pen eraser on Wayland

SDL 3.4.2 records Wayland tablet tool type `ERASER`, but its Wayland event
handler passes `false` as the eraser argument to every `SDL_SendPenTouch` call.
As a result, Tux Paint sees the reversed pen end as another drawing tip. Apply
`patches/SDL-3.4.2-wayland-eraser.patch` to SDL 3.4.2 source with `patch -p1`
and build SDL with Wayland enabled. Place its `libSDL3.so.0` in the private
Tux Paint library directory so the `/opt` launcher loads it. This avoids
changing the system SDL library used by other applications.

## Alicia's launcher

On Alicia's GNOME Wayland session, the pen stops sending tablet-down events to
Tux Paint after it leaves proximity in SDL fullscreen mode. Alt-Tab away and
back restores them. A Wayland protocol trace shows hover events continue but
the compositor sends no `zwp_tablet_tool_v2.down` until focus changes. The same
pen works in other applications and in Tux Paint windowed mode. Run
`sudo sh install-alicia-tuxpaint-windowed-icon.sh` to give Alicia one desktop
icon that opens the stable 1280x800 windowed mode with plain cursors and simple
shapes. The installer removes her old fullscreen desktop icon.
