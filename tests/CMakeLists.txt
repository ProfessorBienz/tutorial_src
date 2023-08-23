include_directories(${tutorial_INCDIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(power_method_test power_method_test.cpp)
target_link_libraries(power_method_test tutorial gtest_main)
add_test(PowerMethodTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/power_method_test)

add_executable(gather_test gather_test.cpp)
target_link_libraries(gather_test tutorial gtest_main)
add_test(GatherTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/gather_test)


