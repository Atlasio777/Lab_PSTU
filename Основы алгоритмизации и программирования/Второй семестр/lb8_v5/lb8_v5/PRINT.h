#pragma once
#include "Object.h"
#include <string>
using namespace std;


//����������� �����
//��� ������� �� �������� ������ � ���, ��� � ���� ���� ���� ���� ���������������� �����
//� ����� ������ ����� � ������� �����, ������� ���������� ����������


class PRINT : public Object
{
protected:
	// ����������� ������ �� ���������
	PRINT();
	// ����������� ������ � �����������
	PRINT(string n, string a);
	// ���� ������
	string name;// ��������
	string author;// �����

public:
	// ���������������� �����
	virtual void display() = 0;
};

