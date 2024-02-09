//реализация методов класса CandyBox
#include "CandyBox.h"

//конструктор без параметров
CandyBox::CandyBox()
{
	this->price = 0;
}

//консруктор с параметрами
CandyBox::CandyBox(std::string name, float price)
{
	this->name = name;
	this->price = price;
}

//деструктор по умолчанию
CandyBox::~CandyBox()
{
}

//сеттер для поля Name
void CandyBox::setName(std::string name)
{
	this->name = name;
}

//сеттер для поля Price
void CandyBox::setPrice(float price)
{
	this->price = price;
}

//геттер для поля Name
std::string CandyBox::getName()
{
	return this->name;
}

//геттер для поля Price
float CandyBox::getPrice()
{
	return this->price;
}