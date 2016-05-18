#!/usr/bin/env bash

source /opt/qt56/bin/qt56-env.sh

cd build
cmake ../ -DBUILD_GUI=1 -DBUILD_TEST=1
make
