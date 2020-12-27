#include <iostream>
#include <cstdarg>
#include <iomanip>

using namespace std;


double f(double x)
{
    return 0.25 * pow(x, 3) + x - 1.2502;
}

double df(double x)
{
    return 0.75 * pow(x,2) + 1;
}

double g(double x)
{
    return x - f(x) / df(x);
}

void newton()
{
    double x;
    double eps;
    cout << "Введите начальное значение корня : "; cin >> x;
    cout << "Напишите точно значение : "; cin >> eps;
    for (double iter = 1; eps < fabs(f(x)); iter = iter + 1)
    {
        cout << "Iteration : " << setprecision(0) << iter << endl;
        if (df(x) == 0)
            break;
        cout << "x    = " << x << endl;
        cout << "g(x) = " << g(x) << endl;
        cout << "df(x)= " << df(x) << endl;
        cout << "f(x) = " << f(x) << endl;
        x = g(x);
    }
}


int main()
{
    setlocale(LC_ALL, "rus");

    newton();
    system("pause");
}


