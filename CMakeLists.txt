cmake_minimum_required(VERSION 2.8)
project(PassGen)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
list(APPEND CMAKE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

file(GLOB_RECURSE PassGen_SOURCES src/*.c src/*.h)
include_directories(AFTER ${CMAKE_SOURCE_DIR}/src/)

add_executable(${PROJECT_NAME} ${PassGen_SOURCES})
