#include "InputOutput.h"
#include "CaseList.h"


// метод для проверки - не прошла ли уже введённая пользователем дата
bool InputOutput::CheckOverdueCase(int day, int month, int year, unsigned short currentYear, unsigned short currentMonth, unsigned short currentDay) const
{
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

// метод для валидности введённой пользователем даты
bool InputOutput::IsValidDate(int day, int month, int year)
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

	if (!CheckOverdueCase(day, month, year, currentYear, currentMonth, currentDay))
		return false;

	return true;
}

// метод для проверки високосности года
bool InputOutput::isLeapYear(int year) {
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

// метод для интерпретации нажатия клавиш в возвращаемое значение для изменения вида меню
char InputOutput::input_menu(int low, int hi, int& numAcion) {
	int c1 = 0;
	int c2 = 0;
	int c = c1 + c2;
	do {
		bool f = false;
		if (_kbhit()) {
			c1 = _getch();
			if (c1 == 13) {
				f = true;
				break;
			}
			c2 = _getch();
			c = c1 + c2;
			switch (c) {
			case 296:
				--numAcion;
				break;
			case 304:
				++numAcion;
				break;
			}
		}

	} while (c1 != 13 && c != 296 && c != 304);
	if (numAcion < low)
		numAcion = hi;
	else if (numAcion > hi)
		numAcion = low;
	return (char)c1;
}



// метод для вывода на печать списка просроченных дел
void InputOutput::PrintOverdueCaseList(CaseList& list) const
{
	if (!list.GetCaseList().size())	// при пустом списке выходим из функции
		return;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	unsigned short currentYear = 1900 + ltm->tm_year;
	unsigned short currentMonth = 1 + ltm->tm_mon;
	unsigned short currentDay = ltm->tm_mday;
	bool is_first = true;
	for (size_t i = 0; i < list.Size(); i++)
	{
		if (list.GetCaseList().at(i)->GetDate() < Date(currentDay, currentMonth, currentYear))
		{
			if (is_first)
				std::cout << "\x1b[33mСписок просроченных задач : \x1b[0m\n";
			is_first = false;
			list.PrintCaseByIndex(i);
		}
	}
}

// метод для вывода на экран основного меню
void InputOutput::Draw_menu(const int numAction) {
	switch (numAction) {

	case 1:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\n\x1b[36mДобавление нового дела.\x1b[0m\n\
Выбор дела.\n\
Очистка всего списка дел.\n\
Сортировка списка.\n\
Выход из программы.\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
		break;
	case 2:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\nДобавление нового дела.\n\
\x1b[36mВыбор дела.\x1b[0m\n\
Очистка всего списка дел.\n\
Сортировка списка.\n\
Выход из программы.\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
		break;
	case 3:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\nДобавление нового дела.\n\
Выбор дела.\n\
\x1b[36mОчистка всего списка дел.\x1b[0m\n\
Сортировка списка.\n\
Выход из программы.\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
		break;
	case 4:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\nДобавление нового дела.\n\
Выбор дела.\n\
Очистка всего списка дел.\n\
\x1b[36mСортировка списка.\x1b[0m\n\
Выход из программы.\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
		break;
	case 5:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\nДобавление нового дела.\n\
Выбор дела.\n\
Очистка всего списка дел.\n\
Сортировка списка.\n\
\x1b[36mВыход из программы.\x1b[0m\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
		break;
	default:
		std::cout << "\n\x1b[33mВарианты действий:\x1b[0m\nДобавление нового дела.\n\
Выбор дела.\n\
Очистка всего списка дел.\n\
Сортировка списка.\n\
Выход из программы.\n\
\n\
Для выбора пункта меню пользуйтесь стрелками вверх и вниз на клавиатуре и кнопкой ВВОД.\n";
	}
}

// метод для интерфейса добавления нового дела
void InputOutput::AddingCase(CaseList& list)
{
	char* title = new char[this->_sizeTitle] {};
	std::string date;							// string object for entering the date
	std::string day;							// string object for recording and subsequent processing of the day
	std::string month;							// string object for recording and subsequent processing of the month
	std::string year;							// string object for recording and subsequent processing of the year
	std::cout << "\x1b[33mВведите название нового мероприятия -> \x1b[0m";
	std::string str;							// string object for recording name of the case
	std::getline(std::cin, str);
	for (int i = 0; i < str.length(); i++) {	// converting a string object to a char array
		if (i == this->_sizeTitle)			// protection against going beyond the boundaries of the char array
			break;
		title[i] = str[i];
	}
	std::vector<int> vec_date;
	
	
	
		do {
			std::cout << "\x1b[33mВведите дату в формате ДД.ММ.ГГГГ -> \x1b[0m";
			std::getline(std::cin, date);
			vec_date = CheckDate(date);
		} while (!vec_date.at(3));
		
	Case newCase( title, date );
	
	list.AddCase(newCase);
	std::cout << "\x1b[32mНовое дело добавлено в список.\x1b[0m\n";

	system("pause");
	system("cls");


	delete[] title;
	
}

// конструктор, который обеспечивает чтение списка дел из файла
InputOutput::InputOutput(std::string filename, CaseList& list)
{
	ReadFromFile(filename, list);
}

// метод для проверки, введённой даты
std::vector<int> InputOutput::CheckDate(std::string date)
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
	// результат функции проверки даты выводится в виде вектора result с данными даты и элементом, 
	// характеризующим правильность даты (0 - дата введена неверно, 1 - дата введена верно)
	std::vector<int> result{ arr[0], arr[1], arr[2], 0 }; 
	if (!IsValidDate(arr[0], arr[1], arr[2]))
		return result;
	
	result.at(3) = 1;
	return result;

}

// метод для чтения списка дел из бинарного файла
int InputOutput::ReadFromFile(std::string filename, CaseList& list)
{
	CaseList tmp;

	std::ifstream fin; // creating an ifstream object to read data from a file

	fin.open(filename, std::ios_base::in | std::ios_base::binary);
	// writing cases from a file to the listCases array
	// запись дел из файла в массив listCases
	if (!fin.is_open()) {
		std::cout << "Ошибка открытия файла.\n";
		return -2;
	}
	else {
		//std::cout << "Файл открыт.\n";
		struct C4se
		{
			char title[_sizeTitle]{};
			Date date;
		};
		C4se c4se;
		while (fin.read((char*)&c4se, sizeof(C4se)))
		{
			list.AddCase(Case(c4se.title, c4se.date));
		}
	}

	fin.close();

	return 0;
}

// метод для записи списка дел в бинарный файл
void InputOutput::WriteToFile(const CaseList& list, std::string filename)
{
	std::ofstream fout;
	fout.open(filename, std::ios_base::out | std::ios_base::binary);

	if (!fout.is_open()) {
		std::cout << "Невозможно открыть файл.\n";
		return;
	}

	struct C4se
	{
		char title[_sizeTitle]{};
		Date date;
	};
	
	for (int j = 0; j < list.GetCaseList().size(); ++j)
	{
		C4se c4se;
		int lengthOfTitleString = list.GetCaseList().at(j)->GetTitle().size();
		for (int i = 0; i < lengthOfTitleString; ++i)
		{
			c4se.title[i] = list.GetCaseList().at(j)->GetTitle().at(i);
		}
		c4se.date = list.GetCaseList().at(j)->GetDate();

		fout.write((char*)&c4se, sizeof(C4se));
	}

	fout.close();
	return;
}

// метод обеспечивающий интерфейс главного меню
void InputOutput::MainMenu(CaseList& list)
{
	bool exit = true;	// variable-flag for exiting the program / переменна¤-флаг дл¤ выхода из программы
	//bool flagDelete = false;	// flag indicating that deleting an array of listCases[] (delete[] listCases;) done
	// флаг, показывающий, что удаление массива listCases[] (delete[] listCases;) выполнено
	int numAction = 0;	// variable for storing an action option from the menu selected by the user
	// переменна¤ дл¤ хранени¤ варианта действи¤ из меню, выбранного пользователем

	char answer{ 'н' };
	do {


		do {
			system("cls");
			std::cout << "\x1b[32mПрограмма дл¤ создания списка запланированных дел.\x1b[0m\n";
			PrintOverdueCaseList(list);

			Draw_menu(numAction);
		} while (input_menu(1, 5, numAction) != '\r');

		int nCase = 0;				// variable for storing the number of the selected case / переменна¤ дл¤ хранени¤ номера выбранного дела
		int nAction = 0;			// variable for storing the action number on the selected case / переменная для хранения номера действия над выбранным делом
		switch (numAction) {

		case 1:
			// adding a case to the list
			// добавление дела в список
			AddingCase(list);

			break;
		case 2:
			// modification, deletion, mark of completion
			// изменение, удаление, отметка о выполнении
			
			do {
				do {
					// выбор дела из списка
					system("cls");
					if (1 == ChooseCaseMenu(list, nCase)) { // если список пуст
						numAction = 1;
						break;
					}
				} while ('\r' != input_menu(0, list.Size(), nCase));

				system("cls");

				// exit to the main menu when selecting "Назад"
				// выход в главное меню при выборе пункта "Назад"
				if (nCase < 0 || nCase >= list.GetCaseList().size()) {
					numAction = 1;
					break;
				}
				// choosing an action with a selected case
				// выбор действи¤ с выбранным делом
				
				ChangeCaseMenu(nAction, nCase, list);
				
			} while (nAction == 1);
			
			system("cls");
			break;
		case 3:
			// clearing the entire list
			// очистка всего списка
			system("cls");
			
			std::cout << "Вы уверены, что хотите удалить все задачи (д/н)? ";
			std::cin >> answer;
			if (answer == 'д' || answer == 'y')
			{
				list.Clear();
				if (!list.GetCaseList().size())
					std::cout << "Список дел очищен!\n";
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			// return to the main menu with an empty to-do list
			// возврат в главное меню при пустом списке дел
			if (!list.GetCaseList().size()) {
				numAction = 1;
				break;
			}
			SortByDate(list);
			list.PrintList();
			system("pause");
			system("cls");
			break;
		case 5:
			exit = false;
			break;
		}
	} while (exit);
}

// метод для вывода на экран меню выбора дела из списка
int InputOutput::ChooseCaseMenu(CaseList& list, int nCase)
{
	size_t listSize = list.Size();
	if (listSize == 0) {
		std::cout << "Запланированных дел нет. Список пуст.\n";
		return 1;
	}
	else {
		
		
		std::cout << "\x1b[33mСписок запланированных дел:\x1b[0m\n";
		if (nCase >= 0 && nCase < listSize) {
			for (int i = 0; i < listSize; ++i) {
				if (nCase == i)
				{
					std::cout << "\x1b[36m";
					list.PrintCaseByIndex(i);
					std::cout << "\x1b[0m";
				}
				else
					list.PrintCaseByIndex(i); std::cout << std::endl;
			}
			std::cout << "Назад\n";
		}
		else {
			list.PrintList();
			std::cout << "\x1b[36mНазад\x1b[0m\n";
		}
	}
	return 0;
}

// метод для вывода на экран меню выбора действий с выбранным делом и выполняющий эти действия
int InputOutput::ChangeCaseMenu(int nAction, int numCase, CaseList& list)
{
	if (numCase < 0) numCase = 0;
	int num = 1;
	do {

		switch (num)
		{
		case 1:
			system("cls");
			list.PrintCaseByIndex(numCase);
			std::cout << "\n\x1b[36mИзменить название\x1b[0m\n";
			std::cout << "Изменить дату\n";
			std::cout << "Удалить дело\n";
			std::cout << "Назад\n";
			break;
		case 2:
			system("cls");
			list.PrintCaseByIndex(numCase);
			std::cout << "\nИзменить название\n";
			std::cout << "\x1b[36mИзменить дату\x1b[0m\n";
			std::cout << "Удалить дело\n";
			std::cout << "Назад\n";
			break;
		case 3:
			system("cls");
			list.PrintCaseByIndex(numCase);
			std::cout << "\nИзменить название\n";
			std::cout << "Изменить дату\n";
			std::cout << "\x1b[36mУдалить дело\x1b[0m\n";
			std::cout << "Назад\n";
			break;
		case 4:
			system("cls");
			list.PrintCaseByIndex(numCase);
			std::cout << "\nИзменить название\n";
			std::cout << "Изменить дату\n";
			std::cout << "Удалить дело\n";
			std::cout << "\x1b[36mНазад\x1b[0m\n";
		default:
			break;
		}
	} while (input_menu(1, 4, num) != '\r');
	std::string answer;
	std::string date;
	std::vector<int> vec_date;
	switch (num) {
	case 1:
		std::cout << "\x1b[33mВведите новое название дела: \x1b[0m";
		answer = "";
		std::getline(std::cin, answer);
		break;
	case 2:
		do {
			std::cout << "\x1b[33mВведите дату в формате ДД.ММ.ГГГГ -> \x1b[0m";
			std::getline(std::cin, date);
			vec_date = CheckDate(date);
		} while (!vec_date.at(3));
		
		break;
	case 3:
		if (!list.GetCaseList().size())
		{
			system("cls");
			std::cout << "Cписок дел пуст. Удалять нечего.\n";
			system("pause");
		}
		else {
			std::cout << "\x1b[33mВы уверены, что хотите удалить дело (д/н): \x1b[0m";
			std::cin.ignore();
			std::cin >> answer;
			if (answer[0] == 'y' || answer[0] == 'д')
			{
				if(list.DeleteCase(numCase))
					std::cout << "Дело удалено из списка.\n";
				else
					std::cout << "Дело НЕ удалено из списка.\n";
			}
		}
		break;
	case 4:
		return 1;
	}
	if (num == 1)
	{
		Case newCase(answer, list.GetCaseList().at(numCase)->GetDate());
		if (list.DeleteCase(numCase))
			list.AddCase(newCase);
		else
			std::cout << "Ошибка удаления!\n";
	}
	else if (num == 2)
	{
		Case newCase(list.GetCaseList().at(numCase)->GetTitle(), date);
		if (list.DeleteCase(numCase))
			list.AddCase(newCase);
		else
			std::cout << "Ошибка удаления!\n";
	}
	return 0;
}

void InputOutput::SortByDate(CaseList& list)
{
	list.SortListByDate();
}