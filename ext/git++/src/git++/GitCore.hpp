#ifndef GITVIEWER_GITCORE_HPP
#define GITVIEWER_GITCORE_HPP

#include <string>

namespace Git
{
struct GitError
{
	std::string message;
	int errorType;

	GitError();
	GitError(int, std::string);
};

void InitGitCore();
void DeInitGitCore();
GitError GetLastError();
}


#endif //GITVIEWER_GITCORE_HPP
