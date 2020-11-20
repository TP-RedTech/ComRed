cmake_minimum_required(VERSION 3.5)
project(DB)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB SRC
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB TEST_SRC
        ${PROJECT_SOURCE_DIR}/test/testDB.cpp
)

add_library(DB STATIC ${SRC}) 
target_include_directories(DB PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(test_db ${TEST_SRC})
target_link_libraries(test_db 
                        DB
                        Utils
                        ServerApplication
)
target_link_libraries(test_db ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_db -lgmock)
