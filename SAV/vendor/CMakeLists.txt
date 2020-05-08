cmake_minimum_required(VERSION 3.12)

add_subdirectory(GLEW/)
include_directories(GLEW/include)

add_subdirectory(GLFW/)
include_directories(GLFW/include)

add_subdirectory(GLM/)
include_directories(GLW/)

add_subdirectory(spdlog/)
include_directories(spdlog/include)

include_directories(imgui/)

project(imgui)

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
