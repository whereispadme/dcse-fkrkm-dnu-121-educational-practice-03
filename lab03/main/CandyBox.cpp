//���������� ������� ������ CandyBox
#include "CandyBox.h"

//����������� ��� ����������
CandyBox::CandyBox()
{
	this->price = 0;
}

//���������� � �����������
CandyBox::CandyBox(std::string name, float price)
{
	this->name = name;
	this->price = price;
}

//���������� �� ���������
CandyBox::~CandyBox()
{
}

//������ ��� ���� Name
void CandyBox::setName(std::string name)
{
	this->name = name;
}

//������ ��� ���� Price
void CandyBox::setPrice(float price)
{
	this->price = price;
}

//������ ��� ���� Name
std::string CandyBox::getName()
{
	return this->name;
}

//������ ��� ���� Price
float CandyBox::getPrice()
{
	return this->price;
}