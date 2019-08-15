cmake_minimum_required(VERSION 3.14)
project(program C)
set(CMAKE_SKIP_RPATH TRUE)

add_library(mathlib SHARED mathprog.c)
target_include_directories(mathlib PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(program program.c)

# if using recent gcc, we don't want
# RUNPATH default, which CMake will otherwise
# leverage here -- we switch to using
# RPATH, but this should ONLY
# be if we allow CMake to use RPATH
target_link_options(program PRIVATE
        LINKER:--disable-new-dtags)

target_link_libraries(program PRIVATE mathlib)
