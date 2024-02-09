#include <string>
#pragma once

//���������� ����� � ������� ������ CandyBox
class CandyBox
{
	//private ���� ������
private:
	std::string name;
	float price;


	//public ������ ������
public:
	//���������� ������������� � ����������� �������� ������
	CandyBox();
	CandyBox(std::string name, float price);
	~CandyBox();
	
	//�������
	void setName(std::string name);
	void setPrice(float price);

	//�������
	std::string getName();
	float getPrice();

};