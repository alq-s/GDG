#!/bin/bash

set -e

echo "NOTE: Expect an Installation Script for Windows Systems later on"

command -v gcc >/dev/null 2>&1 || { echo >&2 "GCC is required but not installed. Aborting."; exit 1; }
command -v ar >/dev/null 2>&1 || { echo >&2 "ar is required but not installed. Aborting."; exit 1; }


gcc -c gdg.c -o gdg.o

ar rcs libgdg.a gdg.o

sudo mkdir -p /usr/local/include
sudo mkdir -p /usr/local/lib

sudo cp gdg.h /usr/local/include/
sudo cp libgdg.a /usr/local/lib/
sudo cp types.h /usr/local/include/

sudo ldconfig

rm -f gdg.o libgdg.a

echo "The GDG Library was installed"
echo "Include <gdg.h> in your program and link with -lgdg"
echo "If you come across any problems, report to the Github Repository"
echo "https://github.com/alq-s/GDG"

# This installs the GDG library on Linux systems