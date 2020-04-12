add_library(libgit++ ${CMAKE_CURRENT_LIST_DIR}/src/GitCommit.cpp
					 ${CMAKE_CURRENT_LIST_DIR}/src/GitCore.cpp
					 ${CMAKE_CURRENT_LIST_DIR}/src/GitRepository.cpp)

target_include_directories(libgit++ PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/
									PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/)

target_link_libraries(libgit++ CONAN_PKG::libgit2)
