#pragma once
#include "Object.h"
#include "MAGAZIN.h"
#include <iostream>
using namespace std;

class VECTOR
{
public:
	VECTOR() {}
	// конструктор класса с параметрами
	VECTOR(int);
	// деструктор класса
	~VECTOR(void);
	// добавление элемента в вектор
	void add();
	// удаление элемента из вектора 
	void del();
	// отображение
	void show();
	int operator()();// размер вектора

protected:
	// указатель на первый элемент вектора
	Object** beg;
	int size;// размер
	int curr;// текущая позиция
};

