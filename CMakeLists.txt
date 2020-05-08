cmake_minimum_required(VERSION 3.12)

add_subdirectory(SAV/vendor/)

project(SAVexe)

find_package(OpenGL REQUIRED)

# Set C++14
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14")
endif()


include_directories(
                        SAV/
                        SAV/src/
                        SAV/vendor/
                    )           

file(GLOB_RECURSE SOURCES
        SAV/src/*.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} libglew_static glfw glm imgui spdlog)