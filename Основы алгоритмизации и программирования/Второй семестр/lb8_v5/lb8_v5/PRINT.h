#pragma once
#include "Object.h"
#include <string>
using namespace std;


//абстрактный класс
//его отличие от простого класса в том, что у него есть хоть один чистовиртуальный метод
//в таком классе может и обычный метод, который унаследуют наследники


class PRINT : public Object
{
protected:
	// конструктор класса по умолчанию
	PRINT();
	// конструктор класса с параметрами
	PRINT(string n, string a);
	// поля класса
	string name;// название
	string author;// автор

public:
	// чистовиртуальный метод
	virtual void display() = 0;
};

