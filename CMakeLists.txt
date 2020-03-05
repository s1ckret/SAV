cmake_minimum_required(VERSION 3.12)

project(SAVexe)

find_package(OpenGL REQUIRED)

# Set C++14
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14")
endif()

add_subdirectory(SAV/vendor/)

include_directories(
                        SAV/
                        SAV/src/
                        SAV/vendor/GLEW/include/
                        SAV/vendor/GLFW/include/
                        SAV/vendor/GLM/
                        SAV/vendor/
                        SAV/vendor/spdlog/include/
                    )           

file(GLOB SOURCES
        SAV/src/*.cpp
        SAV/src/**/*.cpp
        SAV/src/**/**/*.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} libglew_static glfw glm imgui spdlog)