cmake_minimum_required(VERSION 3.25)
project(lab2_source C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2_source

        mypcm.c
        mypcm.h lab2.c)
