//���������� ��������� ������� ������
#include "Array.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//����������� �� ���������
template <typename T>
Array<T>::Array() : data(nullptr), size(0) {}

//����������� � �����������
template <typename T>
Array<T>::Array(int size) {

	this->size = size;
	this->data = new T[size];

	for (int i = 0; i < size; ++i) {

		data[i] = 0;

	}
}

//���������� �������� ������
template <typename T>
Array<T>::~Array() {
	if (this->size > 0) {
		delete[] this->data;
	}
}

//������������� ��������� ������� ���������������� ������
template <typename T>
void Array<T>::setArray() {
	for (int i = 0; i < this->size; ++i) {

		cout << "[" << i + 1 << "]:";

		while (!(cin >> this->data[i])) {
			std::cout << "������!������� ���������� �������� ��� [" << i + 1 << "]:";
			cin.clear();
			cin.sync();
			cin.ignore(100500, '\n');

		}
	}
}

//����� �������� ��������� �������
template <typename T>
void Array<T>::printArray() {
	cout << endl << "�������� ������:\n";

	for (int i = 0; i < this->size; ++i) {
		cout << this->data[i] << "		";
	}

}

//����� ������������� ��������� �������
template <typename T>
void Array<T>::sumNegative() {
	T sum = { 0 };
	int negativeCounter = { 0 };
	for (int i = 0; i < this->size; ++i) {
		if (this->data[i] < 0) {
			sum += data[i];
			++negativeCounter;
		}
	}
	if (negativeCounter == 0) {
		cout << endl << "\n�� ���� ������������� ���������!";
	}
	else {
		cout << endl << "\n����� ������������� ��������� �������:" << sum;
	}
}

//������������ ��������� ����� ����������� � ������������ ����������s
template <typename T>
void Array<T>::multiMinMax() {
	T min = this->data[0];//�������� ������� �������� �� ��������� �����������
	T max = this->data[0];//�������� ������� �������� �� ��������� ������������
	
	int iMin = { 0 }; //������ ������������� ��������
	int iMax = { 0 }; //������ ������������� ��������
	
	for (int i = 0; i < this->size; ++i) {
		//����� ������������� � ��� �������
		if (this->data[i] > max) {
			max = this->data[i];
			iMax = i;
		}
		//����� ������������ � ��� �������
		if (this->data[i] < min) {
			min = this->data[i];
			iMin = i;
		}
	}

	//������������ ����� ��� ����
	T multi = { 1 };
	if (iMin < iMax) {
		for (int i = iMin+1; i < iMax; ++i) {
			multi *= this->data[i];
		}
	}
	else {
		for (int i = iMax+1; i < iMin; ++i) {
			multi *= this->data[i];
		}
	}

	cout << endl << "\n������������ ����� ����������� � ������������ ����������:" << multi;

}