cmake_minimum_required(VERSION 3.15)
project(itertools-cfar-a)

set(CMAKE_CXX_STANDARD 14)

add_executable(itertools-cfar-a Demo.cpp TestCounter.cpp doctest.h range.hpp accumulate.hpp filterfalse.hpp compress.hpp Test.cpp TestRunner.cpp)
