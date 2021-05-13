#include <iostream>
using namespace std;

// объ€вл€ение и реализаци€ класса
class Time {
private:
	// пол€ класса
	unsigned int first;// часы 
	unsigned int second;// минуты

public:
	// конструктор по умолчанию
	Time():first(0), second(0) {}
	
	// метод дл€ переведени€ вреемни в минуты
	unsigned minutes()
	{
		// певеровим часы в минуты
		int min = first * 60;
		min += second;// прибавл€ем минуты
		return min;// функци€ возвращает минуты
	}

	// задаем часы
	void setHours(unsigned int f) { this->first = f; }
	// задаем минуты
	void setMinutes(unsigned int s) { this->second = s; }

	void display()
	{
		cout << this->first << ":" << this->second << " = " << minutes() << " мин." << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "RU");

	// объект класса
	Time time;
	unsigned int h, m;// часы и минуты дл€ ввод с клавиатуры
	// ввод данных с клавиатуры
	cout << "часы = "; cin >> h;
	cout << "минуты = "; cin >> m;
	// установка параметров в объект класса
	time.setHours(h);
	time.setMinutes(m);
	// вывод данных
	time.display();


	cout << endl;
	system("pause");
	return 0;
}