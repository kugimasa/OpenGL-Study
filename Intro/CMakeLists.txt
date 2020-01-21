cmake_minimum_required(VERSION 3.14)
project(Intro)

set(CMAKE_CXX_STANDARD 14)

add_executable(Intro main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(Intro ${OPENGL_LIBRARY} ${GLUT_LIBRARY})