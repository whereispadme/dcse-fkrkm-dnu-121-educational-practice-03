//Кущевский Андрей, ПЗ-19-1
/*
Кожний елемент матриці є змінною типу CandyBox (коробка цукерок) (назва цукерок, ціна коробки). 
Вивести інформацію про всі коробки цукерок, ціна яких знаходиться у вказаному діапазоні.
*/

#include "CandyBox.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

//прототипы функций для ввода значения пользователем и последующего возврата значения для инициализации, также функция проверки польз. ввода
int trueInt();
float trueFloat();
string setName();
float setPrice();


//прототипы функция для работы с двумерным массивом объектов (в качестве параметров указатель на массив[0][0], строки, столбцы)
void setCandyBox(CandyBox **temp, int rows, int cols);
void objectInRange(CandyBox **temp, int rows, int cols);
void clear(CandyBox **temp, int rows, int cols);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 0A");

	int choice = 0;

	do {
		system("cls");
		std::cout << "Введите количество строк:";
		int rows = trueInt();

		std::cout << "Введите количество столбцов:";
		int cols = trueInt();

		//Ручное создание массива объектов в C++
		//Выделяется память для объектов класса Foo в количестве count
		CandyBox **temp = (CandyBox**)operator new(sizeof(CandyBox) * rows);

		temp = new CandyBox *[cols];//массив указателей
		for (int i = 0; i < rows; i++) {

			temp[i] = new CandyBox[cols];//инициализация указателей

		}

		setCandyBox(temp, cols, rows);	 //инициализация элементов матрицы
		objectInRange(temp, cols, rows); //вызов функции для поиска объектов из диапазона
		clear(temp, cols, rows);		 //удаление элементов
		operator delete(temp);			 //удаление начального указателя

		std::cout << "Желаете продолжить работу с программой?(1 - да)(другая клавиша - выход из программы):";
		cin >> choice;

	} while (choice == 1);

	system("cls");
	system("pause");
	return 0;
}

//определение функции для проверки коректного ввода числа ввещественного числа != 0
float trueFloat() {
	float value = 0;

	while (!(cin >> value) || (value <= 0)) {
		cin.clear();
		cin.ignore(100500, '\n');
		std::cout << "Ошибка!Введите корректное значение:";
	}

	return value;
}

//определение функции для проверки коректного ввода целочисленного != 0
int trueInt() {
	int value = 0;

	while (!(cin >> value) || (value <= 0)) {
		cin.clear();
		cin.ignore(100500, '\n');
		std::cout << "Ошибка!Введите корректное значение:";
	}

	return value;
}

//определение функции для ввода названия коробки конфет -> возврат значения и инициализация переменной результатом выполнения функции
string setName() {
	
	cin.clear();
	cin.ignore(100500, '\n');
	
	std::cout << "Введите название коробки конфет:";
	string name;
	getline(cin, name);

	return name;
}

//определение функции для ввода цены за коробку конфет -> возврат значения и инициализация переменной результатом выполнения функции
float setPrice() {
	std::cout << "Введите цену:";
	float price;
	while (!(cin >> price) || (price <= 0)) {
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Ошибка!Введите корректное значение:";
	}

	return price;
}

//определние функции для создания элементов(объектов) матрицы с определёнными параметрами для конструктора
void setCandyBox(CandyBox **temp, int rows, int cols) {
	system("cls");
	string name;
	float price = 0;
	
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			cout << "Объект " << "[" << i + 1 << "][" << j + 1 << "]:" << endl;
			name = setName();
			price = setPrice();

			new(&temp[i][j]) CandyBox(name, price);
			cout << endl;
		}
	}

}

//определение функции для поиска объектов в указанном ценевом диапазоне
void objectInRange(CandyBox **temp, int rows, int cols) {
	system("cls");
	cin.clear();
	cin.ignore(100500, '\n');
	cout << "Введите ценовой диапазон:" << endl;
	cout << "Начальная цена:";
	float i1 = trueFloat();

	std::cout << "Конечная цена:";
	float i2 = trueFloat();

	cout << endl;
	int counterRangeObj = { 0 };

	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {

			//проверка, входит ли price в указанный интервал, также возможен ввод обратного интервала
			if ((temp[i][j].getPrice() >= i1 && temp[i][j].getPrice() <= i2) || (temp[i][j].getPrice() <= i1 && temp[i][j].getPrice() >= i2)) {

				cout << "+---------------------------------------+" << endl;
				cout << "|Объект " << "[" << i + 1 << "][" << j + 1 << "]:";
				printf("%-25c|", NULL);

				cout << endl << "|Название:";
				printf("%-30s", temp[i][j].getName().c_str());//c.str - формирует эту строку только и возвращает указатель на *const char
				cout << "|";
				
				cout << endl << "|Цена:";	
				printf("%-34.2f", temp[i][j].getPrice());
				cout << "|";
				cout << endl << "+---------------------------------------+" << endl;
				
				++counterRangeObj;
				cout << endl << endl;
			}
		}
	}
	if (counterRangeObj == 0) {
		cout << "Не было объектов в выбранном вами диапазоне!" << endl << endl;
	}
}

//определение функции для очистки элементов матрицы
void clear(CandyBox **temp, int rows, int cols) {
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {

			temp[i][j].~CandyBox();

		}
	}
}