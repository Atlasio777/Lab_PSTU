#include "Time.h"
#include <string>

// �������������� ������� � �������
unsigned int Time::toSecond(unsigned int m, unsigned int sec)
{
	return m * 60 + sec;
}

// �������������� ������ � ������ � �������
void Time::toTime(unsigned int& seconds, unsigned int& min, unsigned int& sec)
{
	min = seconds / 60;
	sec = seconds %= 60;

}

// ������� �������
string Time::toString()
{
	string str = "";
	if (minutes < 10) str = "0";
	str += to_string(minutes) + ":";
	if (seconds < 10) str += "0";
	str += to_string(seconds);

	return str;// ������� ���������� �����
}


// ������ ����
void Time::setMinutes(unsigned int m) { this->minutes = m; }
// ������ �������
void Time::setSeconds(unsigned int s) { this->seconds = s; }

// �������� ���������� ��� ��������� ������
Time Time::operator -(const unsigned int& sec)
{//���������� �������� ���������� ���������

	// ������� ��� ����� � ��������
	unsigned int timeToSeconds = toSecond(this->minutes, this->seconds);
	// ��������� ������ �� ������ �������
	timeToSeconds -= sec;
	// ������� ������ � ������ � �������
	unsigned int m = this->minutes, s = this->seconds;
	toTime(timeToSeconds, m, s);
	Time obj(m, s);

	return obj;
}

// ���������� ��������� ���������
bool operator == (Time a, Time b)
{
	// ���� ����� �����, ������ true, ����� false
	if (a.minutes == b.minutes && a.seconds == b.seconds) return true;
	return false;
}

// ���������� ��������� ���������
bool operator != (Time a, Time b)
{
	// ���� ����� �����, ������ false, ����� true
	if (a.minutes != b.minutes || a.seconds != b.seconds) return true;
	return false;
}