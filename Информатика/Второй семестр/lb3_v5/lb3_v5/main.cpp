#include <iostream>
#include "Time.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");


	Time time;// объект класса
	unsigned int m, s;// переменные для ввода с клавиатуры
	// ввод данных с клавиатуры
	cout << "минуты = "; cin >> m;
	cout << "секунды = "; cin >> s;
	// установка параметров в объект класса
	time.setMinutes(m);
	time.setSeconds(s);
	// вывод данных
	string str = time.toString();
	cout << "Текущее время " << str << endl;

	unsigned int sec = 0;
	cout << "Колво секунд, чтобы отнять: "; cin >> s;
	Time newTime = time - s;
	str = newTime.toString();
	cout << "Новое время " << str << endl;

	// сравнение времени при помощи перегруженных операторов сравнения
	if (time == newTime) cout << "Время совпадает.\n";
	if (time != newTime) cout << "Время не совпадает.\n";

	cout << endl;
	system("pause");
	return 0;
}