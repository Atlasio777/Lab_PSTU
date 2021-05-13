#include "VECTOR.h"


// деструктор класса
VECTOR::~VECTOR() 
{
	if (this->beg != 0) delete[]this->beg;
	this->beg = 0;
}

// конструктор класса с параметрами
VECTOR::VECTOR(int n)
{
	// инициализаци€ массива
	this->beg = new Object * [n];
	this->curr = 0;
	this->size = n;
}
// добавление элемента в вектор
void VECTOR::add()
{
	Object* p;
	// выбор из объектов двух возможных классов
	cout << "ƒобавление журнала в вектор:" << endl;
	// добавление объекта класса MAGAZIN
	MAGAZIN* a = new MAGAZIN();
	// ввод атребутов
	a->insert();
	p = a;
	if (this->curr < this->size)
	{
		this->beg[this->curr] = p;// добавление в вектор
		this->curr++;
	}

}

// просмотр вектора
void VECTOR::show()
{
	if (this->curr == 0) cout << "ѕусто...\n";
	// указатель но указатель типа Object
	Object** p = beg;
	for (int i = 0; i < this->curr; i++)
	{
		// вывод метода (позднее св€зывание)
		(*p)->display();
		p++;// перемещение указател€ на следующий элемент
	}
}

// возвращает размер вектора
int VECTOR::operator()()
{
	return this->curr+1;
}


// удаление элемента из вектора 
void VECTOR::del()
{
	// вектор пуст
	if (this->curr == 0) return;
	this->curr--;
}
