#!/bin/bash

# Build
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DDISTRIBUTOR=karboggy -DCRASH_REPORTER=OFF
cmake --build build -j$(nproc)
cmake --install build