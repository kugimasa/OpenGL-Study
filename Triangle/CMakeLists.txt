cmake_minimum_required(VERSION 3.15)
project(Triangle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Triangle main.cpp triangle.cpp triangle.hpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(Triangle ${OPENGL_LIBRARY} ${GLUT_LIBRARY})