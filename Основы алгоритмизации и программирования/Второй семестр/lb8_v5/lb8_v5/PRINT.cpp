#include "PRINT.h"

// конструктор класса по умолчанию
PRINT::PRINT()
{
}

// конструктор класса с параметрами
PRINT::PRINT(string n, string a)
{
	this->name = n;
	this->author = a;
}
