#include "GitRepository.hpp"

#include <git2/repository.h>
#include <git2/clone.h>
#include <git2/errors.h>

namespace Git {

namespace
{
int FetchProgress(const git_transfer_progress *stats, void *data)
{
	Repository::CloneCallbacks *cb = reinterpret_cast<Repository::CloneCallbacks*>(data);
	if(cb && cb->fetchProgress)
		cb->fetchProgress(stats->total_objects,
						  stats->indexed_objects,
						  stats->received_objects,
						  stats->local_objects,
						  stats->total_deltas,
						  stats->indexed_deltas,
						  stats->received_bytes);
	return 0;
}

void CheckoutProgress(const char *path, size_t cur,  size_t tot,  void *data)
{
	Repository::CloneCallbacks *cb = reinterpret_cast<Repository::CloneCallbacks*>(data);
	if(cb && cb->checkoutProgress)
		cb->checkoutProgress(path, cur, tot);
}
}

Repository::CloneCallbacks::CloneCallbacks() = default;

Repository::CloneCallbacks::CloneCallbacks(const FetchCallback &fc, const CheckoutCallback& cc)
	: fetchProgress(fc)
	, checkoutProgress(cc)
{}

struct Repository::Impl
{
	git_repository* repository {nullptr};
	std::string path;
};

Repository::Repository()
	:m_impl(std::make_unique<Impl>())
{}

Repository::~Repository()
{
	Close();
}

bool Repository::Open(const std::string &path)
{
	if(m_impl->repository)
		return false;

	m_impl->path = path;
	const int error = git_repository_open(&m_impl->repository, m_impl->path.c_str());

	return error == GITERR_NONE;
}

bool Repository::Clone(const std::string &path, const std::string &url, CloneCallbacks cb)
{
	if(m_impl->repository)
		return false;

	m_impl->path = path;

	git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;

	clone_opts.checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
	clone_opts.checkout_opts.progress_cb = CheckoutProgress;
	clone_opts.checkout_opts.progress_payload = &cb;
	clone_opts.fetch_opts.callbacks.transfer_progress = FetchProgress;
	clone_opts.fetch_opts.callbacks.payload = &cb;

	const int error = git_clone(&m_impl->repository, url.c_str(), m_impl->path.c_str(), &clone_opts);

	return error == GITERR_NONE;
}

void  Repository::Close()
{
	if(!m_impl->repository)
		return;

	git_repository_free(m_impl->repository);
	m_impl->repository = nullptr;
	m_impl->path = "";
}

std::string Repository::GetPath() const
{
	return m_impl->path;
}

git_repository* Repository::GetRespository()
{
	return m_impl->repository;
}

}
