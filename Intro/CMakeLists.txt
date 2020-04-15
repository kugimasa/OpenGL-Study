cmake_minimum_required(VERSION 3.14)
project(Intro)

set(CMAKE_CXX_STANDARD 14)

add_executable(Intro main.cpp)
add_executable(3D draw3D.cpp)
add_executable(Animation animation.cpp)
add_executable(HiddenSurfaceRemoval Animation hidden_surface_removal.cpp shading.cpp)
add_executable(Shading Animation shading.cpp)
add_executable(Hierarchical Animation hierarchical.cpp 3d_data.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(Intro ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
target_link_libraries(3D ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
target_link_libraries(HiddenSurfaceRemoval ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
target_link_libraries(Shading ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
target_link_libraries(Hierarchical ${OPENGL_LIBRARY} ${GLUT_LIBRARY})