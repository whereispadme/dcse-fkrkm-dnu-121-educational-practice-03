#include <string>
#pragma once

//объ€вление полей и методов класса CandyBox
class CandyBox
{
	//private пол€ класса
private:
	std::string name;
	float price;


	//public методы класса
public:
	//объ€вление конструкторов и деструктора объектов класса
	CandyBox();
	CandyBox(std::string name, float price);
	~CandyBox();
	
	//сеттеры
	void setName(std::string name);
	void setPrice(float price);

	//геттеры
	std::string getName();
	float getPrice();

};