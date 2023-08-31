include_directories(${tutorial_INCDIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(power_method_test power_method_test.cpp)
target_link_libraries(power_method_test tutorial gtest_main ${MPI_LIBRARIES})
add_test(PowerMethodTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/power_method_test)

add_executable(power_method_vec_test power_method_vec_test.cpp)
target_link_libraries(power_method_vec_test tutorial gtest_main ${MPI_LIBRARIES})
add_test(PowerMethodVecTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/power_method_vec_test)

add_executable(power_method_val_test power_method_val_test.cpp)
target_link_libraries(power_method_val_test tutorial gtest_main ${MPI_LIBRARIES})
add_test(PowerMethodValTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/power_method_val_test)

add_executable(gather_test gather_test.cpp)
target_link_libraries(gather_test tutorial gtest_main ${MPI_LIBRARIES})
add_test(GatherTest mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/gather_test)

add_executable(gather_test_self gather_test_self.cpp)
target_link_libraries(gather_test_self tutorial gtest_main ${MPI_LIBRARIES})
add_test(GatherTestSelf mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/gather_test_self)

add_executable(gather_test_nonzero_root gather_test_nonzero_root.cpp)
target_link_libraries(gather_test_nonzero_root tutorial gtest_main ${MPI_LIBRARIES})
add_test(GatherTestNonzeroRoot mpirun -n 4 --oversubscribe ${CMAKE_BINARY_DIR}/tutorial_src/tests/gather_test_nonzero_root)

