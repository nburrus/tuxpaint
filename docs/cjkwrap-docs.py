#!/usr/bin/env python3

# FIXME: Under construction!
# Experimental script to try and wrap
# Japanese plaintext docs, since `links` does not
# currently do this properly.  -bjk 2023.07.15
 
import cjkwrap

with open('ja_JP.UTF-8/README.txt') as f:
  while True:
    line = f.readline()
    if not line:
      break

    oldlen = len(line)
    line = line.lstrip()
    newlen = len(line)
    indent = oldlen - newlen

    wrappedlines = cjkwrap.wrap(line, 78 - indent)
    for l in wrappedlines:
      print(" " * indent, end="")
      print(l)

f.close()

