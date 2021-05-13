#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include "Time.h"
#include "ClassVector.h"// ����� ������
#include "ERROR.h"
using namespace std;

// ����� ��������� ������� �������� ��������������� � �� ��������
template<class T>
void removeFrom(vector<T> &v)
{
	vector<int>::iterator itVec;
	double average = 0;
	// ���������� �������� ���������������
	for (itVec = v.begin(); itVec != v.end(); itVec++)
		average += (*itVec);
	average /= v.size();

	cout << "������� �������������� = " << average << endl;
	// �������� ���������
	for (int i = 0; i < v.size(); i++)
		if (v[i] > average)
		{
			v.erase(v.begin() + i);
			i--;
		}
}

int main()
{
	setlocale(LC_ALL, "RU");


	// ������ 1
	list<float> lst;
	list<float>::iterator it;
	
	// ���� ������ � ���������
	cout << "\n������ 1 \n���� ������ � ���������-������ ���� float, ���� �� ������ ����:\n";
	int index = 0;

	
	while (true)
	{
		// ���� �������� � ����������
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// ����� �� ������������ �����
		if (value == 0) break;
		// ���������� �������� � ������
		lst.push_back(value);
	}

	cout << "����� ������ �� �����:\n";
	for (it = lst.begin(); it != lst.end(); it++)
		cout << (*it) << " ";

	// ������� ������
	lst.clear();
	





	// ������ 2
	list<Time> lst2;
	list<Time>::iterator it2;
	unsigned int m, s;// ���������� ��� ����� � ����������

	// ���� ������ � ���������
	cout << "\n\n������ 2\n���� ������ � ���������-������ ���� Time, ���� �� ������ -1:\n";
	Time time;
	while (true)
	{
		// ���� ������ � ����������
		cout << "������ = "; cin >> m;
		if (m == -1) break;
		cout << "������� = "; cin >> s;
		if (s == -1) break;
		
		// ��������� ���������� � ������ ������
		time.setMinutes(m);
		time.setSeconds(s);
		lst2.push_back(time); 
	}

	// ����� ������
	cout << "����� ������ �� �����:\n";
	for (it2 = lst2.begin(); it2 != lst2.end(); it2++)
	{
		string str = (*it2).toString();
		cout << "������� ����� " << str << endl;
	}
	// ������� ������
	lst2.clear();




	// ������ 3
	classVector vec;
	try
	{
		// ���� ������ � ������
		cout << "\n������ 3\n���� ������ � ���������: ������������������� ����� - ������.\n������� '0', ���� ����� ��������� ����.\n";
		// ����������� ����
		while (true)
		{
			cout << "��������: ";
			size_t value = 0;
			cin >> value;// ���� � ����������
			if (value == 0) break;// ����� �����
			vec.push_back(value);// ���������� �������� � ������
		}
		
		// ����� ������������ �������� ������� � ���������� ��� �� �������� ������� ����������
		int N;
		cout << "������� ������� N ��� ������� ��������: ";
		cin >> N;

		classVector v;
		int min = 0;
		// ����� ������������ �������� ��������
		for (int i = 0; i < vec(); i++)
			if (vec[i] < min || i == 0) min = vec[i];
		// ������� ������ �������� � ������� N
		for (int i = 0; i < N; i++)
			v.push_back(vec[i]);
		v.push_back(min);
		for (int i = N; i < vec(); i++)
			v.push_back(vec[i]);
		vec = v;

		// ����� ���� ��������� �������
		cout << "�������� �������:\n";
		int size = vec();
		for (int i = 0; i<size; i++)
			cout << vec[i] << " ";
	}
	catch (ERROR& err)
	{
		err.what();
	}




	
	// ������ 4
	cout << "\n������ 4\n";
	cout << "������� ���������� - ������:\n";
	vector<int> v;
	vector<int>::iterator itVec;

	// ���� ������ � ���������
	cout << "���� ������ � ������� ���������� - ������ ���� int, ���� �� ������ ����:\n";
	index = 0;
	while (true)
	{
		// ���� �������� � ����������
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// ����� �� ������������ �����
		if (value == 0) break;
		// ���������� �������� � ������
		v.push_back(value);
	}

	// ����� ��������� ������� �������� ��������������� � �� ��������
	removeFrom(v);
	cout << "����� ������ �� �����:\n";
	for (itVec = v.begin(); itVec != v.end(); itVec++)
		cout << (*itVec) << " ";

	// ������� �������
	v.clear();
	
	




	// ������ 5
	classVector vec2;
	stack<classVector> lst4;
	
	try
	{
		// ���� ������ � ������
		cout << "\n������ 5\n���� ������ � ���������: ������������������� ����� - ������, ������� ���������� ����.\n������� '0', ���� ����� ��������� ����.\n";
		// ����������� ����
		size_t max = 0;
		while (true)
		{
			cout << "��������: ";
			size_t value = 0;
			cin >> value;// ���� � ����������
			if (value == 0) break;// ����� �����
			vec2.push_back(value);// ���������� �������� � ������
			if (value > max) max = value;// ����� ������������� ��������
		}
		lst4.push(vec2);


		

		// ����� ���� ��������� �������
		cout << "������������ ������� max: " << max << endl;
		cout << "�������� �����:\n";
		for (int i = 0; i < lst4.size(); i++) {
			// ������ ������� ��������� �� ������������ ������� ����������
			classVector vv = lst4.top();
			for (int j = 0; j < vv(); j++)
				cout << vv[j] * max << endl;
			lst4.pop();// ������������ ������
		}
	}
	catch (ERROR& err)
	{
		err.what();
	}
	
	// ����� ����������� ������ ��� ������������ ������
	vec.~classVector();
	vec2.~classVector();
	cout << endl;
	return 0;
}