#pragma once
#include "Object.h"
#include "MAGAZIN.h"
#include <iostream>
using namespace std;

class VECTOR
{
public:
	VECTOR() {}
	// ����������� ������ � �����������
	VECTOR(int);
	// ���������� ������
	~VECTOR(void);
	// ���������� �������� � ������
	void add();
	// �������� �������� �� ������� 
	void del();
	// �����������
	void show();
	int operator()();// ������ �������

protected:
	// ��������� �� ������ ������� �������
	Object** beg;
	int size;// ������
	int curr;// ������� �������
};

