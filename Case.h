#ifndef _CASE_H_
#define _CASE_H_

#include <string>
#include "Date.h"

class Case
{
private:
	std::string _title;
	Date _date;

public:
	Case();
	Case(std::string title, std::string date);
	std::string GetTitle();
	Date GetDate();
	void PrintCase();
};


#endif // !_CASE_H_

