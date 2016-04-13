cmake_minimum_required(VERSION 3.2.2)
project(PassGen)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(cmake/options.cmake)
include(CheckPlatform)
include(cmake/showoptions.cmake)

add_subdirectory(src)
