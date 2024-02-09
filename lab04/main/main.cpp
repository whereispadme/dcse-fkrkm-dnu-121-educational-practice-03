//Кущевский Андрей,ПЗ-19-1

//главная функция программы main.cpp
#include "Rational.h"

void trueValue(int& numerator, int& denominator);//функция для проверки корректного ввода пользователя

int main() {
	setlocale(0, "rus");
	system("color E4");

	int choice;

	do {
		system("cls");
		
		int numr, denomr;

		trueValue(numr, denomr);
		Rational a(numr, denomr);
		
		trueValue(numr, denomr);
		Rational b(numr, denomr);
		
		view(a + b);
		
		cout << endl << endl << "Желаете повторить работу программы?(1 - да), (другая клавиша - выход из программы):";
		cin >> choice;
	} while (choice == 1);

	_getch();
	return 0;
}

//реализация дружественной функции вывода
void view(const Rational& data) {

	cout << "Результaт:";
	cout << data.numerator << "/" << data.denominator;

}

//реализация функции корректного ввода
void trueValue(int& numerator, int& denominator) {
	
	int value = 0;
	cout << "Введите числитель:";

	while (!(cin >> value)) {
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Ошибка!Введите корректное значение числителя:";
	}

	numerator = value;

	cout << endl << "Введите знаменатель:";

	while (!(cin >> value) || (value == 0)) {
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Ошибка!Введите корректное значение знаменателя:";
	}

	denominator = value;

	cout << endl;
}