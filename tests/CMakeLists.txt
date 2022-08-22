include_directories(${tutorial_INCDIR})

add_executable(tutorial_test tutorial_test.cpp)
target_link_libraries(tutorial_test tutorial gtest_main)
add_test(TutorialTest ${CMAKE_BINARY_DIR}/tutorial_src/tests/tutorial_test)

