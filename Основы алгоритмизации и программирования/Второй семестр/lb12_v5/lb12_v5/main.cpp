#include <iostream>
#include "Time.h"
#include "classVector.h"
#include "ERROR.h"
#include <set>
using namespace std;

// Найти минимальный элемент и добавть его на заданную позицию контейнера
template<class T>
void searchMin(set<T> &s)
{
	T min = 0;
	int N;
	cout << "Введите номер позиции для добавления туда минимального элемента: ";
	cin >> N;
	// проверка на корректный ввод номера
	int size = s.size();
	if (N < 0 || N > size) return;
	// поиск минимального элемента
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if (it == s.begin() || min > (*it)) min = (*it);
	}

	// добавление элементов во временную структуру
	set <T> tmp;
	int index = 0;
	cout << "Минимальный элемент = " << min << endl;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++){
		// добавление минимального элемента в указанную позицию
		if (index++ == N)
		{
			tmp.insert(min);
		}
		tmp.insert(index);// копирование элементов во временный массив
	}
	s.clear();
	s = tmp;
}

// Найти элементы, большие среднего арифметического и удалить их из контейнера
template<class T>
void remove(set<T>& s)
{
	// вычисление среднего арифметического
	T average = 0;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		average += (*it);
	average /= s.size();
	cout << "Среднее арифметическое: " << average << endl;
	// удаление по условию
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if ((*it) > average) {
			s.erase(it);
			it = s.begin();
		}
	}
}

// Каждый элемент домножить на максимальный элемент контейнера
template<class T>
void multiMax(set<T>& s)
{
	T max = 0;
	// поиск максимального элемента
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		if (it == s.begin() || max < (*it))
			max = (*it);

	// умножение элементов на максимальный
	set <T> tmp;
	int index = 0;
	cout << "Максимальный элемент = " << max << endl;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++) {
		tmp.insert((*it) * max);// домножение элементов
	}
	s.clear();
	s = tmp;
}


int main()
{
	setlocale(LC_ALL, "RU");

	
	cout << "\nЗадача 1\n";
	cout << "Контейнер - set (float)\n";
	cout << "Ввод данных, пока не введен ноль:\n";

	// объявление структуры
	set<float> s;
	int index = 0;

	while (true)
	{
		// ввод значения с клавиатуры
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// выход из бесконечного цикла
		if (value == 0) break;
		// добавление элемента в список
		s.insert(value);
	}


	// Найти минимальный элемент и добавть его на заданную позицию контейнера
	searchMin(s);
	// Найти элементы, большие среднего арифметического и удалить их из контейнера
	remove(s);
	// Каждый элемент домножить на максимальный элемент контейнера
	multiMax(s);

	cout << "Вывод контейнера set на экран:\n";
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	// очистка контейнера
	s.clear();



	
	
	cout << "\nЗадача 2\n";
	cout << "Контейнер - set (Time)\n";

	// объявление структуры
	set<Time> s2;
	
	unsigned int m, sec;// переменные для ввода с клавиатуры
	Time time;// объект класса Time
	
	// ввод данных с клавиатуры
	cout << "минуты = "; cin >> m;
	cout << "секунды = "; cin >> sec;
	// установка параметров в объект класса
	time.setMinutes(m);
	time.setSeconds(sec);
	s2.insert(time);
	
	cout << "Вывод контейнера set на экран:\n";
	for (set <Time> ::iterator it2 = s2.begin(); it2 != s2.end(); it2++) {
		time = *it2;
		string str = time.toString();
		cout << "Текущее время " << str << endl;
	}

	// очистка контейнера
	s2.clear();
	



	
	// ЗАДАЧА 3
	cout << "\nЗадача 3\n";
	cout << "Контейнер - set (Vector)\n";
	cout << "Ввод данных, пока не введен 0:\n";

	// объявление структуры
	set<classVector> s3;
	classVector vec;

	try
	{
		// ввод данных в вектор
		// бесконечный цикл
		while (true)
		{
			cout << "значение: ";
			size_t value = 0;
			cin >> value;// ввод с клавиатуры
			if (value == 0) break;// конец ввода
			vec.push_back(value);// добавление элемента в вектор
		}
		s3.insert(vec);

		// вывод всех элементов вектора
		classVector vecTmp;
		cout << "Вывод контейнера set на экран:\n";
		for (set <classVector> ::iterator it = s3.begin(); it != s3.end(); it++) {
			int size = (*it)();
			vecTmp = (*it);
			for (int i = 0; i < size; i++)
			{
				cout << vecTmp[i] << " ";
			}
				
		}
		// очистка вектора
		vec.~classVector();
	}
	catch (ERROR& err)
	{
		err.what();
	}
	

	cout << endl;
	system("pause");
	return 0;
}