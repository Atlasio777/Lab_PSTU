#pragma once
#pragma once
// библиотеки
#include <sstream>
#include <iostream>
// пространство имен
using namespace std;


// класса вектор
class classVector {

	// приватные поля
private:
	int* arr;// объявление динамического массива
	size_t sizeOfVector;// размер массива



	// публичные методы класса
public:
	// конструктор класса по умолчанию
	classVector();

	// деструктор класса
	~classVector();

	// добавление нового элемента в вектор
	void push_back(const int& value);

	// перевод элементов вектора в строку
	string ToString();

	// получение колва элементов вектора
	size_t operator()() const;

	// оператор перегрузки []
	// получение значения элемента по индексу
	int operator[](const int& index);

	// класс - иторетор вектора
	const class myIterator
	{
	private:
		// указатель итератора
		int* pointer;

	public:
		// конструктор класса с параметром
		myIterator(int* ptr) : pointer(ptr) { }
		// перегрузка операторов
		int* operator->() { return pointer; }
		int& operator*() { return *pointer; }
		myIterator operator++(int item) { pointer++; return *this; }

		myIterator operator+(const int& n)
		{
			for (int i = 0; i < n; i++)
				pointer++;
			return *this;
		}

		bool operator!=(const myIterator& item) { return pointer != item.pointer; }
		bool operator==(const myIterator& item) { return pointer == item.pointer; }
	};

	const myIterator cbegin()
	{
		return myIterator(this->arr);
	}
	const myIterator cend()
	{
		return myIterator(this->arr + this->sizeOfVector);
	}
};



