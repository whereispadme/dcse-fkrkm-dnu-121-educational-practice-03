#include "Train.h"
#include "Functions.h"

//глобальная переменная работы с меню
int choice;

int main() {
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 0A");

	//массив данных для дальнейшей работы с ним
	int size = 0;
	Train *data = new Train[size];

	while (true) {
		choice = showMenu();
		switchMenu(choice, data, size);
	}
	
	delete[] data;	
	
	_getch();
	return 0;
}