set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/")

cmake_minimum_required(VERSION 3.9)
project(CINVADERS)
find_package(SDL2 REQUIRED)

include_directories(../Cinvaders/Include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "../Cinvaders/*.cpp")


add_executable(CINVADERS ${SOURCES})
