#include "Time.h"
#include <string>

// преобразование времени в секунды
unsigned int Time::toSecond(unsigned int m, unsigned int sec)
{
	return m * 60 + sec;
}

// преобразование секунд в минуты и секунды
void Time::toTime(unsigned int& seconds, unsigned int& min, unsigned int& sec)
{
	min = seconds / 60;
	sec = seconds %= 60;

}

// возврат времени
string Time::toString()
{
	string str = "";
	if (minutes < 10) str = "0";
	str += to_string(minutes) + ":";
	if (seconds < 10) str += "0";
	str += to_string(seconds);

	return str;// функция возвращает время
}


// задаем часы
void Time::setMinutes(unsigned int m) { this->minutes = m; }
// задаем секунды
void Time::setSeconds(unsigned int s) { this->seconds = s; }

// оператор перегрузки для вычитания секунд
Time Time::operator -(const unsigned int& sec)
{//префиксный оператор перегрузки инкремент

	// получим все время в секундах
	unsigned int timeToSeconds = toSecond(this->minutes, this->seconds);
	// вычитание секунд из общего времени
	timeToSeconds -= sec;
	// перевод секунд в минуты и секунды
	unsigned int m = this->minutes, s = this->seconds;
	toTime(timeToSeconds, m, s);
	Time obj(m, s);

	return obj;
}

// перегрузка оператора сравнения
bool operator == (Time a, Time b)
{
	// если время равно, вернем true, иначе false
	if (a.minutes == b.minutes && a.seconds == b.seconds) return true;
	return false;
}

// перегрузка оператора сравнения
bool operator != (Time a, Time b)
{
	// если время равно, вернем false, иначе true
	if (a.minutes != b.minutes || a.seconds != b.seconds) return true;
	return false;
}

bool operator<(const Time& p1, const Time& p2)
{
	return true;
}