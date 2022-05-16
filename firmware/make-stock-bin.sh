#!/bin/bash

rm -rf build
mkdir -p build bin

touch build/standing-desk.yaml
cat config.yaml >> build/standing-desk.yaml
sed -i "" "s/DESK_BRAND/$1/" build/standing-desk.yaml

esphome compile build/standing-desk.yaml
cp build/.esphome/build/standing-desk/.pioenvs/standing-desk/firmware.bin bin/stock-$1.bin

rm build/standing-desk.yaml