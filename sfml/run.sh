#!/usr/bin/env bash

g++ -O3 `pkg-config sfml-all --cflags --libs` main.cpp
./a.out
