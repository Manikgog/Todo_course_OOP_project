#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include "Case.h"
#include "CaseList.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	
	Case c1("занятие по С++", "3.7.2023");
	c1.PrintCase();

	

	return 0;
}
