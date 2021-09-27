#!/bin/bash
SDL2_VERSION=2.0.16
sudo apt-get -y update
sudo apt-get -y install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64
wget https://www.libsdl.org/release/SDL2-devel-${SDL2_VERSION}-mingw.tar.gz
tar -zxvf SDL2-devel-${SDL2_VERSION}-mingw.tar.gz
mv SDL2-${SDL2_VERSION}/x86_64-w64-mingw32 SDL2
rm -rf SDL2-devel-${SDL2_VERSION}-mingw.tar.gz SDL2-${SDL2_VERSION}