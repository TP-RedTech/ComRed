cmake_minimum_required(VERSION 3.17)
project(Utils)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB test_source
        "${PROJECT_SOURCE_DIR}/test/*.cpp"
        )

add_library(Utils STATIC ${sources})

add_executable(gtest ${test_source})
target_link_libraries(gtest  Utils ServerApplication ${GTEST_LIBRARIES})
target_link_libraries(gtest -lgmock)