#include <Windows.h>
#include <iostream>
#include "MAGAZIN.h"
#include "PRINT.h"
#include "VECTOR.h"
#include "DIALOG.h"

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	
	/*
	// ������ � ������� "������"
	MAGAZIN* m = new MAGAZIN();
	m->insert();
	m->display();
	
	// ������ � ��������
	// ������ �������� � ������
	VECTOR v(10); // �������� �������
	Object* p = m; // ��������� ��������� �� ������� ������ MAGAZIN
	v.add();// ���������� ������� � ������
	v.add();// ���������� ������� � ������
	v.show();// ����� �������
	v.del();// �������� ��������
	cout << "������ �������: " << v() << endl;
	*/

	// ������ � ������� DIALOG
	DIALOG D;
	D.execute();


	cout << endl;
	system("pause");
	return 0;
}