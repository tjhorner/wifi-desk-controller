#!/bin/bash

DESK_CONFIGS=(
  "uplift_v2"
)

for i in "${DESK_CONFIGS[@]}"
do
  ./make-stock-bin.sh $i
done