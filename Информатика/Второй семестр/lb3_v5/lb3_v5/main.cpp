#include <iostream>
#include "Time.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");


	Time time;// ������ ������
	unsigned int m, s;// ���������� ��� ����� � ����������
	// ���� ������ � ����������
	cout << "������ = "; cin >> m;
	cout << "������� = "; cin >> s;
	// ��������� ���������� � ������ ������
	time.setMinutes(m);
	time.setSeconds(s);
	// ����� ������
	string str = time.toString();
	cout << "������� ����� " << str << endl;

	unsigned int sec = 0;
	cout << "����� ������, ����� ������: "; cin >> s;
	Time newTime = time - s;
	str = newTime.toString();
	cout << "����� ����� " << str << endl;

	// ��������� ������� ��� ������ ������������� ���������� ���������
	if (time == newTime) cout << "����� ���������.\n";
	if (time != newTime) cout << "����� �� ���������.\n";

	cout << endl;
	system("pause");
	return 0;
}