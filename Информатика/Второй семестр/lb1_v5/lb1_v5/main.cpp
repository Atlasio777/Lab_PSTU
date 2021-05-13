#include <iostream>
using namespace std;

// ����������� � ���������� ������
class Time {
private:
	// ���� ������
	unsigned int first;// ���� 
	unsigned int second;// ������

public:
	// ����������� �� ���������
	Time():first(0), second(0) {}
	
	// ����� ��� ����������� ������� � ������
	unsigned minutes()
	{
		// ��������� ���� � ������
		int min = first * 60;
		min += second;// ���������� ������
		return min;// ������� ���������� ������
	}

	// ������ ����
	void setHours(unsigned int f) { this->first = f; }
	// ������ ������
	void setMinutes(unsigned int s) { this->second = s; }

	void display()
	{
		cout << this->first << ":" << this->second << " = " << minutes() << " ���." << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "RU");

	// ������ ������
	Time time;
	unsigned int h, m;// ���� � ������ ��� ���� � ����������
	// ���� ������ � ����������
	cout << "���� = "; cin >> h;
	cout << "������ = "; cin >> m;
	// ��������� ���������� � ������ ������
	time.setHours(h);
	time.setMinutes(m);
	// ����� ������
	time.display();


	cout << endl;
	system("pause");
	return 0;
}