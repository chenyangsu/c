#!/bin/bash
lowercase=$(head -n 1 $1)
uppercase=$(head -2 $1 | tail -1)
#echo $lowercase #To test what is stored in these variables
#echo $uppercase
cat $2 | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' $uppercase | tr 'abcdefghijklmnopqrstuvwxyz' $lowercase 