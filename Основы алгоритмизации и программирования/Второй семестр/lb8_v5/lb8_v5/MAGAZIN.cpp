#include "MAGAZIN.h"



// ����������� ������ �� ���������
MAGAZIN::MAGAZIN()
{
	this->count = 0;
}

// ����������� ������
MAGAZIN::MAGAZIN(int count, string name, string author) : PRINT(name, author)
{
	this->count = count;
}

// ������ �������� ������� �����������,
// ��� ����� ����������������� ������ ����� � ������������ ������
void MAGAZIN::display()
{
	cout << "������ ������ �����\n";
	cout << "�������� �������: " << this->name << endl;
	cout << "����� �������: " << this->author << endl;
	cout << "����� ��.: " << this->count << endl;
}

// ���� �������� ���������
void MAGAZIN::insert()
{
	cout << "�����: "; cin >> this->count;
	// �������� ������ ���� �� ���������� getline	
	cin.ignore(256, '\n');
	cout << "�����: "; getline(cin, this->author);
	cout << "��������: "; getline(cin, this->name);
	
}
