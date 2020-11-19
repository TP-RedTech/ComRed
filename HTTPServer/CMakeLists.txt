cmake_minimum_required(VERSION 3.17)
project(ComRedServer)

set(CMAKE_CXX_STANDARD 20)

include(configure_gtest.cmake)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/server/*.h"
        "${PROJECT_SOURCE_DIR}/include/controller/*.h"
        "${PROJECT_SOURCE_DIR}/include/requests/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(ComRedServer ${sources})