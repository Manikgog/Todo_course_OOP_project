#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include "Case.h"
#include "CaseList.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // ��������� ������� �������� �� ���� ������
	
	Case c1("������� �� �++", "3.7.2023");
	c1.PrintCase();

	

	return 0;
}
