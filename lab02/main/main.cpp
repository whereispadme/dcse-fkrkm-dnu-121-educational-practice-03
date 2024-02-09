//Кущевский Андрей, ПЗ-19-1

/*
Варіант 9.
Обчислити:
1. Суму негативних елементів масиву.
2. Добуток елементів масиву, розташованих між максимальним і мінімальним елементами.
*/

#include "Array.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//прототип функции для проверки корректного ввода размера
int trueSize();

//Главная функция программы
int main() {

	setlocale(0, "rus");
	system("color 0A");

	int choice;
	int choiceDoWhile;
	do {
		system("cls");
		cout << "Типы данных:\n";
		cout << "1 - int\n";
		cout << "2 - float\n";
		cout << "3 - double\n";
		cout << endl << "Выберите тип данных, с которым желаете работать:";
		cin >> choice;

		switch (choice) {
		case 1: {
			int size = trueSize();
			Array<int> objectArray(size);

			objectArray.setArray();
			objectArray.printArray();
			objectArray.sumNegative();
			objectArray.multiMinMax();
			break;
		}
		case 2: {
			int size = trueSize();
			Array<float> objectArray(size);

			objectArray.setArray();
			objectArray.printArray();
			objectArray.sumNegative();
			objectArray.multiMinMax();
			break;
		}
		case 3: {
			int size = trueSize();
			Array<double> objectArray(size);

			objectArray.setArray();
			objectArray.printArray();
			objectArray.sumNegative();
			objectArray.multiMinMax();
			break;
		}

		default: {
			cout << std::endl <<"Ошибка!Выберите элемент из списка!";
			_getch();
			cin.clear();
			cin.sync();
			cin.ignore(100500, '\n');
			system("cls");
			main();
			break;
		}
		}

		cin.ignore(100500, '\n');
		cout << endl << endl << "Желаете продолжить роботу с программой?(1 - да, другая клавиша - завершение работы программы):";
		std::cin >> choiceDoWhile;
		
	} while (choiceDoWhile == 1);
	
	
	system("cls");
	system("pause");
	return 0;
}

//реализация функции для проверки корректного ввода размера
int trueSize() {
	system("cls");

	int size;
	cout << "Введите размер массива:";
	while (!(cin >> size) || size <= 0) {//пока cin == false или размер меньше нулевого значения

		cout << "Ошибка!Введите корректный размер массива:";

		cin.clear();
		cin.sync();
		cin.ignore(100500, '\n');
	}
	
	system("cls");
	return size;
}