#include "Functions.h"
#include "Train.h"

void clearStreamInput() {
	cin.sync();
	cin.clear();
	cin.ignore(100500, '\n');
}

void line() {
	cout << "+-------------------------------------+" << endl;
}

void printMenu() {
	
	cout << "Главное меню программы:" << endl;
	cout << "[1] Ввод данных о маршруте" << endl;
	cout << "[2] Просмотр данных" << endl;
	cout << "[3] Поиск маршрута по номеру" << endl;
	cout << "[4] Сортировка маршрутов по номерам поездов" << endl;
	cout << "[5] Очистка данных" << endl << endl;
	cout << "[6] Сохранить в файл" << endl;
	cout << "[7] Считать данные из файла" << endl;
	cout << "[8] Очистить содержимое файла" << endl << endl;
	cout << "[0] Выход из программы" << endl << endl;
	cout << "Выберите пункт меню:";

}

int trueChoiceMenu() {

	int value;

	while (!(cin >> value)) {
		system("cls");
		clearStreamInput();
		cout << "Ошибка!Введите корректное значение!";
		_getch();
		system("cls");
		printMenu();
	}

	return value;
}

int showMenu() {

	cout << "Главное меню программы:" << endl;
	cout << "[1] Ввод данных о маршруте" << endl;
	cout << "[2] Просмотр данных" << endl;
	cout << "[3] Поиск маршрута по номеру" << endl;
	cout << "[4] Сортировка маршрутов по номерам поездов" << endl;
	cout << "[5] Очистка данных" << endl << endl;
	cout << "[6] Сохранить в файл" << endl;
	cout << "[7] Считать данные из файла" << endl;
	cout << "[8] Очистить содержимое файла" << endl << endl;
	cout << "[0] Выход из программы" << endl << endl;
	cout << "Выберите пункт меню:";
	int choice = trueChoiceMenu();

	return choice;
}

void switchMenu(int choice, Train*(&data), int& size) {
	switch (choice) {

	case 1: {
		inputData(data, size);
		break;
	}

	case 2: {
		printData(data, size);
		break;
	}
	
	case 3: {
		findData(data, size);
		break;
	}

	case 4: {
		sortData(data, size);
		break;
	}

	case 5: {
		deleteAllData(data, size);
		break;
	}
	
	case 6: {
		system("cls");
		
		if (size == 0) {
			cout << "Данные отсутствуют! \nВведите информацию в пункте меню [1]!" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			clearStreamInput();
			cout << "Введите название файла:";
			string path;
			getline(cin, path);

			saveData(data, size, path);
		}

		break;
	}
	
	case 7: {
		system("cls");
		clearStreamInput();
		cout << "Введите название файла:";
		string path;
		getline(cin, path);
		readData(data, size, path);
		break;
	}

	case 8: {
		system("cls");
		clearStreamInput();
		cout << "Введите название файла:";
		string path;
		getline(cin, path);
		deleteDataFile(path);
		break;
	}

	case 0: {
		system("cls");
		cout << "Завершение работы программы...";
		delete[] data;
		_getch();
		exit(0);
	}

	default: {
		system("cls");
		clearStreamInput();
		cout << "Ошибка!Выберите пункт меню из списка!";
		_getch();
		system("cls");
		break;
	}

	}//end switch
}

