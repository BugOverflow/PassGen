#!/usr/bin/env bash

cd build
cmake ../ -DBUILD_TEST=1 -DWITH_WARNINGS=1
make
