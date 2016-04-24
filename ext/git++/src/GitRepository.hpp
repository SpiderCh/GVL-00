#include <git2/repository.h>
#include <string>

namespace git {

/**
 *  @brief Класс описывающий git репозиторий.
 */
class Repository
{
public:
	Repository();
	~Repository();

	/**
	 * @brief  Функция открывающая существующий репозиторий
	 * @param path --- путь до репозитория
	 * @param isBare --- пустой ли это репозиторий
	 * @return true если репозиторий удалось открыть, в противном случае false
	 */
	bool Open(const std::string& path, bool isBare = false);

	/**
	 * @brief Функция создаёт репозиторий по указанному пути
	 * @param path --- путь до нового репозитория
	 * @param isBare --- пустой репозиторий
	 * @return true если репозиторий удалось открыть, в противном случае false
	 */
	bool Create(const std::string& path, bool isBare = false);

	/**
	 * @brief  Функция закрывает работу с выбранным репозиторием.
	 */
	void Close();

private:
	git_repository* m_repository{nullptr};
	std::string m_repoPath;
};
}
