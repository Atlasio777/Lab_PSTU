#include <iostream>
#include <string.h>
#include <string>
using namespace std;


// абстрактный класс
// его отличие от простого класса в том, что у него есть хоть один чистовиртуальный метод
// в таком классе может быть и обычный метод, который унаследуют наследники
class PAIR {

protected:
	// поля класса
	int first, second;

public:
	PAIR() {}
	PAIR(int f, int s)
	{
		this->first = f;
		this->second = s;
	}
	
	// чистовиртуальный метод создания строки
	virtual void display() = 0;

	// метода для передачи значений в поля класса
	void setFirst(int number) { this->first = number; }
	void setSecond(int number) { this->second = number; }
	int getFirst() { return this->first; }
	int getSecond() { return this->second; }

};

class MONEY : public PAIR {
private:
	// поля класса
	int rub, cop;
public:
	// конструктор класса по умолчанию
	MONEY()
	{
		this->rub = 0;
		this->cop = 0;
	}
	// конструктор класса с параметрами
	MONEY(int r, int c) : PAIR(r, c)
	{		
		this->rub = r;
		this->cop = c;
	}


	// префиксный оператор перегрузки инкремент
	MONEY operator +(MONEY& source)
	{
		cout << "\nВыполняется сложение\n";
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
		cout << "\nВыполняется вычитание\n";
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
		cout << "\nВыполняется деление\n";
		MONEY obj;
		obj.rub = this->getFirst() / source.getFirst();
		obj.cop = this->getSecond() / source.getSecond();
		obj.first = obj.rub;
		obj.second = obj.cop;
		return obj;
	}

	
	// оператор override, говорит компилятору, 
    // что нужно проконтролировать данный метод в родительском классе

	// перегруженный метод
	void display() override
	{
		string res = "";
		res += to_string(this->first);
		res += " руб. ";
		res += to_string(this->second);
		res += " коп.";
		cout << res << endl;
	}

};

int main()
{
	// кириллица консоли
	setlocale(LC_ALL, "RU");

	// объекты производного класса
	MONEY money1(5,50);// руб коп
	MONEY money2;
	MONEY money3;


	// ввод значений для класса с клавиатуры
	int rub, cop;
	cout << "money2:\n";
	cout << "руб = "; cin >> rub;
	cout << "коп = "; cin >> cop;

	// передаем параметры в объект класса
	money2.setFirst(rub);
	money2.setSecond(cop);

	// указатель объекта базового класса
	PAIR* baseObj;
	// вывод значений полей классов
	baseObj = &money1;
	cout << "MONEY1 = "; baseObj->display();
	baseObj = &money2;
	cout << "MONEY2 = "; baseObj->display();

	// сложение двух объектов класса MONEY
	money3 = money1 + money2;
	baseObj = &money3;
	// вывод значений полей класса
	cout << "MONEY3 = "; baseObj->display();

	// вычистание двух объектов класса MONEY
	money3 = money3 - money2;
	baseObj = &money3;
	// вывод значений полей класса
	cout << "Результат после вычитания:\n";
	cout << "MONEY3 = "; baseObj->display();

	// вычистание двух объектов класса MONEY
	money3 = money2 / money1;
	baseObj = &money3;
	// вывод значений полей класса
	cout << "Результат после деления:\n";
	cout << "MONEY3 = "; baseObj->display();

	cout << endl;
	system("pause");
	return 0;
}
