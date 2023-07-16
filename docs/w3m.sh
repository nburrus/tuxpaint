#!/bin/bash

infile=${@: -1}
args=${@:1:${#}-1}

sed -e "s/<\\/dd>/<br\\/><br\\/><\\/dd>/g" $infile | w3m $args