void inputData(Train* (&data), int& size) {
	system("cls");

	//временные переменные для ввода данных
	string point;
	string trainNum;
	string date;

	int choice;
	if (size == 0) {
		cout << "Данные отсутствуют!\nЖелаете добавить?(1 - да), (другая клавиша - выход в меню):";
		cin >> choice;
	}
	else if (size > 0) {
		cout << "В программе присутсвуют данные!\nЖелаете добавить в конец?(1 - да), (другая клавиша - выход в меню):";
		cin >> choice;
		if (choice == 1) {
			clearStreamInput();
			addNewData(data, size);
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << endl;
			system("pause");
			system("cls");
			clearStreamInput();
			return;
		}
	}

	if (choice != 1) {
		cout << endl;
		system("pause");
		system("cls");
		clearStreamInput();
		return;
	}
	else {
		cout << endl << "Введите количество объектов, которые желаете ввести:";
		while (!(cin >> size) || (size <= 0)) { clearStreamInput(); cout << "Ошибка!Введите корректное значение:"; }

		//переопределение размера массива объектов
		data = new Train[size];

		cout << endl;

		for (int i = 0; i < size; ++i) {
			clearStreamInput();

			cout << "Объект[" << i + 1 << "]:" << endl;
			point = setPoint();
			trainNum = setTrainNum();
			date = setDate();

			data[i].addData(point, trainNum, date);
			cout << "________________________________________________________________________________________________________________________\n";
		}
	}

	system("pause");
	system("cls");
}

string setPoint() {
	
	cout << "Точка назначения:";
	string point;
	getline(cin, point);

	return point;
}

string setTrainNum() {
		
	cout << "Номер поезда:";
	string trainNum;
	getline(cin, trainNum);

	return trainNum;
}

string setDate() {
	
	cout << "Дата:";
	string date;
	getline(cin, date);

	return date;
}

void printData(Train* data,	int size) {
	system("cls");

	if (size == 0) {
		cout << "Данные отсутствуют! \nВведите информацию в пункте меню [1]!" << endl;
	}
	else {
		
		line();
		
		for (int i = 0; i < size; ++i) {

			cout << "|Данные об объекте [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
			data[i].printData();
			line();
		
		}
	}

	cout << endl;
	system("pause");
	system("cls");
}

void printData(Train* data, int size, int sortAmount){
	system("cls");
	
	cout << "Количество сортировок:" << sortAmount << endl;
	cout << endl << "Результат сортировки:" << endl;

	line();

	for (int i = 0; i < size; ++i) {

		cout << "|Данные об объекте [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
		data[i].printData();
		line();

	}

	cout << endl;
	system("pause");
	system("cls");
}

void sortData(Train* data, int size) {
	system("cls");

	if (size == 0) {
		cout << "Данные отсутствуют! \nВведите информацию в пункте меню [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	//временный объект для сортировки + счетчик сортировок
	Train temp;
	int sortAmount = 0;
	
	//сортировка пузырьком
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (data[i].getTrainNum() > data[j].getTrainNum()) {

				temp = data[i];
				data[i] = data[j];
				data[j] = temp;

				++sortAmount;

			}
		}
	}
	
	printData(data, size, sortAmount);
}

void copyData(Train* buf, Train* data, int size) {
	for (int i = 0; i < size; ++i) {

		buf[i] = data[i];//сработает перегрузка оператора =
	
	}
}

void addNewData(Train* (&data), int& size) {
	
	string point;
	string trainNum;
	string date;
	
	int choice;
	int i = 0;
	do {
		//временный массив объектов для записи туда уже существующих элементов
		Train* buffer = new Train[size];

		int sizeNow = size;//сколько элементов на данный момент

		int newSize = ++size;//сколько элементов будет
	
		//используем функцию copyData для заполнения буфера текущими элементами
		copyData(buffer, data, sizeNow);

		//переопределяем память, под новое количество элементов
		data = new Train[newSize];

		//копируем из буфера сохраненные элементы и вставляем в переопределённый массив
		copyData(data, buffer, sizeNow);

		clearStreamInput();

		cout << "Объект[" << i + 1 << "]:" << endl;
		point = setPoint();
		trainNum = setTrainNum();
		date = setDate();
		
		data[sizeNow].addData(point, trainNum, date);
		cout << "________________________________________________________________________________________________________________________\n";
		
		++i;

		cout << "Желаете добавить ещё один элемент в конец?(1 - да), (другая клавиша - выход в меню):";
		cin >> choice;
		
		if (choice == 1) {
			cout << endl;
		}

		delete[] buffer;

	} while (choice == 1);
	clearStreamInput();
}

