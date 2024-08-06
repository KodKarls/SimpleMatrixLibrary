project(SimpleMatrixTests)

set(MATRIX_TESTS_DIR matrix_tests)

add_subdirectory(${TEST_LIBS_DIR}/googletest)

add_executable(SimpleMatrixTests main.cpp
               ${MATRIX_TESTS_DIR}/test_matrix.cpp)

target_link_libraries(SimpleMatrixTests gtest gtest_main)
target_link_libraries(SimpleMatrixTests matrix)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})