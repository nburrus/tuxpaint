#!/bin/bash

echo -n "Checking host environment ... "
sysname=`uname -s`
if echo $sysname | grep MINGW64; then
  arch=x86_64
elif echo $sysname | grep MINGW32; then
  arch=i686
else
  exit
fi

echo "Building installer ... "
result=`/C/Program\ Files\ \(x86\)/Inno\ Setup\ 5/ISCC tuxpaint.iss | grep installer.exe`
if [ "x$result" != "x" ]; then
  installer=`basename $result`
fi
rename windows-installer windows-$arch-installer $installer

echo "Building portable zip archive ... "
zip=`echo $installer | sed 's/installer.exe//'`$arch.zip
if [ -d TuxPaint ]; then
  rm -rf TuxPaint
fi
mv bdist TuxPaint
zip -qr -9 $zip TuxPaint
cd ..
