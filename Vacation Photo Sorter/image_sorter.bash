#!/bin/bash
find $1 -type f -print0 | xargs -0 ls -ltr | awk ' {print $9} ' > file.txt
convert -append $(cat file.txt) $(echo $1 | tr '/' '_').jpg
