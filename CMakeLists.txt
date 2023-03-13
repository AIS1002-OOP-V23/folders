cmake_minimum_required(VERSION 3.15)
project(folders)

set(CMAKE_CXX_STANDARD 17)

# INTERFACE because the target "folder" is header-only
add_library(folder INTERFACE "${CMAKE_SOURCE_DIR}/include/ais1002/folder.hpp")
target_include_directories(folder INTERFACE "${CMAKE_SOURCE_DIR}/include")

add_executable(folder_demo main.cpp)
target_link_libraries(folder_demo PUBLIC folder)

# testing
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
