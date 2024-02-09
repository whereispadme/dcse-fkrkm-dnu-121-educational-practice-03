//���������� ������� ������ Rational
#include "Rational.h"

//���������� ������������ �� ���������(��� ����������)
Rational::Rational() {
	
	this->numerator = 0;
	this->denominator = 0;

}

//���������� ������������ ��� ������������� ����� (���������, �����������)
Rational::Rational(int numerator, int denominator) {
	
	this->numerator = numerator;
	this->denominator = denominator;

}

//���������� �� ���������
Rational::~Rational() 
{
}

//���������� ���������� ��������� �������� ��� ������ Rational
Rational Rational::operator+(const Rational& object) {
	
	//�.� �������� ��������� ��� �����-���� ������, �� � ���������� �� ��� ���������, � ����(������ �� ���������), ������->������� ������(this) 

	int a = this->numerator;
	int b = this->denominator;
	int c = object.numerator;
	int d = object.denominator;
	
	if (badValue(a, b, c, d)) {
		cout << "������������ ��������!\n";
	}

	Rational result(a*d + b*c, b*d);

	result.reduce();

	return result;//���������� ������ (���������)

}

//�������� �� ������������ ������
bool badValue(int a, int b, int c, int d) {
	if (a == 0 || b == 0 || c == 0 || d == 0) {
		return true;
	}
	else {
		return false;
	}
}

//���������� ���������� ����� �������� ���� �����
int NOD(int vl, int v2) {
	while (v2)
	{
		int temp = v2;
		v2 = vl % v2;
		vl = temp;
	}
	return vl;
}