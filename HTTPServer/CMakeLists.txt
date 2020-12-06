cmake_minimum_required(VERSION 3.5)
project(ComRedServer)

set(CMAKE_CXX_STANDARD 14)

include(configure_gtest.cmake)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/server/*.h"
        "${PROJECT_SOURCE_DIR}/include/controller/*.h"
        "${PROJECT_SOURCE_DIR}/include/requests/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp")

find_package(Boost 1.71 REQUIRED)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(ComRedServer ${sources})

target_link_libraries(ComRedServer
            ${CMAKE_THREAD_LIBS_INIT})
