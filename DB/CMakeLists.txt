cmake_minimum_required(VERSION 3.5)
project(DB)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB SRC
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(DB ${SRC}) 
