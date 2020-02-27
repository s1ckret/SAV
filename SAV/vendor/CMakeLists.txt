cmake_minimum_required(VERSION 3.12)

add_subdirectory(GLEW/)
add_subdirectory(GLFW/)
add_subdirectory(GLM/)
add_subdirectory(spdlog/)

project(imgui)

include_directories(imgui/)
include_directories(GLFW/include/)

file(GLOB IMGUI_SOURCES 
        imgui/*.cpp
        imgui/examples/imgui_impl_glfw.cpp
        imgui/examples/imgui_impl_opengl3.h
    )

file(GLOB IMGUI_HEADERS 
        imgui/*.h
        imgui/examples/imgui_impl_glfw.h
        imgui/examples/imgui_impl_opengl3.cpp
    )

add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
