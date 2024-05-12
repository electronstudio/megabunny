#!/usr/bin/env bash

gcc -O3 -lraylib main.c
LD_LIBRARY_PATH=/usr/local/lib ./a.out
