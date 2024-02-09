//реализация шаблонных методов класса
#include "Array.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//конструктор по умолчанию
template <typename T>
Array<T>::Array() : data(nullptr), size(0) {}

//конструктор с параметрами
template <typename T>
Array<T>::Array(int size) {

	this->size = size;
	this->data = new T[size];

	for (int i = 0; i < size; ++i) {

		data[i] = 0;

	}
}

//деструктор объектов класса
template <typename T>
Array<T>::~Array() {
	if (this->size > 0) {
		delete[] this->data;
	}
}

//инициализация элементов массива пользовательским вводом
template <typename T>
void Array<T>::setArray() {
	for (int i = 0; i < this->size; ++i) {

		cout << "[" << i + 1 << "]:";

		while (!(cin >> this->data[i])) {
			std::cout << "Ошибка!Введите корректное значение для [" << i + 1 << "]:";
			cin.clear();
			cin.sync();
			cin.ignore(100500, '\n');

		}
	}
}

//вывод текущего состояния массива
template <typename T>
void Array<T>::printArray() {
	cout << endl << "Введённый массив:\n";

	for (int i = 0; i < this->size; ++i) {
		cout << this->data[i] << "		";
	}

}

//сумма отрицательных элементов массива
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
		cout << endl << "\nНе было отрицательных элементов!";
	}
	else {
		cout << endl << "\nСумма отрицательных элементов массива:" << sum;
	}
}

//произведение элементов между минимальным и максимальным элементамиs
template <typename T>
void Array<T>::multiMinMax() {
	T min = this->data[0];//значение первого элемента по умолчанию минимальное
	T max = this->data[0];//значение первого элемента по умолчанию максимальное
	
	int iMin = { 0 }; //индекс минмиамльного элемента
	int iMax = { 0 }; //индекс максимального элемента
	
	for (int i = 0; i < this->size; ++i) {
		//поиск максимального и его индекса
		if (this->data[i] > max) {
			max = this->data[i];
			iMax = i;
		}
		//поиск минимального и его индекса
		if (this->data[i] < min) {
			min = this->data[i];
			iMin = i;
		}
	}

	//произведение между мин макс
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

	cout << endl << "\nПроизведение между минимальным и максимальным элементами:" << multi;

}