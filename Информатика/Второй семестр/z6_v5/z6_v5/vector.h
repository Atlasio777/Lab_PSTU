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
	int *arr;// объявление динамического массива
	size_t sizeOfVector;// размер массива



	// публичные методы класса
public:
	// конструктор класса по умолчанию
	classVector()
	{
		this->sizeOfVector = 0;
		this->arr = nullptr;
	}

	// деструктор класса
	~classVector()
	{
		// особождение памяти массива
		if (this->arr == nullptr)
		{
			return;
		}
		this->sizeOfVector = 0;// обнуление количества элементов
		delete[] this->arr;// особождение памяти
		this->arr = nullptr;
	}

	// добавление нового элемента в вектор
	void push_back(const int& value);

	// перевод элементов вектора в строку
	string ToString();

	// получение колва элементов вектора
	size_t size() const { return this->sizeOfVector; }

	// оператор перегрузки []
	// получение значения элемента по индексу
	int operator[](const int& index)
	{
		// проверка выхода индекса за пределы массива
		if (index >= this->sizeOfVector || index < 0)
		{
			return NULL;
		}
		// возврат значения массива по индексу
		return this->arr[index];
	}

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

		myIterator operator+(const int & n)
		{
			for(int i=0; i<n; i++)
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


// добавление нового элемента в вектор
void classVector::push_back(const int& valueTopush_back)
{
	// объявление динамического одномерного массива объектов шаблонного типа
	int* tempArr = new int[this->sizeOfVector + 1];
	// копирование элементов массива в новый массив
	if (this->sizeOfVector > 0)
	{
		for (size_t i = 0; i < this->sizeOfVector + 1; i++)
		{
			tempArr[i] = this->arr[i];
		}
	}
	// добавление нового элемента
	tempArr[this->sizeOfVector] = valueTopush_back;

	this->sizeOfVector++;// увеличим колво элементов массива на единицу
	delete[] this->arr;// освобождение памяти динамического массива
	this->arr = tempArr;// замена старого массива на новый
}

// перевод элементов вектора в строку в консоль
string classVector::ToString()
{
	if (this->sizeOfVector == 0)
	{
		return "";
	}
	stringstream resultString;
	for (classVector::myIterator i = this->cbegin(); i != this->cend(); i++)
	{
		resultString << *i << " ";
	}
	return resultString.str();
}
