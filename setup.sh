#!/bin/bash
SDL2_VERSION=2.0.16
SDL2_IMAGE_VERSION=2.0.5
JSON_VERSION=3.10.2

# pkg dependencies
sudo apt-get -y update && sudo apt-get -y install rsync wget gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64

# library dependencies
wget -nc "https://www.libsdl.org/release/SDL2-devel-${SDL2_VERSION}-mingw.tar.gz"
wget -nc "https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-${SDL2_IMAGE_VERSION}-mingw.tar.gz"
wget -nc "https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/json.hpp"

# extract
tar -zxf SDL2-devel-${SDL2_VERSION}-mingw.tar.gz
tar -zxf SDL2_image-devel-${SDL2_IMAGE_VERSION}-mingw.tar.gz

mv SDL2-${SDL2_VERSION}/x86_64-w64-mingw32 SDL2
rsync -r SDL2_image-${SDL2_IMAGE_VERSION}/x86_64-w64-mingw32/ SDL2/.

rm -rf SDL2-devel-${SDL2_VERSION}-mingw.tar.gz SDL2_image-devel-${SDL2_IMAGE_VERSION}-mingw.tar.gz SDL2-${SDL2_VERSION} SDL2_image-${SDL2_IMAGE_VERSION}

