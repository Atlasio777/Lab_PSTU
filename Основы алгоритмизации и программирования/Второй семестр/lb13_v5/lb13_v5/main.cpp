#include <iostream>
#include "Time.h"
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// Найти минимальный элемент и добавть его на заданную позицию контейнера
void searchMin(vector<int>& s)
{
	int min = 0;
	int N;

	cout << "Найти минимальный элемент и добавть его на заданную позицию контейнера: \n";
	cout << "Введите номер позиции для добавления туда минимального элемента: ";
	cin >> N;
	// проверка на корректный ввод номера
	int size = s.size();
	if (N < 0 || N > size) return;


	
	// добавление элементов во временную структуру
	vector<int> tmp;
	int index = 0;
	// вычисление минимального элемента
	std::vector<int>::iterator result = std::min_element(s.begin(), s.end());
	min = *result;
	cout << "Минимальный элемент = " << min << endl;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++) {
		// добавление минимального элемента в указанную позицию
		if (index++ == N)
			tmp.push_back(min);
		tmp.push_back(index);// копирование элементов во временный массив
	}
	s.clear();
	s = tmp;
}

// Найти элементы, большие среднего арифметического и удалить их из контейнера
template<class T>
void remove(vector<T>& s)
{
	// вычисление среднего арифметического
	T average = 0;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++)
		average += (*it);
	average /= s.size();
	cout << "Среднее арифметическое: " << average << endl;
	// удаление по условию
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if ((*it) > average) {
			s.erase(it);
			it = s.begin();
		}
	}
}

// Каждый элемент домножить на максимальный элемент контейнера
template<class T>
void multiMax(vector<T>& s)
{
	T max = 0;
	// вычисление максимального элемента
	std::vector<int>::iterator result = std::max_element(s.begin(), s.end());
	max = *result;

	// умножение элементов на максимальный
	vector <T> tmp;
	int index = 0;
	cout << "Максимальный элемент = " << max << endl;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++) {
		tmp.push_back((*it) * max);// домножение элементов
	}
	s.clear();
	s = tmp;
}

// вывд текущего значения
void show(Time t) {
	string str = t.toString();
	cout << "Текущее время " << str << endl;
}
void show2(int val) {
	cout << val << " ";
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	

	cout << "\nЗадача 1\n";
	cout << "Контейнер - список (Time)\n";
	cout << "Ввод данных, пока не введен -1:\n";

	// объявление структуры
	list<Time> lst;

	unsigned int m, sec;// переменные для ввода с клавиатуры
	Time time;// объект класса Time

	while (true)
	{
		// ввод данных с клавиатуры
		cout << "минуты = "; cin >> m;
		if (m == -1) break;
		cout << "секунды = "; cin >> sec;
		if (sec == -1) break;
		// установка параметров в объект класса
		time.setMinutes(m);
		time.setSeconds(sec);
		lst.push_back(time);
	}
	cout << "Вывод контейнера list на экран при помощи for_each:\n";
	std::for_each(lst.begin(), lst.end(), show);
	

	


	cout << "\nЗадача 2\n";
	cout << "Адаптер контейнера - вектор\n";
	cout << "Ввод данных, пока не введен 0:\n";
	vector<int> vec;
	int index = 0;
	while (true)
	{
		// ввод значения с клавиатуры
		int value;
		cout << "[" << index++ << "] = "; cin >> value;
		// выход из бесконечного цикла
		if (value == 0) break;
		// добавление элемента в список
		vec.push_back(value);
	}

	cout << "Вывод контейнера vector на экран при помощи for_each:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// Найти минимальный элемент и добавть его на заданную позицию контейнера
	searchMin(vec);
	cout << "Вывод контейнера vector после поиска минимального занчения методом min_element:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// Найти элементы, большие среднего арифметического и удалить их из контейнера
	remove(vec);
	cout << "Вывод контейнера vector после удаления значений:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// Каждый элемент домножить на максимальный элемент контейнера
	multiMax(vec);
	cout << "Вывод контейнера vector после домножение максимального элемента:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;






	// Ассоциативный контейнер - множество
	cout << "\nЗадача 3\n";
	cout << "Ассоциативный контейнер - множество\n";
	cout << "Ввод данных, пока не введен 0:\n";

	// объявление структуры
	set<int> mySet;
	index = 0;

	while (true)
	{
		// ввод значения с клавиатуры
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// выход из бесконечного цикла
		if (value == 0) break;
		// добавление элемента в список
		mySet.insert(value);
	}

	cout << "Вывод контейнера set на экран при помощи for_each:\n";
	std::for_each(mySet.begin(), mySet.end(), show2);
	cout << endl;







	cout << endl;
	system("pause");
	return 0;
}