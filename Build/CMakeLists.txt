cmake_minimum_required(VERSION 3.11)
project(CINVADERS)
find_package(SDL2 REQUIRED)

include_directories(../Cinvaders/Include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "../Cinvaders/*.cpp")


add_executable(CINVADERS ${SOURCES})
