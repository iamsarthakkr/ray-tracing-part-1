#! /bin/bash
ROOT_DIR=$(pwd)

echo $ROOT_DIR

cmake -S . -B out/build
cd out/build && make
cd $ROOT_DIR