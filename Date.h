#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>
#include <chrono>
#pragma warning(disable : 4996)

class Date
{
private:
	int _day;
	int _month;
	int _year;
	bool CheckDayByMonth();
	int DaysInFebruary();
	int NumberOfDayYear(int numberOfMonth);
	int NumberOfDaysInMonths(int numberOfMonth);	// количество дней в сумме от начала года до текущего мес¤ца
	void DaysToMonthsAndDays(int result_days);

	int* StringToArr(std::string date);
	void StringToDate(std::string str);
	bool IsValidDate(int day, int month, int year);
	bool isLeapYear(int year);

public:
	Date();
	Date(int day, int month, int year);
	Date(std::string date);
	explicit Date(unsigned char day);
	Date(unsigned char day, unsigned char month);
	Date& operator-(int num);
	int operator-(const Date& d);
	Date& operator+(int num);
	void PrintDate();
};

#endif