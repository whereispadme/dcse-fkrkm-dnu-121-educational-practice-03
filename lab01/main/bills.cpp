//���������� ������� ������
#include "bills.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

//���������� ������������ ������������� ����� �������� ���������� ��� ��������� �������
bills::bills() {
	this->first = 0;
	this->second = 0;
}

bills::~bills() {}

//���������� ������ ��� �������� �������� ����� 
int bills::summa() {
	int sum = this->sum+(this->first * this->second);
	return sum;
}

//������ ��� first
void bills::setFirst(int first) {

	this->first = first;

}

//������ ��� second
void bills::setSecond(int second) {

	this->second = second;

}