include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_branch test_branch.cpp)
target_link_libraries(test_branch tutorial gtest_main)
add_test(BranchTest ${CMAKE_BINARY_DIR}/tutorial_src/tests/test_branch)

add_executable(test_vectorize test_vectorize.cpp)
target_link_libraries(test_vectorize tutorial gtest_main)
add_test(VectorizeTest ${CMAKE_BINARY_DIR}/tutorial_src/tests/test_vectorize)

add_executable(test_parallel test_parallel.cpp)
target_link_libraries(test_parallel tutorial gtest_main)
add_test(ParallelTest ${CMAKE_BINARY_DIR}/tutorial_src/tests/test_parallel)

add_executable(test_speeds test_speeds.cpp)
target_link_libraries(test_speeds tutorial gtest_main)
add_test(SpeedTest ${CMAKE_BINARY_DIR}/tutorial_src/tests/test_speeds)
