#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;
#pragma once

//описание прототипа класса
class Train 
{
	//закрытая часть класса
private:
	string point;
	string trainNum;
	string date;

	//открытая часть класс
public:
	//конструкторы и деструктор объектов класса
	Train();
	Train(string point, string trainNum, string date);
	~Train();

	//методы добавления и вывода данных
	void printData();
	void addData(string point, string trainNum, string date);

	//получение данных из закрытых полей класса(геттеры)
	string getPoint();
	string getTrainNum();
	string getDate();

	//перегрузка оператора =
	Train& operator = (Train object);

};