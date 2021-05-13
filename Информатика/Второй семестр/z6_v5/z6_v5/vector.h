#pragma once
// ����������
#include <sstream>
#include <iostream>
// ������������ ����
using namespace std;


// ������ ������
class classVector {

	// ��������� ����
private:
	int *arr;// ���������� ������������� �������
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
	void push_back(const int& value);

	// ������� ��������� ������� � ������
	string ToString();

	// ��������� ����� ��������� �������
	size_t size() const { return this->sizeOfVector; }

	// �������� ���������� []
	// ��������� �������� �������� �� �������
	int operator[](const int& index)
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
		int* pointer;

	public:
		// ����������� ������ � ����������
		myIterator(int* ptr) : pointer(ptr) { }
		// ���������� ����������
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


// ���������� ������ �������� � ������
void classVector::push_back(const int& valueTopush_back)
{
	// ���������� ������������� ����������� ������� �������� ���������� ����
	int* tempArr = new int[this->sizeOfVector + 1];
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
