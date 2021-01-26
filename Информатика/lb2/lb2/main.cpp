#include <iostream>
#include <math.h>
using namespace std;

// главная функция
int main()
{
	setlocale(LC_ALL, "RU");

	// объявление переменных
	double exp = pow(10, -4);// точность числа
	double sumr = 0, r = 0;// сумма ряда, ряд
	int MAX = 0;// максимальное количество элементов ряда

	// вывод точности на экран
	cout << "Точность e = " << exp << endl;
	
	// ЦИКЛ С УСЛОВИЕМ
	// выполняем цикл, пока выполняется условие  n <= MAX выполняется
	for (int n = 1; n <= 1000; n++)
	{
		// значение ряда
		r = pow((-1),n-1) / pow(n,n);
		// проверка точности
		if (abs(r) - exp < 0) break;// точность достигнута

		cout << "значение ряда = " <<  r << endl;
		sumr += r;// суммя ряда
	}
	cout << "Сумма ряда = " << sumr << endl;

	return 0;
}