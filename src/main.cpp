#include <iostream>

#include "git++/GitCore.hpp"

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;
	git::InitGitCore();
	std::cout << "Everything Ok." << std::endl;
	git::DeInitGitCore();
	return 0;
}
