#define _CRT_SECURE_NO_WARNINGS
// ������������ ����������
#include <iostream>// ������ � �������� �����/������
#include "vector.h"// ����� ������
#include "Time.h"
using namespace std;// ������������ ����





int main()
{
	// ��������� � �������
	setlocale(LC_ALL, "RU");
	// ���������� ������ ������
	classVector<int> vec;


	// ���� ������ � ������
	cout << "������� '0', ���� ����� ��������� ����\n";
	// ����������� ����
	while (true)
	{
		cout << "��������: ";
		size_t value = 0;
		cin >> value;// ���� � ����������
		if (value == 0) break;// ����� �����
		vec.push_back(value);// ���������� �������� � ������
	}

	// ����� ���� ��������� �������
	cout << "�������� �������:\n";
	cout << vec.ToString() << endl;


	// ��������� �������� �� �������
	size_t index;
	cout << "���� ������� ��� ������ ��������: ";
	cin >> index;
	cout << "[" << index << "] = " << vec[index] << endl;


	// ������� ����� ������� vec
	classVector<int> b;
	b = vec;
	
	cout << "����� ������� �������, � ������ b:\n";
	cout << b.ToString() << endl;


	cout << "������������ �������� ���� ��������:\n";
	for (int i = 0; i < vec.size(); i++)
	{
		printf("a[%d] * b[%d] = %d * %d = %d\n", i, i, vec[i], b[i], vec[i] * b[i]);
	}

	
	int n;
	cout << "������� �������� ��� �������� �� ��������� n = "; cin >> n;
	classVector<int>::myIterator i = vec.cbegin();
	i = i + n;
	cout << "���������: " << *i << endl;
	



	// ������ � ������� Time
	Time t;
	cout << "\nt: "; cin >> t;
	cout << t;

	// ��������� �������� ��� ������ Time
	Time k;
	cout << "\nk: "; cin >> k;
	Time p;
	p = t + k;
	cout << p;



	// ����� ����������� ������ ��� ������������ ������
	vec.~classVector();

	cout << endl;
	system("pause");// �������� ���� �������
	return 0;
}
