#include <iostream>
#include "Time.h"
using namespace std;

// ������� ��� ������, ��� �������� ����� ������ ������� ��������
Time* removeWhere(Time *&time, int &size)
{
	// ������� �����
	// ���� ������ � ����������
	Time t;
	unsigned int m, s;// ���������� ��� ����� � ����������
	cout << "�������� �������, ������� ���������:\n";
	cout << "������ = "; cin >> m;
	cout << "������� = "; cin >> s;
	// ��������� ���������� � ������ ������
	t.setMinutes(m);
	t.setSeconds(s);

	Time *tmp = new Time[size];// ��������� ������ ��� �������� ���������
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i] < t) {
			// �������� �� ��������� ������� �� ��������� ������
			tmp[index++] = time[i];
		}
	}
	// ��������� �� ���������� ������� ��������, ������� �������� ����� ��������
	time = tmp;
	size = index;
	return time;
}


// �������� � ������� ����� ������ � ������� N
void addRecords(Time *&time, int& size)
{
	cout << "�������� � ������� ����� ������ � ������� N:\n";
	unsigned int m, s;// ���������� ��� ����� � ����������
	int N = 0;
	int K = 0;
	cout << "N = "; cin >> N;
	cout << "K = "; cin >> K;
	N--; // �������� �� ���������� � ����
	// ������ ��� ����������
	Time tmp[1000];
	int index = 0;
	// �������� �������� �� N
	for (index = 0; index <= N; index++)
		tmp[index] = time[index];


	// ��������� ����� K �������
	for (int i = 0; i < K; i++) {
		// ���� ������ � ����������
		cout << "������ = "; cin >> m;
		cout << "������� = "; cin >> s;
		// ��������� ���������� � ������ ������
		tmp[index + i].setMinutes(m);
		tmp[index + i].setSeconds(s);
		if (i + 1 == K) index += i + 1;
	}

	// ��������� ���������� ������ � ������� �������
	for (int i=N+1; i < size; i++)
		tmp[index++] = time[i];

	time = tmp;
	size = index;
}


int main()
{
	setlocale(LC_ALL, "RU");

	int index = 0;// ������ ��� ������� ��������
	Time *time = new Time[1000];// ������ �������� ������
	unsigned int m, s;// ���������� ��� ����� � ����������

	// ���� ������
	cout << "���� ������:\n";
	int size = 0;
	cout << "����� �������� ��������: "; cin >> size;
	for (int i = 0; i < size; i++)
	{
		// ���� ������ � ����������
		cout << "������ = "; cin >> m;
		cout << "������� = "; cin >> s;
		// ��������� ���������� � ������ ������
		time[index + i].setMinutes(m);
		time[index + i].setSeconds(s);
		if (i + 1 == size) index += i+1;
	}
	
	
	// ����� ������
	for (int i = 0; i < index; i++)
		cout << "�����: " << time[i].toString() << endl;
	
	

	// ��������� ��� ������ � �������� ��������� �� 1 ��� 30 ���
	Time tmp(1,30);
	for (int i = 0; i < index; i++)
		time[i] = time[i] + tmp;
		
	// ����� ������
	cout << "\n������ ����� ����������� 1 ��� 30 ���:\n";
	for (int i = 0; i < index; i++)
		cout << "�����: " << time[i].toString() << endl;
	


	// �������� � ������� ����� ������ � ������� N
	addRecords(time, index);
	cout << "\n������ ����� ���������� K �������:\n";
	for (int i = 0; i < index; i++)
		cout << "�����: " << time[i].toString() << endl;
	
	
	
	// ������� ��� ������, ��� �������� ����� ������ ������� ��������
	time = removeWhere(time, index);

	// ����� ������
	cout << "\n������ ����� ��������:\n";
	for (int i = 0; i < index; i++)
		cout << "�����: " << time[i].toString() << endl;
	

	cout << endl;
	system("pause");
	return 0;
}