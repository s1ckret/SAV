cmake_minimum_required(VERSION 3.12)


project(SavLib)

find_package(OpenGL REQUIRED)

add_subdirectory(SAV/vendor/)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Wall /std:c++14")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Wall /std:c++14")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -O0 -g -std=c++14")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -O3 -std=c++14")
endif()

include_directories(SAV/
                    SAV/src/
                    SAV/vendor/
)           

file(GLOB_RECURSE SOURCES
        SAV/src/*.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} libglew_static glfw glm imgui spdlog)




project(SAVexe)

find_package(OpenGL REQUIRED)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Wall /std:c++14")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Wall /std:c++14")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -O0 -g -std=c++14")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -O3 -std=c++14")
endif()

include_directories(SAV/include/
                    Sandbox/src/
)           

file(GLOB_RECURSE SOURCES
        Sandbox/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} SavLib)
