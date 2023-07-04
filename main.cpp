#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <cassert>
#include "Date.h"
#include "Case.h"
#include "CaseList.h"
#include "InputOutput.h"

void Test_Date()
{
	Date d1(1, 1, 1979);
	Date d2(14, 05, 1979);
	Date d3(14, 05, 1979);
	assert(true == (d1 < d2));
	assert(false == (d1 > d2));
	assert(false == (d1 == d2));
	assert(true == (d2 == d3));
}

void Test()
{
	void Test_Date();
}


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	CaseList list;
	InputOutput i("case.bin", list);
	i.MainMenu(list);
	i.WriteToFile(list, "case.bin");


	

	return 0;
}
