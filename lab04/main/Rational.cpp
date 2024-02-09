//реализация методов класса Rational
#include "Rational.h"

//реализация конструктора по умолчанию(без параметров)
Rational::Rational() {
	
	this->numerator = 0;
	this->denominator = 0;

}

//реализация конструктора для инициализации полей (числителя, знаменателя)
Rational::Rational(int numerator, int denominator) {
	
	this->numerator = numerator;
	this->denominator = denominator;

}

//деструктор по умолчанию
Rational::~Rational() 
{
}

//реализация перегрузки оператора сложения для класса Rational
Rational Rational::operator+(const Rational& object) {
	
	//т.к оператор определен как метод-член класса, то в параметрах не два аргумента, а один(объект из параметра), первый->текущий объект(this) 

	int a = this->numerator;
	int b = this->denominator;
	int c = object.numerator;
	int d = object.denominator;
	
	if (badValue(a, b, c, d)) {
		cout << "Некорректные значения!\n";
	}

	Rational result(a*d + b*c, b*d);

	result.reduce();

	return result;//возвращаем объект (результат)

}

//проверка на неккоректные данные
bool badValue(int a, int b, int c, int d) {
	if (a == 0 || b == 0 || c == 0 || d == 0) {
		return true;
	}
	else {
		return false;
	}
}

//возвращает наибольший общий делитель двух чисел
int NOD(int vl, int v2) {
	while (v2)
	{
		int temp = v2;
		v2 = vl % v2;
		vl = temp;
	}
	return vl;
}