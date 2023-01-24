#!/bin/bash

GAME_NAME=${1:-game}

if [ -d "build" ]; then
    rm -r build
fi

mkdir build

gcc src/*.c -lraylib -lm -o build/$GAME_NAME

build/$GAME_NAME
