#pragma once

class bills
{
	//объ€вление закрытых полей класса bills
private:
	int first;
	int second;

public:
	//конструктор без параметров, деструктор по умолчанию
	bills();
	~bills();
	
	//статическое поле дл€ хранени€ значени€ суммы
	static int sum;

	//сеттеры дл€ полей класса
	void setFirst(int first);
	void setSecond(int second);
	
	//метод класса bills дл€ расчЄта денежной суммы
	int summa();

	//дружественные функции класса bills
	friend void setFirst(bills &object);
	friend void setSecond(bills &object);
};