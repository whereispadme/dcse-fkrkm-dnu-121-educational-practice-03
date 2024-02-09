#include "Train.h"
#include "Functions.h"


//конструктор по умолчанию(без параметров)
Train::Train() {

	this->point = "";
	this->trainNum = "";
	this->date = "";

}

//конструктор с параметрами
Train::Train(string point, string trainNum, string date) {
	
	this->point = point;
	this->trainNum = trainNum;
	this->date = date;

}

//деструктор объектов класса
Train::~Train() 
{
}

//метод вывода данных объекта
void Train::printData() {
	printf("|%-37c|", NULL);
	cout << endl << "|Точка назначения:"; printf("%-20s", this->point.c_str()); cout << "|";
	cout << endl << "|Номер поезда:"; printf("%-24s", this->trainNum.c_str()); cout << "|";
	cout << endl << "|Дата отправления:"; printf("%-20s", this->date.c_str()); cout << "|" << endl;

}

//метод добавление данных
void Train::addData(string point, string trainNum, string date) {

	this->point = point;
	this->trainNum = trainNum;
	this->date = date;

}

//реализация перегрузки оператора =
Train& Train::operator= (Train object) {
	
	this->point = object.point;
	this->date = object.date;
	this->trainNum = object.trainNum;
	
	return *this;
}

//геттеры для закрытых полей
string Train::getPoint() { return this->point; }

string Train::getTrainNum() { return this->trainNum; }

string Train::getDate() { return this->date; }