cmake_minimum_required(VERSION 3.6.0)

project(GitViewer)

set(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EXT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext")
set(CMAKE_HELPER_FILES "${REPO_ROOT}/cmake")
set(SOURCE_DIR "${REPO_ROOT}/src")
set(CMAKE_MODULE_PATH "${CMAKE_HELPER_FILES}")

include(${CMAKE_HELPER_FILES}/compile_defenitions.cmake)
include(${CMAKE_HELPER_FILES}/target.cmake)
include(${CMAKE_HELPER_FILES}/install_target.cmake)
include(${CMAKE_HELPER_FILES}/documentation.cmake)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Modules
include(${EXT_DIR}/git++/LibGit++.cmake)

AddTarget(
	NAME GitViewer
	TYPE app
	OUTPUT_NAME "GitViewer++"
	SOURCE_DIR "${SOURCE_DIR}"
	CMAKE
		Boost
	QT_LIB
		Core
		Widgets
		Gui
	DEPENDENCIES
		libgit++
	)
