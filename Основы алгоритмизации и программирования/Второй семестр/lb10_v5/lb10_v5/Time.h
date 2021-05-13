#pragma once
#include <string>
using namespace std;

// объявляение и реализация класса
class Time {
private:
	// поля класса
	unsigned int minutes;// минуты 
	unsigned int seconds;// секунды

	// преобразование времени в секунды
	unsigned int toSecond(unsigned int m, unsigned int sec);

	// преобразование секунд в минуты и секунды
	void toTime(unsigned int& seconds, unsigned int& min, unsigned int& sec);

public:
	// конструктор по умолчанию
	Time() :minutes(0), seconds(0) {}

	// конструктор с параметрами
	Time(unsigned int m, unsigned int s) :minutes(m), seconds(s) {}

	// возврат времени
	string toString();
	
	// задаем часы
	void setMinutes(unsigned int m);
	// задаем секунды
	void setSeconds(unsigned int s);

	// оператор перегрузки для вычитания секунд
	Time operator -(const unsigned int& sec);

	// оператор перегрузки для добавления времени
	Time operator +(const Time &);

	// перегрузка оператора сравнения
	friend bool operator == (Time a, Time b);

	// перегрузка оператора сравнения
	friend bool operator != (Time a, Time b);

	// оператор перегрузки >
	bool operator <(const Time& obj);

};


