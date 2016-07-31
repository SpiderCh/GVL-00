#ifndef GIT_COMMIT_HPP
#define GIT_COMMIT_HPP
#include <git2/commit.h>
#include <git2/types.h>

namespace git
{
class Commit
{
public:
	Commit();
	~Commit();
private:
	git_commit* m_commit{nullptr};
};
}

#endif //GIT_COMMT_HPP
