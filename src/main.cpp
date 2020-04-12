#include <iostream>

#include "git++/GitCore.hpp"
#include "git++/GitRepository.hpp"

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	Git::InitGitCore();

	Git::Repository::CloneCallbacks cb(
		[](unsigned int	total_objects
						, unsigned int	indexed_objects
						, unsigned int	received_objects
						, unsigned int	local_objects
						, unsigned int	total_deltas
						, unsigned int	indexed_deltas
						, size_t	received_bytes)
		{
			std::cout << "Fetch progress:"       << std::endl
					  << "\tTotal objects:\t"    << total_objects    << std::endl
					  << "\tIndexed objects:\t"  << indexed_objects  << std::endl
					  << "\tReceived objects:\t" << received_objects << std::endl
					  << "\tLocal objects:\t"    << local_objects    << std::endl
					  << "\tTotal deltas:\t"     << total_deltas     << std::endl
					  << "\tIndexed deltas:\t"   << indexed_deltas   << std::endl
					  << "\tRecived bytes:\t"    << received_bytes   << std::endl;
		},
		[](const char*, size_t current, size_t total)
		{
			std::cout << "Checkout progress for: " << /*path << " :" <<*/ std::endl
					  << "\tCurrent:\t" << current << std::endl
					  << "\tTotal:\t"   << total   << std::endl;
		}
	);

	Git::Repository repo;
	const bool res = repo.Clone("/Users/chas/projects/git/test/gvl-01", "https://github.com/SpiderCh/GVL-00.git", cb);
	if(res) {
		std::cout << "Successfully clone repository";
	} else {
		Git::GitError err = Git::GetLastError();
		std::cout << "Cannot clone repository" << std::endl
				  << "\tMessage: " << err.message << std::endl
				  << "\tError Code: " << err.errorType << std::endl;
	}
	return 0;
}
