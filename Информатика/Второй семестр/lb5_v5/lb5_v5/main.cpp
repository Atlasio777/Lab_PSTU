#include <iostream>
#include <string.h>
#include <string>
using namespace std;


// ����������� �����
// ��� ������� �� �������� ������ � ���, ��� � ���� ���� ���� ���� ���������������� �����
// � ����� ������ ����� ���� � ������� �����, ������� ���������� ����������
class PAIR {

protected:
	// ���� ������
	int first, second;

public:
	PAIR() {}
	PAIR(int f, int s)
	{
		this->first = f;
		this->second = s;
	}
	
	// ���������������� ����� �������� ������
	virtual void display() = 0;

	// ������ ��� �������� �������� � ���� ������
	void setFirst(int number) { this->first = number; }
	void setSecond(int number) { this->second = number; }
	int getFirst() { return this->first; }
	int getSecond() { return this->second; }

};

class MONEY : public PAIR {
private:
	// ���� ������
	int rub, cop;
public:
	// ����������� ������ �� ���������
	MONEY()
	{
		this->rub = 0;
		this->cop = 0;
	}
	// ����������� ������ � �����������
	MONEY(int r, int c) : PAIR(r, c)
	{		
		this->rub = r;
		this->cop = c;
	}


	// ���������� �������� ���������� ���������
	MONEY operator +(MONEY& source)
	{
		cout << "\n����������� ��������\n";
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
		cout << "\n����������� ���������\n";
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
		cout << "\n����������� �������\n";
		MONEY obj;
		obj.rub = this->getFirst() / source.getFirst();
		obj.cop = this->getSecond() / source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	
	// �������� override, ������� �����������, 
    // ��� ����� ����������������� ������ ����� � ������������ ������

	// ������������� �����
	void display() override
	{
		string res = "";
		res += to_string(this->first);
		res += " ���. ";
		res += to_string(this->second);
		res += " ���.";
		cout << res << endl;
	}

};

int main()
{
	// ��������� �������
	setlocale(LC_ALL, "RU");

	// ������� ������������ ������
	MONEY money1(5,50);// ��� ���
	MONEY money2;
	MONEY money3;


	// ���� �������� ��� ������ � ����������
	int rub, cop;
	cout << "money2:\n";
	cout << "��� = "; cin >> rub;
	cout << "��� = "; cin >> cop;

	// �������� ��������� � ������ ������
	money2.setFirst(rub);
	money2.setSecond(cop);

	// ��������� ������� �������� ������
	PAIR* baseObj;
	// ����� �������� ����� �������
	baseObj = &money1;
	cout << "MONEY1 = "; baseObj->display();
	baseObj = &money2;
	cout << "MONEY2 = "; baseObj->display();

	// �������� ���� �������� ������ MONEY
	money3 = money1 + money2;
	baseObj = &money3;
	// ����� �������� ����� ������
	cout << "MONEY3 = "; baseObj->display();

	// ���������� ���� �������� ������ MONEY
	money3 = money3 - money2;
	baseObj = &money3;
	// ����� �������� ����� ������
	cout << "��������� ����� ���������:\n";
	cout << "MONEY3 = "; baseObj->display();

	// ���������� ���� �������� ������ MONEY
	money3 = money2 / money1;
	baseObj = &money3;
	// ����� �������� ����� ������
	cout << "��������� ����� �������:\n";
	cout << "MONEY3 = "; baseObj->display();

	cout << endl;
	system("pause");
	return 0;
}
