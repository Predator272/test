cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project("test" VERSION 2022.11.30)

add_executable(${PROJECT_NAME} "src/main.cpp")

# include glfw

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory("external/glfw")
target_link_libraries(${PROJECT_NAME} glfw)
