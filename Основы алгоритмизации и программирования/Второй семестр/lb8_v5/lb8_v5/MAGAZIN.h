#pragma once
#include "PRINT.h"
#include <iostream>
using namespace std;

// �����-��������� (������)
class MAGAZIN : public PRINT
{
private: 
	int count;// ����� �������
public:
	// ����������� ������ �� ���������
	MAGAZIN();
	// ����������� ������ � �����������
	MAGAZIN(int count, string name, string author);

	//������ �������� ������� �����������, 
	//��� ����� ����������������� ������ ����� � ������������ ������
	void display();

	// ���� �������� ���������
	void insert();
};

