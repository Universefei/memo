#!/usr/bin/env bash

rm *.o animatedtiles qrc_*.cpp *.moc Makefile
qmake -project
qmake animatedtiles.pro
make
./animatedtiles
