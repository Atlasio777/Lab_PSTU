#include <Windows.h>
#include <iostream>
#include "MAGAZIN.h"
#include "PRINT.h"
#include "VECTOR.h"
#include "DIALOG.h"

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	
	/*
	// работа с классом "журнал"
	MAGAZIN* m = new MAGAZIN();
	m->insert();
	m->display();
	
	// работа с вектором
	// запись объектов в вектор
	VECTOR v(10); // создание вектора
	Object* p = m; // установка указателя на объекта класса MAGAZIN
	v.add();// добавление объекта в вектор
	v.add();// добавление объекта в вектор
	v.show();// вывод вектора
	v.del();// удаление элемента
	cout << "размер вектора: " << v() << endl;
	*/

	// работа с классом DIALOG
	DIALOG D;
	D.execute();


	cout << endl;
	system("pause");
	return 0;
}