#!/usr/bin/env bash

##### macos mkdir -p build
pushd build
cmake ..
make -j8
popd