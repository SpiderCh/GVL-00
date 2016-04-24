cmake_minimum_required(VERSION 3.3.1)

project(GitViewer)

set(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_HELPER_FILES "${REPO_ROOT}/cmake")
set(SOURCE_DIR "${REPO_ROOT}/src")
set(CMAKE_MODULE_PATH "${CMAKE_HELPER_FILES}")

include(${CMAKE_HELPER_FILES}/compile_defenitions.cmake)
include(${CMAKE_HELPER_FILES}/target.cmake)
include(${CMAKE_HELPER_FILES}/install_target.cmake)
include(${CMAKE_HELPER_FILES}/documentation.cmake)

find_package(Boost REQUIRED)
find_package(LibGit2 REQUIRED)

AddCompileDefenitions(
	"-std=c++11"
	"-Wall"
	"-Wpedantic"
	"-Wextra"
    )

AddTarget(NAME GitViewer
	TYPE app
	OUTPUT_NAME "GitViewer"
	SOURCE_DIR "${SOURCE_DIR}/*")
