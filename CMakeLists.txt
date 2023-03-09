cmake_minimum_required(VERSION 3.10)
project(ping)

set(CMAKE_CXX_STANDARD 14)


add_executable(ping main.cpp src/ping.cpp src/ping.h)
