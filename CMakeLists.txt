cmake_minimum_required(VERSION 2.8)
project(least_squares_circle_fit)

# The version number.
set(node_draw_VERSION_MAJOR 0)
set(node_draw_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g")
#add_subdirectory(src)
add_subdirectory(tests)

# uninstall target
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

file(GLOB_RECURSE HEADERS
        includes/*.h)
install (FILES ${HEADERS} DESTINATION include/least_squares_circle_fit)
