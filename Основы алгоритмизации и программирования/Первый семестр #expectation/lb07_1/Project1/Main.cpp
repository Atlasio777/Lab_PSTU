#include <iostream>
using namespace std;

struct complex
{
	//Дествительная часть
	double Re;
	//Мнимая часть
	double Im;
};

float Multi(int size, float mas[])
{
	float res = 1;
	//Если множителей больше нуля
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			res *= mas[i];
		}
		return res;
	}
	else return 0;
}

// умножение комплексных чисел
complex Multi(int size, complex mas[])
{

	complex res;
	res.Re = 1;
	res.Im = 1;
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			res.Re *= mas[i].Re;
			res.Im *= mas[i].Im;
		}
		return res;
	}
	else
	{
		res.Re = 0;
		res.Im = 0;
		return res;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	//Количество вещественных чисел, комплексных
	int kolFloat, kolComplex;
	cout << "Введите количество вещественных чисел: ";
	cin >> kolFloat;
	float* mas = new float[kolFloat];
	cout << "Заполните массив:" << endl;
	for (int i = 0; i < kolFloat; i++)
	{
		cin >> mas[i];
	}
	cout << "Ваш массив:" << endl;
	for (int i = 0; i < kolFloat; i++)
	{
		cout << mas[i] << endl;
	}
	//Вывод результата умножения вещ. чисел
	cout << "Результат умножения чисел массива = " << Multi(kolFloat, mas) << endl;
	cout << "Введите количество комплексных чисел: ";
	cin >> kolComplex;
	complex* mas1 = new complex[kolComplex];
	cout << "Заполните массив:" << endl;
	for (int i = 0; i < kolComplex; i++)
	{
		cin >> mas1[i].Re;
		cin >> mas1[i].Im;
	}
	cout << "Ваш массив:" << endl;
	for (int i = 0; i < kolComplex; i++)
	{
		cout << mas1[i].Re << " + " << mas1[i].Im << "i" << endl;
	}
	//Вывод результата умножения комплексных чисел
	cout << "Результат умножения чисел массива = " << Multi(kolComplex, mas1).Re << " + " << Multi(kolComplex, mas1).Im << "i" << endl;
	return 0;
}