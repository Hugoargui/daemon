#! /bin/sh

cmake -S . build -G "Unix Makefiles"
(cd build && make)

