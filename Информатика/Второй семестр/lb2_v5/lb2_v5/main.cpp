#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ����������� � ���������� ������
class Uravnenie {
private:
	// ���� ������
	double A,B,C;// ������������

public:
	// ����������� �� ���������
	Uravnenie() :A(0), B(0), C(0) {}

	// ����������� � �����������
	Uravnenie(double a, double b, double c) :A(a), B(b), C(c) {}


	// ������ ��� ���������� �� �������������
	// �����
	double sum(){ 
		double result = A + B + C;
		printf("%lf + %lf + %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// ��������
	double razn() { 
		double result = A - B - C;
		printf("%lf - %lf - %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// ������������
	double proizv() { 
		double result = A * B * C;
		printf("%lf * %lf * %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// �������
	double chast() { 
		double result = A / B / C;
		printf("%lf / %lf / %lf = %.2lf\n", A, B, C, result);
		return result;
	}

	// ������ ��������� ������
	void setA(double A) { this->A = A; }
	void setB(double B) { this->B = B; }
	void setC(double C) { this->C = C; }

};

int main()
{
	setlocale(LC_ALL, "RU");


	double A, B, C;
	// ���� ������ � ����������
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;

	// ������ ������
	Uravnenie obj(A, B, C);
	// ����� ������� ������� ������
	obj.chast();
	obj.proizv();
	obj.razn();
	obj.sum();

	// ���� ������ � ����������
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	cout << "C = "; cin >> C;
	
	// ������ ������
	Uravnenie obj2;
	// ������ ��������� ������� ������
	obj2.setA(A);
	obj2.setB(B);
	obj2.setC(C);

	// ����� ������� ������� ������
	obj2.chast();
	obj2.proizv();
	obj2.razn();
	obj2.sum();


	cout << endl;
	system("pause");
	return 0;
}