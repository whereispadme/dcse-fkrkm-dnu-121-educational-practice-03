#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;
#pragma once

//�������� ��������� ������
class Train 
{
	//�������� ����� ������
private:
	string point;
	string trainNum;
	string date;

	//�������� ����� �����
public:
	//������������ � ���������� �������� ������
	Train();
	Train(string point, string trainNum, string date);
	~Train();

	//������ ���������� � ������ ������
	void printData();
	void addData(string point, string trainNum, string date);

	//��������� ������ �� �������� ����� ������(�������)
	string getPoint();
	string getTrainNum();
	string getDate();

	//���������� ��������� =
	Train& operator = (Train object);

};