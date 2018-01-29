cmake_minimum_required(VERSION 3.2)

find_package (Boost REQUIRED)

include_directories(./include)

add_definitions("-std=c++17 -fPIC")

add_subdirectory(python)
add_subdirectory(src)
