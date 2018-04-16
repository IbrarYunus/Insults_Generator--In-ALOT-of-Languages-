cmake_minimum_required(VERSION 3.9)
project(InsultsGenerator)

set(CMAKE_CXX_STANDARD 11)

add_executable(InsultsGenerator main.cpp InsultsProcessor.cpp InsultsProcessor.h)