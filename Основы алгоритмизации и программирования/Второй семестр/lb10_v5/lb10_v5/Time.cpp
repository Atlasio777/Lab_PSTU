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
	{// префиксный оператор перегрузки инкремент

		// получим все время в секундах
		unsigned int timeToSeconds = toSecond(this->minutes, this->seconds);
		// вычитание секунд из общего времени
		timeToSeconds -= sec;
		// перевод секунд в минуты и секунды
		unsigned int m = 0, s = 0;
		toTime(timeToSeconds, m, s);
		Time obj(m, s);

		return obj;
	}

	// оператор перегрузки для добавления времени
	Time Time::operator +(const Time &t)
	{
		// получим все время в секундах
		unsigned int objTimeSec = toSecond(t.minutes, t.seconds);
		unsigned int currTimeSec = toSecond(this->minutes, this->seconds);
		// добавление секунд к времени
		currTimeSec += objTimeSec;
		// перевод секунд в минуты и секунды
		unsigned int m = 0, s = 0;
		toTime(currTimeSec, m, s);
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

	// перегрузка оператора <
	bool Time::operator <(const Time& obj)
	{
		// получим время в секундах
		unsigned int TimeSeconds1 = toSecond(this->minutes, this->seconds);
		unsigned int TimeSeconds2 = toSecond(obj.minutes, obj.seconds);
		// определим какое время больше
		if (TimeSeconds1 < TimeSeconds2) return true;
		return false;
	}