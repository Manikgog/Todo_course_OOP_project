#include "Date.h"

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(int day, int month, int year)
	: _day(day), _month(month), _year(year)
{}

Date::Date(std::string date)
{
	int arr[3]{};						
	std::string s_tmp;
	char c;

	for (size_t i = 0, j = 0; i <= date.length(); ++i)
	{
		if ((date[i] == '.' || i == date.length()) && s_tmp.length() != 0)
		{
			arr[j] = stoi(s_tmp);
			s_tmp.erase();
			j++;
			if (j == 3) break;
		}

		if (date[i] >= '0' && date[i] <= '9')
		{
			c = date[i];
			s_tmp += c;
		}
	}
	_day = arr[0];
	_month = arr[1];
	_year = arr[2];
}


int Date::GetDay()
{
	return _day;
}

int Date::GetMonth()
{
	return _month;
}

int Date::GetYear()
{
	return _year;
}
