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
	{// ���������� �������� ���������� ���������

		// ������� ��� ����� � ��������
		unsigned int timeToSeconds = toSecond(this->minutes, this->seconds);
		// ��������� ������ �� ������ �������
		timeToSeconds -= sec;
		// ������� ������ � ������ � �������
		unsigned int m = 0, s = 0;
		toTime(timeToSeconds, m, s);
		Time obj(m, s);

		return obj;
	}

	// �������� ���������� ��� ���������� �������
	Time Time::operator +(const Time &t)
	{
		// ������� ��� ����� � ��������
		unsigned int objTimeSec = toSecond(t.minutes, t.seconds);
		unsigned int currTimeSec = toSecond(this->minutes, this->seconds);
		// ���������� ������ � �������
		currTimeSec += objTimeSec;
		// ������� ������ � ������ � �������
		unsigned int m = 0, s = 0;
		toTime(currTimeSec, m, s);
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

	// ���������� ��������� <
	bool Time::operator <(const Time& obj)
	{
		// ������� ����� � ��������
		unsigned int TimeSeconds1 = toSecond(this->minutes, this->seconds);
		unsigned int TimeSeconds2 = toSecond(obj.minutes, obj.seconds);
		// ��������� ����� ����� ������
		if (TimeSeconds1 < TimeSeconds2) return true;
		return false;
	}