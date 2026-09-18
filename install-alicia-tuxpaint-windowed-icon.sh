#!/bin/sh
set -eu

if [ "$(id -u)" -ne 0 ]; then
  echo "Run with sudo." >&2
  exit 1
fi

desktop=/home/alicia/Desktop
icon=/opt/tuxpaint-sdl3/share/icons/hicolor/128x128/apps/tuxpaint.png
target="$desktop/Tux Paint.desktop"
old="$desktop/Tux Paint Fullscreen.desktop"

test -x /opt/bin/tuxpaint
test -f "$icon"
install -d -o alicia -g alicia -m 755 "$desktop"
temp=$(mktemp "$desktop/.tuxpaint-launcher.XXXXXX")
trap 'rm -f "$temp"' EXIT HUP INT TERM
cat > "$temp" <<EOF
[Desktop Entry]
Type=Application
Name=Tux Paint
Comment=Draw with Tux Paint
Exec=/opt/bin/tuxpaint --fullscreen=no --windowsize=1280x800 --nofancycursors --dontgrab --simpleshapes
Icon=$icon
Terminal=false
Categories=Education;Art;Graphics;2DGraphics;Game;KidsGame;
EOF
chown alicia:alicia "$temp"
chmod 755 "$temp"
mv -f "$temp" "$target"
trap - EXIT HUP INT TERM
rm -f "$old"
runuser -u alicia -- gio set -t boolean "$target" metadata::trusted true 2>/dev/null || true
echo "Alicia's Tux Paint icon now opens the stable windowed mode: $target"
