#!/usr/bin/env bash

gcc -O3 `pkg-config sdl2 SDL2_image --cflags --libs` main.c
./a.out
