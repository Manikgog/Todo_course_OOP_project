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

public:
	CaseList() {}						
	CaseList(const CaseList& cList);
	~CaseList();
	void AddCase(const Case& case_);		// метод добавления задачи в список
	void DeleteCase(int numCase);			// метод для удаления задачи из списка
	void Clear();							// метод для очистки списка задач
	size_t Size();							// метод возвращающий размер списка
	Case& GetCase(size_t index);			// метод возвращаюищй ссылку на задачу (объект Case) по индексу 
	std::vector<Case*> GetCaseList() const;	// метод возвращающий вектор задач
};

#endif
