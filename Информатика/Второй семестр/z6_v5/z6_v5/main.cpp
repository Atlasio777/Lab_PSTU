#define _CRT_SECURE_NO_WARNINGS
// подключаемые библиотеки
#include <iostream>// работа с потоками ввода/вывода
#include "vector.h"// класс вектор
using namespace std;// пространство имен



int main()
{
	// кириллица в консоли
	setlocale(LC_ALL, "RU");
	// объ€вление класса вектор
	classVector vec;


	// ввод данных в вектор
	cout << "¬ведите '0', если нужно закончить ввод\n";
	// бесконечный цикл
	while (true)
	{
		cout << "значение: ";
		size_t value = 0;
		cin >> value;// ввод с клавиатуры
		if (value == 0) break;// конец ввода
		vec.push_back(value);// добавление элемента в вектор
	}

	// вывод всех элементов вектора
	cout << "Ёлементы вектора:\n";
	cout << vec.ToString() << endl;


	// получение значени€ по индексу
	size_t index;
	cout << "¬вод индекса дл€ поиска значени€: ";
	cin >> index;
	cout << "[" << index << "] = " << vec[index] << endl;


	// создаем копию вектора vec
	classVector b = vec;
	cout << " опи€ первого вектора, в вектор b:\n";
	cout << vec.ToString() << endl;


	cout << "ѕеремножение значений двух векторов:\n";
	for (int i = 0; i < vec.size(); i++)
	{
		printf("a[%d] * b[%d] = %d * %d = %d\n", i, i, vec[i], b[i], vec[i] * b[i]);
	}
	

	int n;
	cout << "¬ведите значение дл€ перехода по указателю n = "; cin >> n;
	classVector::myIterator i = vec.cbegin();
	i = i + n;
	cout << "–езультат: "<< *i << endl;


	// вызов деструктора класса дл€ освобождение пам€ти
	vec.~classVector();


	system("pause");// задержка окна консоли
	return 0;
}