void deleteAllData(Train* (&data), int& size) {
	system("cls");
	int choice;

	if (size == 0) {
		cout << "Данные отсутствуют! Введите информацию в пункте меню [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Подтвердите удаление элементов(всего списка) (1 - подтвердить), (другая клавиша - возврат в меню):";
	cin >> choice;
	if (choice != 1) {
		clearStreamInput();
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << endl << "Удаление..." << endl << endl;
		for (int i = 0; i < size; ++i) {
			data[i].~Train();
		}
		size = 0;
		system("pause");
		system("cls");
	}

}

void findData(Train* data, int size) {
	system("cls");
	clearStreamInput();

	if (size == 0) {
		cout << "Данные отсутствуют! Введите информацию в пункте меню [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Введите номер поезда для поиска маршрута:";
	string trainNum;
	getline(cin, trainNum);

	int findAmount = 0;

	for (int i = 0; i < size; ++i) {
		if (data[i].getTrainNum() == trainNum) {

			line();
			cout << "|Данные об объекте [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
			data[i].printData();
			++findAmount;
		}
	}

	if (findAmount == 0) {
		cout << endl << "Не было найдено маршрутов по указанному номеру поезда!" << endl << endl;
	}
	else {
		line();
		cout << endl;
	}

	system("pause");
	system("cls");
}

void saveData(Train* data, int size, string path) {

	//поток для записи в файл
	ofstream record(path);

	if (record) {
		record << size << endl << endl;
		
		for (int i = 0; i < size; ++i) {
			
			record << data[i].getPoint() << endl;
			record << data[i].getTrainNum() << endl;
			record << data[i].getDate() << endl;
			
			if (i < size - 1) {
				record << endl;
			}
		}
	}
	else {
		cout << "Ошибка при работе с файлом!" << path << endl << endl;
		record.close();
		system("pause");
		system("cls");
		return;
	}

	cout << endl << "Данные успешно сохранены в файл:" << path << endl << endl;
	
	record.close();
	system("pause");
	system("cls");
	return;
}

void readData(Train* (&data), int& size, string path) {

	ifstream reading(path);

	if (reading) {
		string point;
		string trainNum;
		string date;

		//считывание, сколько элементов хранится (size)
		reading >> size;
		
		if (reading.peek() == EOF) {
			cout << endl << "Файл пуст!" << endl << endl;
			reading.close();

			system("pause");
			system("cls");
			return;
		}

		cout << endl << "Чтение файла...";
		cout << endl << "Внимание!Текущие данные в программе будут утеряны!" << endl << endl;

		data = new Train[size];

		for (int i = 0; i < size; ++i) {
			reading >> point;
			reading >> trainNum;
			reading >> date;

			data[i].addData(point, trainNum, date);
		}
	}
	else {

		cout << "Ошибка при открытии файла!" << endl << endl;

	}

	reading.close();

	system("pause");
	system("cls");
	return;
}

void deleteDataFile(string path) {
	system("cls");
	int choice;
	
	ofstream del(path);

	if (!del) {
		cout << endl << endl << "Ошибка удаления данных из файла!" << endl << endl;
		del.close();
		system("pause");
		system("cls");
		return;
	}

	cout << "Подтвердите удаление объектов в файле(всего файла) (1 - подтвердить), (другая клавиша - возврат в меню):";
	cin >> choice;

	if (choice != 1) {
		clearStreamInput();
		cout << endl;
		system("pause");
		del.close();
		system("cls");
		return;
	}
	else {
		if (del) {
			del.open(path, std::ofstream::out | std::ofstream::trunc);
			cout << endl << "Удаление.." << endl << endl;
			del.close();
			system("pause");
			system("cls");
			return;
		}			
	}
	
}