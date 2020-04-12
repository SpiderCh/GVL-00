#include "git++/GitCore.hpp"

#include <git2/global.h>
#include <git2/errors.h>

namespace Git {

GitError::GitError()
	: errorType(GIT_ERROR_NONE)
{}

GitError::GitError(int error, std::string message)
	: message(message)
	, errorType(error)
{}

void InitGitCore()
{
	git_libgit2_init();
}

void DeInitGitCore()
{
	git_libgit2_shutdown();
}

GitError GetLastError()
{
	const git_error *err = git_error_last();
	return GitError{err->klass, err->message};
}
}
