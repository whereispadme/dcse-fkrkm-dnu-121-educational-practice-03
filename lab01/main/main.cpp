//Кущевский Андрей, ПЗ-19-1
/*
Вариант 9.
Поле first - ціле позитивне число, номінал купюри; номінал може приймати значення 1, 2, 5, 10, 20, 50, 100, 200.
Поле second - ціле позитивне число, кількість купюр даної гідності.
Реалізувати метод summa () - обчислення грошової суми.
*/
#include "bills.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int bills::sum = 0;//сумма 0 по умолчанию

void setFirst(bills &object);
void setSecond(bills &object);

int main() {
	setlocale(0, "rus");

	int choice = 0;
	
	do {
		system("cls");
		
		//по имени
		cout << "Работа с объектом созданным по имени!" << endl;
		bills object;

		setFirst(object);
		setSecond(object);
		bills::sum = object.summa();

		_getch();
		system("cls");

		//через указатель
		cout << "Работа с объектом созданным через указатель!" << endl;
		bills objectPtr;
		bills *object_ptr = &objectPtr;
		setFirst(*object_ptr);
		setSecond(*object_ptr);
		bills::sum = object_ptr->summa();

		cout << endl << "Сумма:" << bills::sum;

		cout << endl << endl << "Желаете повторить операцию?(1 - да)(другая клавиша - выход из программы):";
		std::cin >> choice;

	} while (choice != 0);
	
	cout << endl;
	system("pause");
	return 0;
}

void setFirst(bills &object) {
	cout << "Доступные номиналы купюры:\n- 1\n- 2\n- 5\n- 10\n- 20\n- 50\n- 100\n- 200";
	cout << endl << "Выберите номинал купюры:";
	int first;
	
	while ( !(cin >> first) || (first < 0) ){
		cout << endl << "Ошибка!Введите корректное значение:";
		cin.clear();
		cin.sync();
		cin.ignore(100500, '\n');
	}
	
	switch (first) {

	case 1: {
		object.setFirst(first);
		break;
	}
	case 2: {
		object.setFirst(first);
		break;
	}

	case 5: {
		object.setFirst(first);
		break;
	}

	case 10: {
		object.setFirst(first);
		break;
	}

	case 20: {
		object.setFirst(first);
		break;
	}

	case 50: {
		object.setFirst(first);
		break;
	}
	case 100: {
		object.setFirst(first);
		break;
	}
	case 200: {
		object.setFirst(first);
		break;
	}
	
	default: {
		std::cout << "Данного номинала нет в списке!Повторите попытку!";
		_getch();
		system("cls");
		setFirst(object);
	}
	
	}
	
}

void setSecond(bills &object) {

	cout << endl << "Введите количество купюр для выбранного вами номинала:";
	int second(0);

	while (!(cin >> second) || (second<=0) ) {
		cout << endl << "Ошибка!Введите корректное значение количества:";
		cin.sync();
		cin.clear();
		cin.ignore(100500, '\n');
	}	

	object.setSecond(second);
}