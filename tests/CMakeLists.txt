include_directories(${tutorial_INCDIR})

add_executable(tutorial_test tutorial_test.cpp)
target_link_libraries(tutorial_test tutorial googletest)
add_test(TutorialTest mpirun -n 4 ./tutorial_test)

