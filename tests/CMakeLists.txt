include_directories(${tutorial_INCDIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(tutorial_test tutorial_test.cpp)
target_link_libraries(tutorial_test tutorial gtest_main)
add_test(TutorialTest mpirun -n 4 ${CMAKE_BINARY_DIR}/tutorial_src/tests/tutorial_test)

add_executable(gather_test gather_test.cpp)
target_link_libraries(gather_test tutorial gtest_main)
add_test(GatherTest mpirun -n 4 ${CMAKE_BINARY_DIR}/tutorial_src/tests/gather_test)


