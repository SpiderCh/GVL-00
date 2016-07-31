#include "GitCore.hpp"

#include <git2/global.h>

namespace git {
    void InitGitCore() {
        git_libgit2_init();
    }

    void DeInitGitCore()
    {
        git_libgit2_shutdown();
    }
}