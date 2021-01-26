#include <iostream>
#include <math.h>
using namespace std;



long double factorial(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;
	else return N * factorial(N - 1);
}


int main()
{
	setlocale(LC_ALL, "RU");

	double e = pow(10, -4);
	int a = 1, b = 2;
	const int k = 10;
	double step = (double)(b - a) / k;
	double fx = 1;
	int n = 15;



	cout << "Точность e = " << e << endl;
	cout << "а = " << a << "; " << "b = " << b << endl;
	cout << "шаг = " << step << endl;

	double x = a;
	for (int i = 1; i <= n; i++) {
		cout << fx << endl;
		
		fx += pow(x, i) / factorial(i);
	}
	cout << "e^x = " << exp(x) << "; S = " << fx << endl;

	while (x <= b)
	{
		fx = 1;
		double component = 1;
		for (int i = 1; abs(component) >= e; i++)
		{
			
			component *= (x / i);
			fx += component;
		}
		cout << fx << endl;
		x += step;
	}
	cout << "e^x = " << exp(x) << "; S = " << fx << endl;

	return 0;
}