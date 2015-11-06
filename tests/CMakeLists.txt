enable_testing()

include_directories(
        ../includes
        includes)

add_executable(base_test base_test.cpp)
target_link_libraries(base_test gtest gtest_main armadillo)

#add_test(NAME test COMMAND base_test)
add_custom_target(run_test base_test)