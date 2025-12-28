#!/bin/bash

# docker run --rm -it -v ./:/quickshell --workdir /quickshell hyprland-fedora43 ./build.sh

# Build
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DDISTRIBUTOR=karboggy -DCRASH_REPORTER=OFF
cmake --build build -j$(nproc)
cmake --install build