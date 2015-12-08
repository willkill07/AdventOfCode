#!/usr/bin/env bash

(awk 'BEGIN{ p = 1 }/Day/{ p = 0 }{ if (p == 1) { print } }' README.md
 header="Day | Lines | Source Lines | Total Bytes | Non WS Bytes | Source"
 echo $header
 echo $header | sed 's/[^|]/-/g'
 for i in src/*.cpp
 do
     (echo $i | sed -r 's/[^0-9]+//g'
      echo "|"
      grep -c '^' $i
      echo "|"
      grep -c '.' $i
      echo "|"
      wc -m < $i
      echo "|"
      paste -sd' ' < $i | sed -r 's/\s+//g' | wc -m
      echo "|"
      echo $i | sed -r 's|(.*)/(.*)|[\2](https://github.com/willkill07/adventofcode/blob/master/\1/\2)|'
     ) | paste -sd' '
 done | awk 'BEGIN{ l = 0; s = 0; b = 0; w = 0; }{ l += $3; s += $5; b += $7; w += $9; print }END{ print "**TOTAL** | **" l "** | **" s "** | **" b "** | **" w "** |" }') > README2.md && mv README{2,}.md
