# cmake_minimum_required(VERSION <specify CMake version here>)
project(DLA_Simulator)

set(CMAKE_CXX_STANDARD 14)

set(src_dir
        main.cpp
        )

add_executable(DLA_Simulator ${src_dir})