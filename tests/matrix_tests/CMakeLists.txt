include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMatrixTests
               main.cpp
               test_matrix.cpp)

target_link_libraries(runMatrixTests gtest gtest_main)
target_link_libraries(runMatrixTests matrix)