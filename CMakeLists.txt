cmake_minimum_required(VERSION 3.5)

project(life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDEBUG)

add_executable(life main.cpp)
