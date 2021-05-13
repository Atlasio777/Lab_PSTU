#include "Time.h"


Time::Time(void)
{
	min = sec = 0;
}

Time::Time(int m, int s)
{
	this->min = m;
	this->sec = s;
}

Time::Time(const Time& obj)
{
	this->min = obj.min;
	this->sec = obj.sec;
}
Time& Time::operator=(const Time& obj)
{
	this->min = obj.min;
	this->sec = obj.sec;
	return *this;
}

Time Time::operator+(Time obj)
{
	int t = this->min * 60 + this->sec;
	int kt = obj.min * 60 + obj.sec;
	t += kt;
	Time temp(t/60,t%60);
	return temp;
}


// перегруженные операции для ввода-вывода
ostream& operator << (ostream& out, const Time& obj)
{
	out << obj.min << " : " << obj.sec;
	return out;
}
istream& operator >> (istream& in, Time& obj)
{
	cout << "\nmin: "; in >> obj.min;
	cout << "\nsec: "; in >> obj.sec;
	return in;
}

