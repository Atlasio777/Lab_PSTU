#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class PAIR{
protected:
	// ���� ������
	int first, second;
public:
	// ����������� ������ �� ���������
	PAIR() 
	{
		this->first = 0;
		this->second = 0;
	}
	// ����������� ������ � �����������
	PAIR(int f, int s)
	{
		this->first = f;
		this->second = s;
	}
	
	// ������ ��� �������� �������� � ���� ������
	void setFirst(int number) { this->first = number; }
	void setSecond(int number) { this->second = number; }
	int getFirst() { return this->first; }
	int getSecond() { return this->second; }

	// ����������� ����� �������� ������
	virtual string toString()
	{
		string res = "";
		res += to_string(this->first);
		res += " ���. ";
		res += to_string(this->second);
		res += " ���.";
		return res;
	}

	// ���������� �������� ���������� ���������
	virtual PAIR operator +(const PAIR& source)
	{
		PAIR obj;
		obj.first = this->first + this->second;
		obj.second = source.first + source.second;

		return obj;
	}
};

class MONEY : public PAIR{
protected:
	// ���� ������
	int rub, cop;
public:
	// ����������� ������ �� ���������
	MONEY():PAIR()
	{
		this->rub = 0;
		this->cop = 0;
	}
	// ����������� ������ � �����������
	MONEY(int r, int c):PAIR(r,c)
	{
		this->rub = r;
		this->cop = c;
	}

	// ���������� �������� ���������� ���������
	MONEY operator +(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() + source.getFirst();
		obj.cop = this->getSecond() + source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	// ���������� �������� ���������� ���������
	MONEY operator -(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() - source.getFirst();
		obj.cop = this->getSecond() - source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	// ���������� ��������� �������
	MONEY operator /(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() / source.getFirst();
		obj.cop = this->getSecond() / source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}
	// ������������� �����
	string toString()
	{
		string res = "";
		res += to_string(this->first);
		res += " ���. ";
		res += to_string(this->second);
		res += " ���.";
		return res;
	}

};

int main()
{
	// ��������� �������
	setlocale(LC_ALL, "RU");

	// ������� ������������ ������
	MONEY money1(5,40);
	MONEY money2;
	MONEY money3;
	PAIR *base = &money2;
	PAIR* base2 = &money3;

	// ���� �������� ��� ������ � ����������
	int rub, cop;
	cout << "money2:\n";
	cout << "��� = "; cin >> rub;
	cout << "��� = "; cin >> cop;
	
	// �������� ��������� � ������ ������
	base->setFirst(rub);
	base->setSecond(cop);
	
	// ����� �������� ����� �������
	cout << "MONEY1 = " << money1.toString() << endl;
	cout << "MONEY2 = " << money2.toString() << endl;

	// �������� ���� �������� ������ MONEY
	money3 = money1 + money2;
	// ����� �������� ����� ������
	cout << "MONEY3 = " << money3.toString() << endl;

	// ���������� ���� �������� ������ MONEY
	money3 = money3 - money2;
	// ����� �������� ����� ������
	cout << "��������� ����� ���������:\n";
	cout << "MONEY3 = " << money3.toString() << endl;

	// ���������� ���� �������� ������ MONEY
	money3 = money3 / money2;
	// ����� �������� ����� ������
	cout << "��������� ����� �������:\n";
	cout << "MONEY3 = " << money3.toString() << endl;

	cout << endl;
	system("pause");
	return 0;
}
