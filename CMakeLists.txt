cmake_minimum_required(VERSION 3.22)
project(dbdemo)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-l sqlite3)

add_executable(dbdemo main.cpp sqlite3.c)


