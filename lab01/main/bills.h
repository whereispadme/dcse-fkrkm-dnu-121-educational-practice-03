#pragma once

class bills
{
	//���������� �������� ����� ������ bills
private:
	int first;
	int second;

public:
	//����������� ��� ����������, ���������� �� ���������
	bills();
	~bills();
	
	//����������� ���� ��� �������� �������� �����
	static int sum;

	//������� ��� ����� ������
	void setFirst(int first);
	void setSecond(int second);
	
	//����� ������ bills ��� ������� �������� �����
	int summa();

	//������������� ������� ������ bills
	friend void setFirst(bills &object);
	friend void setSecond(bills &object);
};