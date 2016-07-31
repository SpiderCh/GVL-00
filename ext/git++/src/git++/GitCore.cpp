#include "GitCore.hpp"

#include <git2/global.h>
#include <git2/errors.h>
#include <git2.h>

namespace Git {
void InitGitCore() {
	git_libgit2_init();
}

void DeInitGitCore()
{
	git_libgit2_shutdown();
}

GitError GetLastError()
{
	const git_error *err = giterr_last();
	GitError error;
	error.errorType = err->klass;
	error.message = err->message;
	return error;
}
}
