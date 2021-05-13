#pragma once
#include <string>
using namespace std;

// ����������� � ���������� ������
class Time {
private:
	// ���� ������
	unsigned int minutes;// ������ 
	unsigned int seconds;// �������

	// �������������� ������� � �������
	unsigned int toSecond(unsigned int m, unsigned int sec);

	// �������������� ������ � ������ � �������
	void toTime(unsigned int& seconds, unsigned int& min, unsigned int& sec);

public:
	// ����������� �� ���������
	Time() :minutes(0), seconds(0) {}

	// ����������� � �����������
	Time(unsigned int m, unsigned int s) :minutes(m), seconds(s) {}

	// ������� �������
	string toString();
	
	// ������ ����
	void setMinutes(unsigned int m);
	// ������ �������
	void setSeconds(unsigned int s);

	// �������� ���������� ��� ��������� ������
	Time operator -(const unsigned int& sec);

	// �������� ���������� ��� ���������� �������
	Time operator +(const Time &);

	// ���������� ��������� ���������
	friend bool operator == (Time a, Time b);

	// ���������� ��������� ���������
	friend bool operator != (Time a, Time b);

	// �������� ���������� >
	bool operator <(const Time& obj);

};


