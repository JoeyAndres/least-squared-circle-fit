include_directories(../includes)

enable_testing()

file(GLOB SRC_FILES "*.cpp")
add_library(least_squares_circle_fit ${SRC_FILES})