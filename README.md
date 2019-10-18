# snap

A set of simple utility functions and classes for C++

### Requirements

- g++ (c++11 supported)
- CMake 3.5.1 or above
- gtest
- gcovr
- python

### How to install the required packages

Use the following command to install the packages on Ubuntu

    $ sudo apt-get install build-essential gcc g++ cmake libgtest-dev python python-pip cppcheck clang-tidy gcovr
    $ pip install cpplint
    $ cmake . /usr/src/gtest/
    $ make .
    $ sudo cp libgtest*.a /usr/lib

### How to build

    $ ./build.sh


### Licenses

This project code is available under MIT license. SEE [License](LICENSE).
