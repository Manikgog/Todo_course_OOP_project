/*!
\brief Класс Case (задача, дело), который содержит поля название дела и дату
*/
#ifndef _CASE_H_
#define _CASE_H_

#include <string>
#include "Date.h"

class Date;

class Case
{
private:
	std::string _title;
	Date _date;

public:
	Case();
	Case(std::string title, std::string date);
	Case(std::string title, Date date);
	Case(char* title, char* date);
	std::string GetTitle();
	Date GetDate();
	
};


#endif // !_CASE_H_

