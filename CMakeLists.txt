cmake_minimum_required(VERSION 3.17.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GitViewer CXX C)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wpedantic -Wextra)
endif()

###############
# CONAN SETUP #
###############

set(CONANBUILD_INFO_FILE "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
set(CONANBUILD_INFO_MULTICONFIGURATION_FILE "${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake")
set(CONAN_OPTIONS "TARGETS;KEEP_RPATHS")

if (EXISTS "${CONANBUILD_INFO_MULTICONFIGURATION_FILE}")
	include(${CONANBUILD_INFO_MULTICONFIGURATION_FILE})
	set(CONAN_CMAKE_MULTI ON)
elseif (EXISTS "${CONANBUILD_INFO_FILE}")
	include(${CONANBUILD_INFO_FILE})
	list(APPEND CONAN_OPTIONS "NO_OUTPUT_DIRS")
	set(CONAN_CMAKE_MULTI OFF)
else()
	message(FATAL_ERROR "Cannot load any conanbuildinfo file.")
endif()

conan_basic_setup(${CONAN_OPTIONS})

unset(CONAN_OPTIONS)
unset(CONANBUILD_INFO_FILE)
unset(CONANBUILD_INFO_MULTICONFIGURATION_FILE)

###########
# Modules #
###########
include(${CMAKE_CURRENT_SOURCE_DIR}/lib/git++/LibGit++.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/src/viewer.cmake)
