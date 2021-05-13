#include "ERROR.h"
#include "VECTOR.h"


// ����������� ������ �� ���������
classVector::classVector()
{
	this->sizeOfVector = 0;
	this->arr = nullptr;
}

// ���������� ������
classVector::~classVector()
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

// ��������� ����� ��������� �������
size_t classVector::operator()() const { return this->sizeOfVector; }

// �������� ���������� []
// ��������� �������� �������� �� �������
int classVector::operator[](const int& index)
{
	// �������� ������ ������� �� ������� �������
	if (index >= this->sizeOfVector) throw MAXSIZEERROR();
	if (index < 0) throw INDEXERROR1();
	// ������� �������� ������� �� �������
	return this->arr[index];
}
