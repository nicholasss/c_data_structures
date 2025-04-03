#!/usr/bin/env bash

gcc -g3 -Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion -Wpedantic "$1.c" -o "$1"
