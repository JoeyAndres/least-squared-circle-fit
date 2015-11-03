include_directories(
        ../includes
        includes)

add_executable(base_test "base_test.cpp")
target_link_libraries(base_test least_squares_circle_fit gtest)