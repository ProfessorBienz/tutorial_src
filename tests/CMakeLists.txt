include_directories(${tutorial_INCDIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(datatype_test datatype_test.cpp)
target_link_libraries(datatype_test tutorial gtest_main)
add_test(DataypeTest mpirun -n 4 ${CMAKE_BINARY_DIR}/tutorial_src/tests/datatype_test)

add_executable(alltoall_test alltoall_test.cpp)
target_link_libraries(alltoall_test tutorial gtest_main)
add_test(AlltoallTest mpirun -n 4 ${CMAKE_BINARY_DIR}/tutorial_src/tests/alltoall_test)


