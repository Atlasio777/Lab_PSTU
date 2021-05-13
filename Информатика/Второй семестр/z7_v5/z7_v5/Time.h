#include <iostream>
using namespace std;


class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	Time operator+(Time);

	// перегруженные операции для ввода-вывода
	friend ostream& operator << (ostream& out, const Time&);
	friend istream& operator >> (istream& in, Time&);

	virtual  ~Time(void) {};

private:
	int min, sec;
};