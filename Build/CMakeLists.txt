cmake_minimum_required(VERSION 3.11)
project(CINVADERS)
include_directories(../Cinvaders/Include)

file(GLOB SOURCES "../Cinvaders/*.cpp")

add_executable(CINVADERS ${SOURCES})
