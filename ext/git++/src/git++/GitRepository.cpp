#include "GitRepository.hpp"

namespace git {
Repository::Repository() = default;

Repository::~Repository()
{
	Close();
}

void  Repository::Close()
{
	if(m_repository)
		git_repository_free(m_repository);
	m_repository = nullptr;
	m_repoPath = "";
}

bool Repository::Open(const std::string &path, bool isBare)
{
	return false;
}

}
