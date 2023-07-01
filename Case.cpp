#include "Case.h"


Case::Case() 
	: _title(""), _date(Date()) {}

Case::Case(std::string title, std::string date) 
	: _title(title), _date(Date(date)) {}

std::string Case::GetTitle()
{
	return _title;
}

Date Case::GetDate()
{
	return _date;
}

void Case::PrintCase()
{
	std::cout << _title << " ";
	_date.PrintDate();
}