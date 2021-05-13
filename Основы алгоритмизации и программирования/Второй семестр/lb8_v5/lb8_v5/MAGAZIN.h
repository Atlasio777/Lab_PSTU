#pragma once
#include "PRINT.h"
#include <iostream>
using namespace std;

// класс-наследник (журнал)
class MAGAZIN : public PRINT
{
private: 
	int count;// колво страниц
public:
	// конструктор класса по умолчанию
	MAGAZIN();
	// конструктор класса с параметрами
	MAGAZIN(int count, string name, string author);

	//данный оператор говорит компилятору, 
	//что нужно проконтролировать данный метод в родительском классе
	void display();

	// ввод значений атрибутов
	void insert();
};

