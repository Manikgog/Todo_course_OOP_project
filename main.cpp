#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include "Date.h"
#include "Case.h"
#include "CaseList.h"
#include "InputOutput.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	CaseList list;
	InputOutput i("case.bin", list);
	i.MainMenu(list);
	i.WriteToFile(list, "case.bin");

	return 0;
}
