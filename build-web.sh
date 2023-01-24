#!/bin/bash

GAME_NAME=${1:-game}

if [ -d "build" ]
    rm -r build
fi

mkdir build

emcc -o build/$GAME_NAME.html src/*.c -Os -Wall -I/usr/local/include lib/emscripten/libraylib.a -s USE_GLFW=3 -s ASYNCIFY -s EXPORTED_RUNTIME_METHODS=ccall,cwrap --preload-file data --shell-file lib/emscripten/shell.html
emrun build/$GAME_NAME.html
