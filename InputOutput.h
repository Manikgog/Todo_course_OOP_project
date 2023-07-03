/*!
\brief Класс InputOutput предназначен для обеспечения интерфейса с пользователем и проверки введённых данных
*/
#ifndef _INPUT_OUTPUT_H_
#define _INPUT_OUTPUT_H_

#include <string>
#include <fstream>
#include "CaseList.h"
#include "conio.h"

class InputOutput
{
private:
	static const int _sizeTitle = 56;
	bool CheckOverdueCase(int day, int month, int year, unsigned short currentYear, unsigned short currentMonth, unsigned short currentDay) const;
	bool IsValidDate(int day, int month, int year);
	bool isLeapYear(int year);
	char input_menu(int low, int hi, int& numAcion);
	void PrintCaseList(const CaseList& list) const;
	void PrintOneCase(const CaseList& list, int nCase) const;
	void PrintOverdueCaseList(const CaseList& list) const;
	void Draw_menu(const int numAction);
	void AddingCase(CaseList& list);
public:
	InputOutput(std::string filename, CaseList& list);
	std::vector<int> CheckDate(std::string date);
	int ReadFromFile(std::string filename, CaseList& list);
	void WriteToFile(const CaseList& list, std::string filename);
	void MainMenu(CaseList& list);
	int ChooseCaseMenu(CaseList& list, int nCase);
	int ChangeCaseMenu(int nAction, int nCase, CaseList& list);
};

#endif
