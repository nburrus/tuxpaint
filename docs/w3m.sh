#!/bin/bash

infile=${@: -1}
args=${@:1:${#}-1}

# FIXME: https://en.wikipedia.org/wiki/Line_breaking_rules_in_East_Asian_languages
# | sed -e "s/\(.[、。）]\)/<nobr>\\1<\\/nobr>/g" \
# This needs expanding & to not mess with <img> `alt` tag attributes or anything inside HTML tags (e.g., " quotes)!
# -bjk 2023.07.17

sed -e "s/<\\/dd>/<br\\/><br\\/><\\/dd>/g" $infile \
  | w3m $args

