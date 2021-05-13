#include "ClassVector.h"
#include "ERROR.h"
// конструктор класса по умолчанию
classVector::classVector()
{
	this->sizeOfVector = 0;
	this->arr = nullptr;
}

// деструктор класса
classVector::~classVector()
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

// получение колва элементов вектора
size_t classVector::operator()() const { return this->sizeOfVector; }

// оператор перегрузки []
// получение значения элемента по индексу
int classVector::operator[](const int& index)
{
	// проверка выхода индекса за пределы массива
	if (index >= this->sizeOfVector) throw MAXSIZEERROR();
	if (index < 0) throw INDEXERROR1();
	// возврат значения массива по индексу
	return this->arr[index];
}
