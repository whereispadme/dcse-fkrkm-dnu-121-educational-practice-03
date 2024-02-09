#pragma once
//подключение необходимых для работы программы библиотек
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

bool badValue(int a, int b, int c, int d);//функция проверки на неккоректные данные
int NOD(int vl, int v2);				  //функция (наибольий общий делитель) -> сокращение дроби

class Rational {
	//закрытая часть класса
private:
	int numerator;	//числитель
	int denominator;//знаменатель

	//открытая часть класса
public:
	//конструкторы и деструктор класса
	Rational();
	Rational(int numerator, int denominator);
	~Rational();

	void reduce()
	{
		int nod = NOD(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
	}

	//перегрузка оператора сложения для класса Rational
	Rational operator+(const Rational& object);

	//дружественная функция вывода
	friend void view(const Rational& data);

};

