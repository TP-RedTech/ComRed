cmake_minimum_required(VERSION 3.5)
project(ComRedServer)

set(CMAKE_CXX_STANDARD 14)

include(configure_gtest.cmake)
#add_subdirectory(test)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/server/*.h"
        "${PROJECT_SOURCE_DIR}/include/controller/*.h"
        "${PROJECT_SOURCE_DIR}/include/requests/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(ComRedServer ${sources})