cmake_minimum_required(VERSION 3.28)
project(SimpleMatrixLibrary)

set(CMAKE_CXX_STANDARD 17)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(MATRIX_DIR matrix)

set(SOURCE_FILES main.cpp)
add_executable(SimpleMatrixLibrary ${SOURCE_FILES})

include_directories(${MATRIX_DIR})

add_subdirectory(${MATRIX_DIR})

target_link_libraries(SimpleMatrixLibrary ${MATRIX_DIR})
