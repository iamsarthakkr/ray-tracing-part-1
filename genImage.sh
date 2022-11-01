#! /bin/bash

ROOT_DIR=$(pwd)

./clean.sh
./compileScript.sh

cd $ROOT_DIR/out/build

./out > ./image.ppm
open -a ToyViewer ./image.ppm

cd $ROOT_DIR