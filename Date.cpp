#include "Date.h"

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(int day, int month, int year)
	: _day(day), _month(month), _year(year)
{
	if (!CheckDayByMonth())
	{
		std::cout << "Введённое количество дней не соответствует количеству дней в месяце.\n";
		exit(1);
	}
}

Date::Date(std::string date)
{
	int arr[3]{};						// цифра 3 - количество чисел в дате
	std::string s_tmp;
	char c;

	for (size_t i = 0, j = 0; i <= date.length(); ++i)
	{
		if ((date[i] == '.' || i == date.length()) && s_tmp.length() != 0)
		{
			arr[j] = stoi(s_tmp);
			s_tmp.erase();
			j++;
			if (j == 3) break;	// число 3 - количество чисел в дате т.е. день, месяц, год - три числа
		}

		if (date[i] >= '0' && date[i] <= '9')
		{
			c = date[i];
			s_tmp += c;
		}
	}
	if(!IsValidDate(arr[0], arr[1], arr[2]))
		std::cout << "Ошибка ввода!\n";
	_day = arr[0];
	_month = arr[1];
	_year = arr[2];
}



bool Date::IsValidDate(int day, int month, int year)
{
	// current date/time based on current system
	time_t now = time(0);

	//std::cout << "Number of sec since January 1,1970:" << now << std::endl;

	tm* ltm = localtime(&now);

	// print various components of tm structure.
	unsigned short currentYear = 1900 + ltm->tm_year;
	unsigned short currentMonth = 1 + ltm->tm_mon;
	unsigned short currentDay = ltm->tm_mday;
	unsigned short lengthOfFeb = 28; // начальная длина февраля / initial length of february
	switch (month) {
	case 1:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 2:
		if (isLeapYear(year))
			lengthOfFeb = 29;
		if (day < 1 || day > lengthOfFeb) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 3:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 4:
		if (day < 1 || day > 30) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 5:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 6:
		if (day < 1 || day > 30) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 7:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 8:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 9:
		if (day < 1 || day > 30) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 10:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 11:
		if (day < 1 || day > 30) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	case 12:
		if (day < 1 || day > 31) {
			std::cout << "\x1b[31mНеправильно введён день месяца.\x1b[0m" << std::endl;
			return false;
		}
		break;
	}

	if (month > 12) {
		std::cout << "\x1b[31mМесяцев должно быть меньше 13.\x1b[0m" << std::endl;
		return false;
	}

	if (year < currentYear) {
		std::cout << "\x1b[31mПланируемый год уже прошёл.\x1b[0m" << std::endl;
		return false;
	}
	else if (month < currentMonth && year == currentYear) {
		std::cout << "\x1b[31mПланируемый месяц уже прошёл.\x1b[0m" << std::endl;
		return false;
	}
	else if (day < currentDay && month == currentMonth) {
		std::cout << "\x1b[31mПланируемый день уже прошёл.\x1b[0m" << std::endl;
		return false;
	}
	return true;
}


bool Date::isLeapYear(int year) {
	if (year % 4 == 0) {
		if ((year % 100) == 0 && (year % 400) == 0) {
			//std::cout << "Год " << year << " високосный.\n";
			return true;
		}
		else if ((year % 100) != 0) {
			// std::cout << "Год " << year << " високосный.\n";
			return true;
		}
		else {
			//std::cout << "Год " << year << " не является високосным.\n";
			return false;
		}
	}

	//std::cout << "Год " << year << " не является високосным.\n";
	return false;
}





bool Date::CheckDayByMonth()	// проверка правильности введённого количества дней в месяце
{
	switch (_month)
	{
	case 1:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 2:

		if (_day >= 1 && _day <= DaysInFebruary())
			return true;
		else
			return false;
	case 3:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 4:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 5:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 6:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 7:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 8:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 9:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 10:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 11:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 12:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	}

	return false;
}

int Date::DaysInFebruary()	// функция возвращает количество дней в феврале в зависимости от високосности года
{
	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
	{
		return 29;
	}
	return 28;
}

Date& Date::operator-(int num)
{
	int result_days = NumberOfDayYear(_month) - num;

	if (result_days < 1)
	{
		_year--;
		if (DaysInFebruary() == 29)
		{
			result_days = 366 + result_days;
		}
		else
		{
			result_days = 365 + result_days;
		}
	}
	DaysToMonthsAndDays(result_days);

	return *this;
}

