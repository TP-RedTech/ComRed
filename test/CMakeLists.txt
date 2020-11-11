cmake_minimum_required(VERSION 3.1)

project(tests)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall")
set(CMAKE_C_FLAGS "-g -O0 -Wall")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SRC
    
)

add_library(tests STATIC ${SRC})
add_executable(test main.cpp)

target_link_library(test tests)
target_link_library(test app)
target_link_library(test ${GTEST_LIBRARIES} pthread -lgmock)