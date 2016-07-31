#include <memory>
#include <string>
#include <functional>

namespace Git {

/**
 *  @brief Класс описывающий git репозиторий.
 */

class Repository
{
public:
	struct CloneCallbacks
	{
		std::function<void(unsigned int,
						   unsigned int,
						   unsigned int,
						   unsigned int,
						   unsigned int,
						   unsigned int,
						   size_t)> fetchProgress {nullptr};
		std::function<void(const char*,size_t,size_t)> checkoutProgress {nullptr};
	};

	Repository();
	~Repository();

	bool Open(const std::string& path);
	bool Clone(const std::string& path, const std::string& url, CloneCallbacks cb);

	void Close();
	std::string GetPath() const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
}
