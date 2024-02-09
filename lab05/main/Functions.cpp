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
	
	cout << "������� ���� ���������:" << endl;
	cout << "[1] ���� ������ � ��������" << endl;
	cout << "[2] �������� ������" << endl;
	cout << "[3] ����� �������� �� ������" << endl;
	cout << "[4] ���������� ��������� �� ������� �������" << endl;
	cout << "[5] ������� ������" << endl << endl;
	cout << "[6] ��������� � ����" << endl;
	cout << "[7] ������� ������ �� �����" << endl;
	cout << "[8] �������� ���������� �����" << endl << endl;
	cout << "[0] ����� �� ���������" << endl << endl;
	cout << "�������� ����� ����:";

}

int trueChoiceMenu() {

	int value;

	while (!(cin >> value)) {
		system("cls");
		clearStreamInput();
		cout << "������!������� ���������� ��������!";
		_getch();
		system("cls");
		printMenu();
	}

	return value;
}

int showMenu() {

	cout << "������� ���� ���������:" << endl;
	cout << "[1] ���� ������ � ��������" << endl;
	cout << "[2] �������� ������" << endl;
	cout << "[3] ����� �������� �� ������" << endl;
	cout << "[4] ���������� ��������� �� ������� �������" << endl;
	cout << "[5] ������� ������" << endl << endl;
	cout << "[6] ��������� � ����" << endl;
	cout << "[7] ������� ������ �� �����" << endl;
	cout << "[8] �������� ���������� �����" << endl << endl;
	cout << "[0] ����� �� ���������" << endl << endl;
	cout << "�������� ����� ����:";
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
			cout << "������ �����������! \n������� ���������� � ������ ���� [1]!" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			clearStreamInput();
			cout << "������� �������� �����:";
			string path;
			getline(cin, path);

			saveData(data, size, path);
		}

		break;
	}
	
	case 7: {
		system("cls");
		clearStreamInput();
		cout << "������� �������� �����:";
		string path;
		getline(cin, path);
		readData(data, size, path);
		break;
	}

	case 8: {
		system("cls");
		clearStreamInput();
		cout << "������� �������� �����:";
		string path;
		getline(cin, path);
		deleteDataFile(path);
		break;
	}

	case 0: {
		system("cls");
		cout << "���������� ������ ���������...";
		delete[] data;
		_getch();
		exit(0);
	}

	default: {
		system("cls");
		clearStreamInput();
		cout << "������!�������� ����� ���� �� ������!";
		_getch();
		system("cls");
		break;
	}

	}//end switch
}

