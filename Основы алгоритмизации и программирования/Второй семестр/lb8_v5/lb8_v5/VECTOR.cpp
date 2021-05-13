#include "VECTOR.h"


// ���������� ������
VECTOR::~VECTOR() 
{
	if (this->beg != 0) delete[]this->beg;
	this->beg = 0;
}

// ����������� ������ � �����������
VECTOR::VECTOR(int n)
{
	// ������������� �������
	this->beg = new Object * [n];
	this->curr = 0;
	this->size = n;
}
// ���������� �������� � ������
void VECTOR::add()
{
	Object* p;
	// ����� �� �������� ���� ��������� �������
	cout << "���������� ������� � ������:" << endl;
	// ���������� ������� ������ MAGAZIN
	MAGAZIN* a = new MAGAZIN();
	// ���� ���������
	a->insert();
	p = a;
	if (this->curr < this->size)
	{
		this->beg[this->curr] = p;// ���������� � ������
		this->curr++;
	}

}

// �������� �������
void VECTOR::show()
{
	if (this->curr == 0) cout << "�����...\n";
	// ��������� �� ��������� ���� Object
	Object** p = beg;
	for (int i = 0; i < this->curr; i++)
	{
		// ����� ������ (������� ����������)
		(*p)->display();
		p++;// ����������� ��������� �� ��������� �������
	}
}

// ���������� ������ �������
int VECTOR::operator()()
{
	return this->curr+1;
}


// �������� �������� �� ������� 
void VECTOR::del()
{
	// ������ ����
	if (this->curr == 0) return;
	this->curr--;
}
