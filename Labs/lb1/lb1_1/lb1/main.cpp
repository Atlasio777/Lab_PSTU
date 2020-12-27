#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	float fA = 1000;
	float fB = 0.0001;
	double dA = 1000;
	double dB = 0.0001;

	double a = 0, b = 0, c = 0, d = 0;

	float result1 = 0;
	double result2 = 0;

	result1 = (pow(fA - fB, 3) - (pow(fA, 3) - 3 * pow(fA, 2) * fB)) / pow(fB,3) - 3*fA*pow(fB,2);
	result2 = (pow(dA - dB, 3) - (pow(dA, 3) - 3 * pow(dA, 2) * dB)) / pow(dB,3) - 3*dA*pow(dB,2);

	cout << "Result with float: " << result1 << endl;
	cout << "Result with double: " << result2 << endl;
	//printf("Result with float by printf: %lf", result1); not need
	cout << endl;
	system("pause");
}