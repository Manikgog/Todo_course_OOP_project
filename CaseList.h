/*!
* /brief класс CaseList "Список дел".
* 
* Обеспечивает добавление дела в список, 
* удаление дела из списка,
* очистку списка,
* возвращение размера списка.
*/
#ifndef _CASELIST_H_
#define _CASELIST_H_

#include "Case.h"
#include "Date.h"
#include <vector>

class CaseList
{
private:
	std::vector<Case*> _caseList;			// вектор с указателями на экземпляры класса Case
	size_t MaxLength();						// метод возвращающий длину самого длинного дела по количеству символов
	bool CheckIndex(int index);				// метод для проверка валидности индекса для контроля выхода за границы вектора
public:
	CaseList() {}						
	CaseList(const CaseList& cList);
	~CaseList();
	void AddCase(const Case& case_);		// метод добавления задачи в список
	bool DeleteCase(int index);				// метод для удаления задачи из списка
	void Clear();							// метод для очистки списка задач
	size_t Size() const;							// метод возвращающий размер списка
	Case& GetCase(size_t index);			// метод возвращаюищй ссылку на задачу (объект Case) по индексу 
	std::vector<Case*> GetCaseList() const;	// метод возвращающий вектор задач
	void SortListByDate();					// метод для сортировки дел по дате
	void PrintList();						// вывод на экран списка дел
	void PrintCaseByIndex(size_t index);
};

#endif
