#include "MAGAZIN.h"



// конструктор класса по умолчанию
MAGAZIN::MAGAZIN()
{
	this->count = 0;
}

// конструктор класса
MAGAZIN::MAGAZIN(int count, string name, string author) : PRINT(name, author)
{
	this->count = count;
}

// данный оператор говорит компилятору,
// что нужно проконтролировать данный метод в родительском классе
void MAGAZIN::display()
{
	cout << "Объект класса ЖУРНА\n";
	cout << "Название журнала: " << this->name << endl;
	cout << "Автор журнала: " << this->author << endl;
	cout << "Колво ед.: " << this->count << endl;
}

// ввод значений атрибутов
void MAGAZIN::insert()
{
	cout << "Колво: "; cin >> this->count;
	// игнорить символ чтоб не пропускать getline	
	cin.ignore(256, '\n');
	cout << "Автор: "; getline(cin, this->author);
	cout << "Название: "; getline(cin, this->name);
	
}