Date& Date::operator+(int num)
{
	int result_days = NumberOfDayYear(_month - 1) + num;

	if (result_days > NumberOfDaysInMonths(12))
	{
		_year++;
		if (DaysInFebruary() == 29)
		{
			result_days = result_days - 366;
		}
		else
		{
			result_days = result_days - 365;
		}
	}

	DaysToMonthsAndDays(result_days);

	return *this;
}

void Date::DaysToMonthsAndDays(int result_days)
{
	unsigned char month = 1;
	if (result_days >= 1 && result_days <= 31)
	{
		month = 1;
	}
	else if (result_days > NumberOfDaysInMonths(1) && result_days <= NumberOfDaysInMonths(2))
	{
		month = 2;
		result_days -= 31;
	}
	else if (result_days > NumberOfDaysInMonths(2) && result_days <= NumberOfDaysInMonths(3))
	{
		month = 3;
		result_days -= NumberOfDaysInMonths(2);
	}
	else if (result_days > NumberOfDaysInMonths(3) && result_days <= NumberOfDaysInMonths(4))
	{
		month = 4;
		result_days -= NumberOfDaysInMonths(3);
	}
	else if (result_days > NumberOfDaysInMonths(4) && result_days <= NumberOfDaysInMonths(5))
	{
		month = 5;
		result_days -= NumberOfDaysInMonths(4);
	}
	else if (result_days > NumberOfDaysInMonths(5) && result_days <= NumberOfDaysInMonths(6))
	{
		month = 6;
		result_days -= NumberOfDaysInMonths(5);
	}
	else if (result_days > NumberOfDaysInMonths(6) && result_days <= NumberOfDaysInMonths(7))
	{
		month = 7;
		result_days -= NumberOfDaysInMonths(6);
	}
	else if (result_days > NumberOfDaysInMonths(7) && result_days <= NumberOfDaysInMonths(8))
	{
		month = 8;
		result_days -= NumberOfDaysInMonths(7);
	}
	else if (result_days > NumberOfDaysInMonths(8) && result_days <= NumberOfDaysInMonths(9))
	{
		month = 9;
		result_days -= NumberOfDaysInMonths(8);
	}
	else if (result_days > NumberOfDaysInMonths(9) && result_days <= NumberOfDaysInMonths(10))
	{
		month = 10;
		result_days -= NumberOfDaysInMonths(9);
	}
	else if (result_days > NumberOfDaysInMonths(10) && result_days <= NumberOfDaysInMonths(11))
	{
		month = 11;
		result_days -= NumberOfDaysInMonths(10);
	}
	else if (result_days > NumberOfDaysInMonths(11) && result_days <= NumberOfDaysInMonths(12))
	{
		month = 12;
		result_days -= NumberOfDaysInMonths(11);
	}
	this->_month = month;
	this->_day = result_days;
}


int Date::NumberOfDaysInMonths(int numberOfMonth)
{
	int amountOfDays = 0;
	for (int i = 1; i <= numberOfMonth; ++i)
	{
		switch (i)
		{
		case 1:
			amountOfDays += 31;
			break;
		case 2:
			amountOfDays += (int)DaysInFebruary();
			break;
		case 3:
			amountOfDays += 31;
			break;
		case 4:
			amountOfDays += 30;
			break;
		case 5:
			amountOfDays += 31;
			break;
		case 6:
			amountOfDays += 30;
			break;
		case 7:
			amountOfDays += 31;
			break;
		case 8:
			amountOfDays += 31;
			break;
		case 9:
			amountOfDays += 30;
			break;
		case 10:
			amountOfDays += 31;
			break;
		case 11:
			amountOfDays += 30;
			break;
		case 12:
			amountOfDays += 31;
			break;
		}
	}
	return amountOfDays;
}

int Date::NumberOfDayYear(int numberOfMonth)
{
	int amountOfDays = NumberOfDaysInMonths(numberOfMonth);

	amountOfDays += _day;
	return amountOfDays;
}

void Date::PrintDate()
{
	std::cout << (int)_day << "." << (int)_month << "." << _year;

}

int Date::operator-(const Date& d)
{
	int resultDays_left = NumberOfDaysInMonths(_month) + _day;
	int resultDays_right = NumberOfDaysInMonths(d._month) + d._day;
	return resultDays_left - resultDays_right;
}