void inputData(Train* (&data), int& size) {
	system("cls");

	//��������� ���������� ��� ����� ������
	string point;
	string trainNum;
	string date;

	int choice;
	if (size == 0) {
		cout << "������ �����������!\n������� ��������?(1 - ��), (������ ������� - ����� � ����):";
		cin >> choice;
	}
	else if (size > 0) {
		cout << "� ��������� ����������� ������!\n������� �������� � �����?(1 - ��), (������ ������� - ����� � ����):";
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
		cout << endl << "������� ���������� ��������, ������� ������� ������:";
		while (!(cin >> size) || (size <= 0)) { clearStreamInput(); cout << "������!������� ���������� ��������:"; }

		//��������������� ������� ������� ��������
		data = new Train[size];

		cout << endl;

		for (int i = 0; i < size; ++i) {
			clearStreamInput();

			cout << "������[" << i + 1 << "]:" << endl;
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
	
	cout << "����� ����������:";
	string point;
	getline(cin, point);

	return point;
}

string setTrainNum() {
		
	cout << "����� ������:";
	string trainNum;
	getline(cin, trainNum);

	return trainNum;
}

string setDate() {
	
	cout << "����:";
	string date;
	getline(cin, date);

	return date;
}

void printData(Train* data,	int size) {
	system("cls");

	if (size == 0) {
		cout << "������ �����������! \n������� ���������� � ������ ���� [1]!" << endl;
	}
	else {
		
		line();
		
		for (int i = 0; i < size; ++i) {

			cout << "|������ �� ������� [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
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
	
	cout << "���������� ����������:" << sortAmount << endl;
	cout << endl << "��������� ����������:" << endl;

	line();

	for (int i = 0; i < size; ++i) {

		cout << "|������ �� ������� [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
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
		cout << "������ �����������! \n������� ���������� � ������ ���� [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	//��������� ������ ��� ���������� + ������� ����������
	Train temp;
	int sortAmount = 0;
	
	//���������� ���������
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

		buf[i] = data[i];//��������� ���������� ��������� =
	
	}
}

void addNewData(Train* (&data), int& size) {
	
	string point;
	string trainNum;
	string date;
	
	int choice;
	int i = 0;
	do {
		//��������� ������ �������� ��� ������ ���� ��� ������������ ���������
		Train* buffer = new Train[size];

		int sizeNow = size;//������� ��������� �� ������ ������

		int newSize = ++size;//������� ��������� �����
	
		//���������� ������� copyData ��� ���������� ������ �������� ����������
		copyData(buffer, data, sizeNow);

		//�������������� ������, ��� ����� ���������� ���������
		data = new Train[newSize];

		//�������� �� ������ ����������� �������� � ��������� � ��������������� ������
		copyData(data, buffer, sizeNow);

		clearStreamInput();

		cout << "������[" << i + 1 << "]:" << endl;
		point = setPoint();
		trainNum = setTrainNum();
		date = setDate();
		
		data[sizeNow].addData(point, trainNum, date);
		cout << "________________________________________________________________________________________________________________________\n";
		
		++i;

		cout << "������� �������� ��� ���� ������� � �����?(1 - ��), (������ ������� - ����� � ����):";
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
		cout << "������ �����������! ������� ���������� � ������ ���� [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������� �������� ���������(����� ������) (1 - �����������), (������ ������� - ������� � ����):";
	cin >> choice;
	if (choice != 1) {
		clearStreamInput();
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << endl << "��������..." << endl << endl;
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
		cout << "������ �����������! ������� ���������� � ������ ���� [1]!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "������� ����� ������ ��� ������ ��������:";
	string trainNum;
	getline(cin, trainNum);

	int findAmount = 0;

	for (int i = 0; i < size; ++i) {
		if (data[i].getTrainNum() == trainNum) {

			line();
			cout << "|������ �� ������� [" << i + 1 << "]:"; printf("%-15c", NULL); cout << "|\n";
			data[i].printData();
			++findAmount;
		}
	}

	if (findAmount == 0) {
		cout << endl << "�� ���� ������� ��������� �� ���������� ������ ������!" << endl << endl;
	}
	else {
		line();
		cout << endl;
	}

	system("pause");
	system("cls");
}

void saveData(Train* data, int size, string path) {

	//����� ��� ������ � ����
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
		cout << "������ ��� ������ � ������!" << path << endl << endl;
		record.close();
		system("pause");
		system("cls");
		return;
	}

	cout << endl << "������ ������� ��������� � ����:" << path << endl << endl;
	
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

		//����������, ������� ��������� �������� (size)
		reading >> size;
		
		if (reading.peek() == EOF) {
			cout << endl << "���� ����!" << endl << endl;
			reading.close();

			system("pause");
			system("cls");
			return;
		}

		cout << endl << "������ �����...";
		cout << endl << "��������!������� ������ � ��������� ����� �������!" << endl << endl;

		data = new Train[size];

		for (int i = 0; i < size; ++i) {
			reading >> point;
			reading >> trainNum;
			reading >> date;

			data[i].addData(point, trainNum, date);
		}
	}
	else {

		cout << "������ ��� �������� �����!" << endl << endl;

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
		cout << endl << endl << "������ �������� ������ �� �����!" << endl << endl;
		del.close();
		system("pause");
		system("cls");
		return;
	}

	cout << "����������� �������� �������� � �����(����� �����) (1 - �����������), (������ ������� - ������� � ����):";
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
			cout << endl << "��������.." << endl << endl;
			del.close();
			system("pause");
			system("cls");
			return;
		}			
	}
	
}