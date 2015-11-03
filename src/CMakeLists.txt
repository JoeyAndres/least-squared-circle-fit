include_directories(../includes)

file(GLOB SRC_FILES "*.cpp")
add_library(least_squares_circle_fit ${SRC_FILES})