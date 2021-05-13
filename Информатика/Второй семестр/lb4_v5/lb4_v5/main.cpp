#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class PAIR{
protected:
	// поля класса
	int first, second;
public:
	// конструктор класса по умолчанию
	PAIR() 
	{
		this->first = 0;
		this->second = 0;
	}
	// конструктор класса с параметрами
	PAIR(int f, int s)
	{
		this->first = f;
		this->second = s;
	}
	
	// метода для передачи значений в поля класса
	void setFirst(int number) { this->first = number; }
	void setSecond(int number) { this->second = number; }
	int getFirst() { return this->first; }
	int getSecond() { return this->second; }

	// виртуальный метод создания строки
	virtual string toString()
	{
		string res = "";
		res += to_string(this->first);
		res += " руб. ";
		res += to_string(this->second);
		res += " коп.";
		return res;
	}

	// префиксный оператор перегрузки инкремент
	virtual PAIR operator +(const PAIR& source)
	{
		PAIR obj;
		obj.first = this->first + this->second;
		obj.second = source.first + source.second;

		return obj;
	}
};

class MONEY : public PAIR{
protected:
	// поля класса
	int rub, cop;
public:
	// конструктор класса по умолчанию
	MONEY():PAIR()
	{
		this->rub = 0;
		this->cop = 0;
	}
	// конструктор класса с параметрами
	MONEY(int r, int c):PAIR(r,c)
	{
		this->rub = r;
		this->cop = c;
	}

	// префиксный оператор перегрузки инкремент
	MONEY operator +(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() + source.getFirst();
		obj.cop = this->getSecond() + source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	// префиксный оператор перегрузки дикримент
	MONEY operator -(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() - source.getFirst();
		obj.cop = this->getSecond() - source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	// перегрузка оператора деления
	MONEY operator /(MONEY& source)
	{
		MONEY obj;
		obj.rub = this->getFirst() / source.getFirst();
		obj.cop = this->getSecond() / source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}
	// перегруженный метод
	string toString()
	{
		string res = "";
		res += to_string(this->first);
		res += " руб. ";
		res += to_string(this->second);
		res += " коп.";
		return res;
	}

};

int main()
{
	// кириллица консоли
	setlocale(LC_ALL, "RU");

	// объекты производного класса
	MONEY money1(5,40);
	MONEY money2;
	MONEY money3;
	PAIR *base = &money2;
	PAIR* base2 = &money3;

	// ввод значений для класса с клавиатуры
	int rub, cop;
	cout << "money2:\n";
	cout << "руб = "; cin >> rub;
	cout << "коп = "; cin >> cop;
	
	// передаем параметры в объект класса
	base->setFirst(rub);
	base->setSecond(cop);
	
	// вывод значений полей классов
	cout << "MONEY1 = " << money1.toString() << endl;
	cout << "MONEY2 = " << money2.toString() << endl;

	// сложение двух объектов класса MONEY
	money3 = money1 + money2;
	// вывод значений полей класса
	cout << "MONEY3 = " << money3.toString() << endl;

	// вычистание двух объектов класса MONEY
	money3 = money3 - money2;
	// вывод значений полей класса
	cout << "Результат после вычитания:\n";
	cout << "MONEY3 = " << money3.toString() << endl;

	// вычистание двух объектов класса MONEY
	money3 = money3 / money2;
	// вывод значений полей класса
	cout << "Результат после деления:\n";
	cout << "MONEY3 = " << money3.toString() << endl;

	cout << endl;
	system("pause");
	return 0;
}
