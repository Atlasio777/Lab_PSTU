#include <iostream>
#include "Time.h"
#include "classVector.h"
#include "ERROR.h"
#include <set>
using namespace std;

// ����� ����������� ������� � ������� ��� �� �������� ������� ����������
template<class T>
void searchMin(set<T> &s)
{
	T min = 0;
	int N;
	cout << "������� ����� ������� ��� ���������� ���� ������������ ��������: ";
	cin >> N;
	// �������� �� ���������� ���� ������
	int size = s.size();
	if (N < 0 || N > size) return;
	// ����� ������������ ��������
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if (it == s.begin() || min > (*it)) min = (*it);
	}

	// ���������� ��������� �� ��������� ���������
	set <T> tmp;
	int index = 0;
	cout << "����������� ������� = " << min << endl;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++){
		// ���������� ������������ �������� � ��������� �������
		if (index++ == N)
		{
			tmp.insert(min);
		}
		tmp.insert(index);// ����������� ��������� �� ��������� ������
	}
	s.clear();
	s = tmp;
}

// ����� ��������, ������� �������� ��������������� � ������� �� �� ����������
template<class T>
void remove(set<T>& s)
{
	// ���������� �������� ���������������
	T average = 0;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		average += (*it);
	average /= s.size();
	cout << "������� ��������������: " << average << endl;
	// �������� �� �������
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if ((*it) > average) {
			s.erase(it);
			it = s.begin();
		}
	}
}

// ������ ������� ��������� �� ������������ ������� ����������
template<class T>
void multiMax(set<T>& s)
{
	T max = 0;
	// ����� ������������� ��������
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		if (it == s.begin() || max < (*it))
			max = (*it);

	// ��������� ��������� �� ������������
	set <T> tmp;
	int index = 0;
	cout << "������������ ������� = " << max << endl;
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++) {
		tmp.insert((*it) * max);// ���������� ���������
	}
	s.clear();
	s = tmp;
}


int main()
{
	setlocale(LC_ALL, "RU");

	
	cout << "\n������ 1\n";
	cout << "��������� - set (float)\n";
	cout << "���� ������, ���� �� ������ ����:\n";

	// ���������� ���������
	set<float> s;
	int index = 0;

	while (true)
	{
		// ���� �������� � ����������
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// ����� �� ������������ �����
		if (value == 0) break;
		// ���������� �������� � ������
		s.insert(value);
	}


	// ����� ����������� ������� � ������� ��� �� �������� ������� ����������
	searchMin(s);
	// ����� ��������, ������� �������� ��������������� � ������� �� �� ����������
	remove(s);
	// ������ ������� ��������� �� ������������ ������� ����������
	multiMax(s);

	cout << "����� ���������� set �� �����:\n";
	for (set <float> ::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	// ������� ����������
	s.clear();



	
	
	cout << "\n������ 2\n";
	cout << "��������� - set (Time)\n";

	// ���������� ���������
	set<Time> s2;
	
	unsigned int m, sec;// ���������� ��� ����� � ����������
	Time time;// ������ ������ Time
	
	// ���� ������ � ����������
	cout << "������ = "; cin >> m;
	cout << "������� = "; cin >> sec;
	// ��������� ���������� � ������ ������
	time.setMinutes(m);
	time.setSeconds(sec);
	s2.insert(time);
	
	cout << "����� ���������� set �� �����:\n";
	for (set <Time> ::iterator it2 = s2.begin(); it2 != s2.end(); it2++) {
		time = *it2;
		string str = time.toString();
		cout << "������� ����� " << str << endl;
	}

	// ������� ����������
	s2.clear();
	



	
	// ������ 3
	cout << "\n������ 3\n";
	cout << "��������� - set (Vector)\n";
	cout << "���� ������, ���� �� ������ 0:\n";

	// ���������� ���������
	set<classVector> s3;
	classVector vec;

	try
	{
		// ���� ������ � ������
		// ����������� ����
		while (true)
		{
			cout << "��������: ";
			size_t value = 0;
			cin >> value;// ���� � ����������
			if (value == 0) break;// ����� �����
			vec.push_back(value);// ���������� �������� � ������
		}
		s3.insert(vec);

		// ����� ���� ��������� �������
		classVector vecTmp;
		cout << "����� ���������� set �� �����:\n";
		for (set <classVector> ::iterator it = s3.begin(); it != s3.end(); it++) {
			int size = (*it)();
			vecTmp = (*it);
			for (int i = 0; i < size; i++)
			{
				cout << vecTmp[i] << " ";
			}
				
		}
		// ������� �������
		vec.~classVector();
	}
	catch (ERROR& err)
	{
		err.what();
	}
	

	cout << endl;
	system("pause");
	return 0;
}