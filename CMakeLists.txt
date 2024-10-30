cmake_minimum_required(VERSION 3.29)
project(SimpleMatrixLibrary)

set(CMAKE_CXX_STANDARD 20)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(MATRIX_DIR matrix)
set(TESTS_DIR ${ROOT_DIR}/tests)
set(TEST_LIBS_DIR ${TESTS_DIR}/libs)

set(SOURCE_FILES main.cpp)
add_executable(SimpleMatrixLibrary ${SOURCE_FILES})

include_directories(${MATRIX_DIR})

add_subdirectory(${MATRIX_DIR})
add_subdirectory(${TESTS_DIR})

target_link_libraries(SimpleMatrixLibrary ${MATRIX_DIR})
