#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// объ€вл€ение и реализаци€ класса
class Uravnenie {
private:
	// пол€ класса
	double A,B,C;// коэффициенты

public:
	// конструктор по умолчанию
	Uravnenie() :A(0), B(0), C(0) {}

	// конструктор с параметрами
	Uravnenie(double a, double b, double c) :A(a), B(b), C(c) {}


	// методы дл€ вычислени€ по коэффициентам
	// сумма
	double sum(){ 
		double result = A + B + C;
		printf("%lf + %lf + %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// разность
	double razn() { 
		double result = A - B - C;
		printf("%lf - %lf - %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// произведение
	double proizv() { 
		double result = A * B * C;
		printf("%lf * %lf * %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// частное
	double chast() { 
		double result = A / B / C;
		printf("%lf / %lf / %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// задаем параметры класса
	void setA(double A) { this->A = A; }
	void setB(double B) { this->B = B; }
	void setC(double C) { this->C = C; }

};

int main()
{
	setlocale(LC_ALL, "RU");


	double A, B, C;
	// ввод данных с клавиатуры
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;

	// объект класса
	Uravnenie obj(A, B, C);
	// вызов функций объекта класса
	obj.chast();
	obj.proizv();
	obj.razn();
	obj.sum();

	// ввод данных с клавиатуры
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;
	
	// объект класса
	Uravnenie obj2;
	// задаем параметры объекту класса
	obj2.setA(A);
	obj2.setB(B);
	obj2.setC(C);

	// вызов функций объекта класса
	obj2.chast();
	obj2.proizv();
	obj2.razn();
	obj2.sum();


	cout << endl;
	system("pause");
	return 0;
}