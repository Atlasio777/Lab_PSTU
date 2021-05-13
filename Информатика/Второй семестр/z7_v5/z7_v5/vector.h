#pragma once
// ����������
#include <iostream>
#include <sstream>
// ������������ ����
using namespace std;


// ������ ������ ������
template <class templType>
class classVector {

	// ��������� ����
private:
	templType* arr;//���������� ������������� �������
	size_t sizeOfVector;// ������ �������



	// ��������� ������ ������
public:
	// ����������� ������ �� ���������
	classVector()
	{
		this->sizeOfVector = 0;
		this->arr = nullptr;
	}

	// ���������� ������
	~classVector()
	{
		// ����������� ������ �������
		if (this->arr == nullptr)
		{
			return;
		}
		this->sizeOfVector = 0;// ��������� ���������� ���������
		delete[] this->arr;// ����������� ������
		this->arr = nullptr;
	}

	// ���������� ������ �������� � ������
	void push_back(const templType& value);

	// ������� ��������� ������� � ������
	string ToString();

	// ��������� ����� ��������� �������
	size_t size() const { return this->sizeOfVector; }

	// �������� ���������� []
	// ��������� �������� �������� �� �������
	templType operator[](const int& index)
	{
		// �������� ������ ������� �� ������� �������
		if (index >= this->sizeOfVector || index < 0)
		{
			return NULL;
		}
		// ������� �������� ������� �� �������
		return this->arr[index];
	}

	// ����� - �������� �������
	const class myIterator
	{
	private:
		// ��������� ���������
		templType* pointer;

	public:
		// ����������� ������ � ����������
		myIterator(templType* ptr) : pointer(ptr) { }
		// ���������� ����������
		templType* operator->() { return pointer; }
		templType& operator*() { return *pointer; }
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


// ���������� ������ �������� � ������
template <class templType>
void classVector<templType>::push_back(const templType& valueTopush_back)
{
	// ���������� ������������� ����������� ������� �������� ���������� ����
	templType* tempArr = new templType[this->sizeOfVector + 1];
	// ����������� ��������� ������� � ����� ������
	if (this->sizeOfVector > 0)
	{
		for (size_t i = 0; i < this->sizeOfVector + 1; i++)
		{
			tempArr[i] = this->arr[i];
		}
	}
	// ���������� ������ ��������
	tempArr[this->sizeOfVector] = valueTopush_back;

	this->sizeOfVector++;// �������� ����� ��������� ������� �� �������
	delete[] this->arr;// ������������ ������ ������������� �������
	this->arr = tempArr;// ������ ������� ������� �� �����
}


// ������� ��������� ������� � ������ � �������
template <class templType>
string classVector<templType>::ToString()
{
	if (this->sizeOfVector == 0)
	{
		return "";
	}
	stringstream resultString;
	for (classVector<templType>::myIterator i = this->cbegin(); i != this->cend(); i++)
	{
		resultString << *i << " ";
	}
	return resultString.str();
}

