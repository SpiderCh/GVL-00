#include <memory>
#include <string>
#include <functional>

struct git_repository;

namespace Git {

/**
 *  @brief Класс описывающий git репозиторий.
 */

class Repository
{
public:
	struct CloneCallbacks
	{
		using FetchCallback = std::function<void(unsigned int,
												 unsigned int,
												 unsigned int,
												 unsigned int,
												 unsigned int,
												 unsigned int,
												 size_t)>;
		using CheckoutCallback = std::function<void(const char*,size_t,size_t)>;

		FetchCallback fetchProgress {nullptr};
		CheckoutCallback checkoutProgress {nullptr};

		CloneCallbacks();
		CloneCallbacks(const FetchCallback&, const CheckoutCallback&);
	};

	Repository();
	~Repository();

	bool Open(const std::string& path);
	bool Clone(const std::string& path, const std::string& url, CloneCallbacks cb);

	void Close();
	std::string GetPath() const;

private:
	git_repository* GetRespository();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
}
