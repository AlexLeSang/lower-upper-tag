cmake_minimum_required(VERSION 3.10)
project(lower-upper-tragging)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wc++11-compat -march=native -O3")
add_executable(lower-upper-tragging main.cpp)
