#pragma once
//����������� ����������� ��� ������ ��������� ���������
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

bool badValue(int a, int b, int c, int d);//������� �������� �� ������������ ������
int NOD(int vl, int v2);				  //������� (��������� ����� ��������) -> ���������� �����

class Rational {
	//�������� ����� ������
private:
	int numerator;	//���������
	int denominator;//�����������

	//�������� ����� ������
public:
	//������������ � ���������� ������
	Rational();
	Rational(int numerator, int denominator);
	~Rational();

	void reduce()
	{
		int nod = NOD(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
	}

	//���������� ��������� �������� ��� ������ Rational
	Rational operator+(const Rational& object);

	//������������� ������� ������
	friend void view(const Rational& data);

};

