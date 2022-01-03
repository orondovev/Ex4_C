cmake_minimum_required(VERSION 3.16)
project(Ex4_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex4_C main.c edges.c edges.h nodes.c nodes.h algo.c algo.h)
