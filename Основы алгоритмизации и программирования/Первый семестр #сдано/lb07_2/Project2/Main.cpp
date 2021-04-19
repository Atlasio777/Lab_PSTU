#include <iostream>
using namespace std;

//Ф-ия с 5 параметрами
int sum(int a1, int a2, int a3, int a4, int a5)
{
	return a1 * a2 - a2 * a3 + a3 * a4 - a4 * a5;
}

//Ф-ия с 10 параметрами
int sum(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
	return a1 * a2 - a2 * a3 + a3 * a4 - a4 * a5 - a5 * a6 - a6 * a7 + a7 * a8 - a8 * a9 - a9 * a10;
}

//Ф-ия с 12 параметрами
int sum(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
	return a1 * a2 - a2 * a3 + a3 * a4 - a4 * a5 - a5 * a6 - a6 * a7 + a7 * a8 - a8 * a9 - a9 * a10 - a10 * a11 - a11 * a12;
}

int main()
{
	setlocale(LC_ALL, "RU");
	//Вызов ф-ии с 5 параметрами
	cout << sum(1, 2, 3, 4, 5) << endl;
	//Вызов ф-ии с 10 параметрами
	cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	//Вызов ф-ии с 12 параметрами
	cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
	return 0;
}