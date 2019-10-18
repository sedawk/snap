#!/bin/bash

cmake . || exit 1
make -j || exit 1
ctest --output-on-failure || exit 1
make coverage
