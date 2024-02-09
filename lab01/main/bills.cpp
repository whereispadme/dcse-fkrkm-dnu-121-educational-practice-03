//Реализация методов класса
#include "bills.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

//реализация конструктора инициализация полей нулевыми значениями при созданиии объекта
bills::bills() {
	this->first = 0;
	this->second = 0;
}

bills::~bills() {}

//реализация метода для подсчёта денежной суммы 
int bills::summa() {
	int sum = this->sum+(this->first * this->second);
	return sum;
}

//сеттер для first
void bills::setFirst(int first) {

	this->first = first;

}

//сеттер для second
void bills::setSecond(int second) {

	this->second = second;

}