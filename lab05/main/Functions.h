#include "Train.h"

//��������������� �������
void clearStreamInput();//������� ������ �����(����� ����� cin)
void line();			//����� ��� ������ ��������

//������� ��� ������ � ���� ���������
void printMenu();			//������� ��� ������ ����(no actions)
int trueChoiceMenu();		//������� ��� �������� ����� � ����
int showMenu();				//������� ��� ������ ���� + ���������������� ����(����� ������)
void switchMenu(int choice, Train*(&data), int& size);

//��������������� ������� ��� ����� ���������� (��������� ����������) 
string setPoint();
string setTrainNum();
string setDate();

//������� ��� ������ � �������
void inputData(Train* (&data), int& size);			  //������� ����� ������ -> �������� ������ �� ������ �������� � ������ �� ���������� ��������� ��� ����������� ���������
void printData(Train* data, int size);				  //������� ������ ������ ��� ���� ��������
void printData(Train* data, int size, int sortAmount);//���������� ������� PrintData ��� ������ �������� ����� ����������
void sortData(Train* data, int size);				  //������� ����������
void copyData(Train* buf, Train* data, int size);	  //������� ��� ����������� ��������
void addNewData(Train* (&data), int& size);			  //������� ���������� ���� � ����� ������� ������� (��������� ���������������)
void deleteAllData(Train* (&data), int& size);		  //������� �������� ����� ��������� �� ������
void findData(Train* data, int size);				  //������� ������ �������� �� ������

//������ � ������
void saveData(Train* data, int size, string path);	  //������� ���������� ������ � ����
void readData(Train* (&data), int& size, string path);//������� ������ ������ �� �����
void deleteDataFile(string path);					  //�������� ���� ������ � �����