#!/bin/bash

while true
do
  last="$(tail -n 1 file)"
  echo $((last+1)) >> file
  sleep 0.1
done
