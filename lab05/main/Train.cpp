#include "Train.h"
#include "Functions.h"


//����������� �� ���������(��� ����������)
Train::Train() {

	this->point = "";
	this->trainNum = "";
	this->date = "";

}

//����������� � �����������
Train::Train(string point, string trainNum, string date) {
	
	this->point = point;
	this->trainNum = trainNum;
	this->date = date;

}

//���������� �������� ������
Train::~Train() 
{
}

//����� ������ ������ �������
void Train::printData() {
	printf("|%-37c|", NULL);
	cout << endl << "|����� ����������:"; printf("%-20s", this->point.c_str()); cout << "|";
	cout << endl << "|����� ������:"; printf("%-24s", this->trainNum.c_str()); cout << "|";
	cout << endl << "|���� �����������:"; printf("%-20s", this->date.c_str()); cout << "|" << endl;

}

//����� ���������� ������
void Train::addData(string point, string trainNum, string date) {

	this->point = point;
	this->trainNum = trainNum;
	this->date = date;

}

//���������� ���������� ��������� =
Train& Train::operator= (Train object) {
	
	this->point = object.point;
	this->date = object.date;
	this->trainNum = object.trainNum;
	
	return *this;
}

//������� ��� �������� �����
string Train::getPoint() { return this->point; }

string Train::getTrainNum() { return this->trainNum; }

string Train::getDate() { return this->date; }