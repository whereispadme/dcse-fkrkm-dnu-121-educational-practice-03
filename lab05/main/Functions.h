#include "Train.h"

//вспомогательные функции
void clearStreamInput();//очистка потока ввода(мусор после cin)
void line();			//линия для вывода объектов

//функции для работы с меню программы
void printMenu();			//функция для вывода меню(no actions)
int trueChoiceMenu();		//функция для проверки ввода в меню
int showMenu();				//функция для вывода меню + пользовательский ввод(выбор пункта)
void switchMenu(int choice, Train*(&data), int& size);

//вспомогательные функции для ввода информации (временные переменные) 
string setPoint();
string setTrainNum();
string setDate();

//функции для работы с данными
void inputData(Train* (&data), int& size);			  //функция ввода данных -> передаем ссылку на массив объектов и ссылку на количество элементов для дальнейнего изменения
void printData(Train* data, int size);				  //функция вывода данных обо всех объектах
void printData(Train* data, int size, int sortAmount);//перегрузка функции PrintData для вывода объектов после сортировки
void sortData(Train* data, int size);				  //функция сортировки
void copyData(Train* buf, Train* data, int size);	  //функция для копирования объектов
void addNewData(Train* (&data), int& size);			  //функция добавления даты в конец массива объекто (избежание переопределения)
void deleteAllData(Train* (&data), int& size);		  //функция удаления всаех элементов из списка
void findData(Train* data, int size);				  //функция поиска маршрута по номеру

//работа с файлом
void saveData(Train* data, int size, string path);	  //функция сохранения данных в файл
void readData(Train* (&data), int& size, string path);//функция чтения данных из файла
void deleteDataFile(string path);					  //удаление всех данных в файле