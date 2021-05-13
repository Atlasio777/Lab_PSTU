#pragma once
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
	int* arr;// ���������� ������������� �������
	size_t sizeOfVector;// ������ �������



	// ��������� ������ ������
public:
	// ����������� ������ �� ���������
	classVector();

	// ���������� ������
	~classVector();

	// ���������� ������ �������� � ������
	void push_back(const int& value);

	// ������� ��������� ������� � ������
	string ToString();

	// ��������� ����� ��������� �������
	size_t operator()() const;

	// �������� ���������� []
	// ��������� �������� �������� �� �������
	int operator[](const int& index);

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



