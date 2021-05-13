#include <iostream>
#include "Time.h"
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// ����� ����������� ������� � ������� ��� �� �������� ������� ����������
void searchMin(vector<int>& s)
{
	int min = 0;
	int N;

	cout << "����� ����������� ������� � ������� ��� �� �������� ������� ����������: \n";
	cout << "������� ����� ������� ��� ���������� ���� ������������ ��������: ";
	cin >> N;
	// �������� �� ���������� ���� ������
	int size = s.size();
	if (N < 0 || N > size) return;


	
	// ���������� ��������� �� ��������� ���������
	vector<int> tmp;
	int index = 0;
	// ���������� ������������ ��������
	std::vector<int>::iterator result = std::min_element(s.begin(), s.end());
	min = *result;
	cout << "����������� ������� = " << min << endl;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++) {
		// ���������� ������������ �������� � ��������� �������
		if (index++ == N)
			tmp.push_back(min);
		tmp.push_back(index);// ����������� ��������� �� ��������� ������
	}
	s.clear();
	s = tmp;
}

// ����� ��������, ������� �������� ��������������� � ������� �� �� ����������
template<class T>
void remove(vector<T>& s)
{
	// ���������� �������� ���������������
	T average = 0;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++)
		average += (*it);
	average /= s.size();
	cout << "������� ��������������: " << average << endl;
	// �������� �� �������
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++)
	{
		if ((*it) > average) {
			s.erase(it);
			it = s.begin();
		}
	}
}

// ������ ������� ��������� �� ������������ ������� ����������
template<class T>
void multiMax(vector<T>& s)
{
	T max = 0;
	// ���������� ������������� ��������
	std::vector<int>::iterator result = std::max_element(s.begin(), s.end());
	max = *result;

	// ��������� ��������� �� ������������
	vector <T> tmp;
	int index = 0;
	cout << "������������ ������� = " << max << endl;
	for (vector <int> ::iterator it = s.begin(); it != s.end(); it++) {
		tmp.push_back((*it) * max);// ���������� ���������
	}
	s.clear();
	s = tmp;
}

// ���� �������� ��������
void show(Time t) {
	string str = t.toString();
	cout << "������� ����� " << str << endl;
}
void show2(int val) {
	cout << val << " ";
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	

	cout << "\n������ 1\n";
	cout << "��������� - ������ (Time)\n";
	cout << "���� ������, ���� �� ������ -1:\n";

	// ���������� ���������
	list<Time> lst;

	unsigned int m, sec;// ���������� ��� ����� � ����������
	Time time;// ������ ������ Time

	while (true)
	{
		// ���� ������ � ����������
		cout << "������ = "; cin >> m;
		if (m == -1) break;
		cout << "������� = "; cin >> sec;
		if (sec == -1) break;
		// ��������� ���������� � ������ ������
		time.setMinutes(m);
		time.setSeconds(sec);
		lst.push_back(time);
	}
	cout << "����� ���������� list �� ����� ��� ������ for_each:\n";
	std::for_each(lst.begin(), lst.end(), show);
	

	


	cout << "\n������ 2\n";
	cout << "������� ���������� - ������\n";
	cout << "���� ������, ���� �� ������ 0:\n";
	vector<int> vec;
	int index = 0;
	while (true)
	{
		// ���� �������� � ����������
		int value;
		cout << "[" << index++ << "] = "; cin >> value;
		// ����� �� ������������ �����
		if (value == 0) break;
		// ���������� �������� � ������
		vec.push_back(value);
	}

	cout << "����� ���������� vector �� ����� ��� ������ for_each:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// ����� ����������� ������� � ������� ��� �� �������� ������� ����������
	searchMin(vec);
	cout << "����� ���������� vector ����� ������ ������������ �������� ������� min_element:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// ����� ��������, ������� �������� ��������������� � ������� �� �� ����������
	remove(vec);
	cout << "����� ���������� vector ����� �������� ��������:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;


	// ������ ������� ��������� �� ������������ ������� ����������
	multiMax(vec);
	cout << "����� ���������� vector ����� ���������� ������������� ��������:\n";
	std::for_each(vec.begin(), vec.end(), show2);
	cout << endl;






	// ������������� ��������� - ���������
	cout << "\n������ 3\n";
	cout << "������������� ��������� - ���������\n";
	cout << "���� ������, ���� �� ������ 0:\n";

	// ���������� ���������
	set<int> mySet;
	index = 0;

	while (true)
	{
		// ���� �������� � ����������
		float value;
		cout << "[" << index++ << "] = "; cin >> value;
		// ����� �� ������������ �����
		if (value == 0) break;
		// ���������� �������� � ������
		mySet.insert(value);
	}

	cout << "����� ���������� set �� ����� ��� ������ for_each:\n";
	std::for_each(mySet.begin(), mySet.end(), show2);
	cout << endl;







	cout << endl;
	system("pause");
	return 0;
}