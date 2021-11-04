cmake_minimum_required(VERSION 3.0.0)
project(ImGui VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 14)

add_library("glad" "~/Graphics/glad/src/glad.c")
include_directories("~/Graphics/glad/include"
                    "~/Graphics/imgui")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(ImGui main.cpp)

target_link_libraries(ImGui
                      glfw
                      ${OPENGL_LIBRARY}
                      "glad"
                      "-framework Cocoa"
                      "-framework IOKit"
                      "-framework CoreVideo")

set(sources
    main.cpp
    imgui/imconfig.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_impl_glfw.cpp
    imgui/imgui_impl_glfw.h
    imgui/imgui_impl_opengl3.cpp
    imgui/imgui_impl_opengl3.h
    imgui/imgui_internal.h
    imgui/imgui_widgets.cpp
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
)