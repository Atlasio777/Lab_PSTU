#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include "Time.h"
#include "ClassVector.h"// класс вектор
#include "ERROR.h"
using namespace std;

// поиск элементов больших среднего арифметического и их удаления
template<class T>
void removeFrom(vector<T> &v)
{
	vector<int>::iterator itVec;
	double average = 0;
	// вычисление среднего арифметического
	for (itVec = v.begin(); itVec != v.end(); itVec++)
		average += (*itVec);
	average /= v.size();

	cout << "Среднее арифметическое = " << average << endl;
	// удаление элементов
	for (int i = 0; i < v.size(); i++)
		if (v[i] > average)
		{
			v.erase(v.begin() + i);
			i--;
		}
}

int main()
{
	setlocale(LC_ALL, "RU");


	// ЗАДАЧА 1
	list<float> lst;
	list<float>::iterator it;
	
	// ввод данных в контейнер
	cout << "\nЗАДАЧА 1 \nВвод данных в контейнер-список типа float, пока не введен ноль:\n";
	int index = 0;

	
	while (true)
	{
		// ввод значения с клавиатуры
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// выход из бесконечного цикла
		if (value == 0) break;
		// добавление элемента в список
		lst.push_back(value);
	}

	cout << "Вывод списка на экран:\n";
	for (it = lst.begin(); it != lst.end(); it++)
		cout << (*it) << " ";

	// очистка списка
	lst.clear();
	





	// ЗАДАЧА 2
	list<Time> lst2;
	list<Time>::iterator it2;
	unsigned int m, s;// переменные для ввода с клавиатуры

	// ввод данных в контейнер
	cout << "\n\nЗАДАЧА 2\nВвод данных в контейнер-список типа Time, пока не введен -1:\n";
	Time time;
	while (true)
	{
		// ввод данных с клавиатуры
		cout << "минуты = "; cin >> m;
		if (m == -1) break;
		cout << "секунды = "; cin >> s;
		if (s == -1) break;
		
		// установка параметров в объект класса
		time.setMinutes(m);
		time.setSeconds(s);
		lst2.push_back(time); 
	}

	// вывод списка
	cout << "Вывод списка на экран:\n";
	for (it2 = lst2.begin(); it2 != lst2.end(); it2++)
	{
		string str = (*it2).toString();
		cout << "Текущее время " << str << endl;
	}
	// очистка списка
	lst2.clear();




	// ЗАДАЧА 3
	classVector vec;
	try
	{
		// ввод данных в вектор
		cout << "\nЗАДАЧА 3\nВвод данных в контейнер: параметризированный класс - вектор.\nВведите '0', если нужно закончить ввод.\n";
		// бесконечный цикл
		while (true)
		{
			cout << "значение: ";
			size_t value = 0;
			cin >> value;// ввод с клавиатуры
			if (value == 0) break;// конец ввода
			vec.push_back(value);// добавление элемента в вектор
		}
		
		// поиск минимального элемента вектора и добавление его на заданную позицию контейнера
		int N;
		cout << "Введите позицию N для вставки элемента: ";
		cin >> N;

		classVector v;
		int min = 0;
		// поиск минимального значения элемента
		for (int i = 0; i < vec(); i++)
			if (vec[i] < min || i == 0) min = vec[i];
		// вставка нового элемента в позицию N
		for (int i = 0; i < N; i++)
			v.push_back(vec[i]);
		v.push_back(min);
		for (int i = N; i < vec(); i++)
			v.push_back(vec[i]);
		vec = v;

		// вывод всех элементов вектора
		cout << "Элементы вектора:\n";
		int size = vec();
		for (int i = 0; i<size; i++)
			cout << vec[i] << " ";
	}
	catch (ERROR& err)
	{
		err.what();
	}




	
	// ЗАДАЧА 4
	cout << "\nЗАДАЧА 4\n";
	cout << "Адаптер контейнера - вектор:\n";
	vector<int> v;
	vector<int>::iterator itVec;

	// ввод данных в контейнер
	cout << "Ввод данных в адаптер контейнера - вектор типа int, пока не введен ноль:\n";
	index = 0;
	while (true)
	{
		// ввод значения с клавиатуры
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// выход из бесконечного цикла
		if (value == 0) break;
		// добавление элемента в список
		v.push_back(value);
	}

	// поиск элементов больших среднего арифметического и их удаления
	removeFrom(v);
	cout << "Вывод списка на экран:\n";
	for (itVec = v.begin(); itVec != v.end(); itVec++)
		cout << (*itVec) << " ";

	// очистка вектора
	v.clear();
	
	




	// ЗАДАЧА 5
	classVector vec2;
	stack<classVector> lst4;
	
	try
	{
		// ввод данных в вектор
		cout << "\nЗАДАЧА 5\nВвод данных в контейнер: параметризированный класс - вектор, адаптер контейнера стек.\nВведите '0', если нужно закончить ввод.\n";
		// бесконечный цикл
		size_t max = 0;
		while (true)
		{
			cout << "значение: ";
			size_t value = 0;
			cin >> value;// ввод с клавиатуры
			if (value == 0) break;// конец ввода
			vec2.push_back(value);// добавление элемента в вектор
			if (value > max) max = value;// поиск максимального элемента
		}
		lst4.push(vec2);


		

		// вывод всех элементов вектора
		cout << "максимальный элемент max: " << max << endl;
		cout << "Элементы стека:\n";
		for (int i = 0; i < lst4.size(); i++) {
			// каждый элемент домножить на максимальный элемент контейнера
			classVector vv = lst4.top();
			for (int j = 0; j < vv(); j++)
				cout << vv[j] * max << endl;
			lst4.pop();// освобождение памяти
		}
	}
	catch (ERROR& err)
	{
		err.what();
	}
	
	// вызов деструктора класса для освобождение памяти
	vec.~classVector();
	vec2.~classVector();
	cout << endl;
	return 0;
}