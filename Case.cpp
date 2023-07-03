#include "Case.h"


Case::Case() 
	: _title(""), _date(Date()) {}

Case::Case(std::string title, std::string date) 
	: _title(title), _date(Date(date)) {}

Case::Case(std::string title, Date date) : _title(title), _date(Date(date)){}

Case::Case(char* title, char* date) : _title(title), _date(Date(date)) {}

std::string Case::GetTitle()
{
	return _title;
}

Date Case::GetDate()
{
	return _date;
}

