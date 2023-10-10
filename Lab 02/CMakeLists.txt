cmake_minimum_required(VERSION 3.26)
project(Lab_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab_02
        Dealership.cpp
        Dealership.h
        main.cpp
        Showroom.cpp
        Showroom.h
        Vehicle.cpp
        Vehicle.h)
