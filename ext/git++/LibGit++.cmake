
AddTarget(
	NAME libgit++
	TYPE shared_lib
	SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src"
	CMAKE
		PkgConfig
	FIND_PKG
		libgit2
	EXTRA_CMAKE
		LibGit2
	LINK_LIB
		LIBGIT2_LIBRARIES
	)
