#include <iostream>
#include <cstdarg>
#include <iomanip>

using namespace std;
void printInfo(string familiya = "Иванов", int course = 3, int rate = 80)
{
    cout << familiya << ", " << course << " курс. Рейтинг: " << rate << endl;
}


void printMaxValue(int n, ...)
{

    int max = -1000000;
    va_list factor;  
    va_start(factor, n); 
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (va_arg(factor, int) > max)
            {
                max = va_arg(factor, int);
            }
        }
       
    }
    va_end(factor);

    cout << "Max param = " << max << endl;
}


void sortBubl(double MyArray[], int size) {
    int last = size; bool ok;
    do {
        last = last - 1;
        ok = true;
        for (int i = 0; i < last; i++) {
            if (MyArray[i] > MyArray[i + 1]) {
                int x = MyArray[i];
                MyArray[i] = MyArray[i + 1];
                MyArray[i + 1] = x;
                ok = false;
            }
        }
    } while (!ok);
}



void sortBubl(int MyArray[], int size) {
    int last = size; bool ok;
    do {
        last = last - 1;
        ok = true;
        for (int i = 0; i < last; i++) {
            if (MyArray[i] > MyArray[i + 1]) {
                int x = MyArray[i];
                MyArray[i] = MyArray[i + 1];
                MyArray[i + 1] = x;
                ok = false;
            }
        }
    } while (!ok);
}



template <typename T>
void sortTemplate(T MyArray[], int size)
{
    int last = size; bool ok;
    do {
        last = last - 1;
        ok = true;
        for (int i = 0; i < last; i++) {
            if (MyArray[i] > MyArray[i + 1]) {
                int x = MyArray[i];
                MyArray[i] = MyArray[i + 1];
                MyArray[i + 1] = x;
                ok = false;
            }
        }
    } while (!ok);
}



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
    cout << "Enter initial root value   : "; cin >> x;
    cout << "Enter error of calculation : "; cin >> eps;
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

    printInfo();
    printInfo("Петров", 3, 75); 
    printInfo("Сидоров", 4);


    printMaxValue(6, 4, 6, 10, 1, 3, 12);



    int arr[] = { 2,9,4,6,87,1,2,4 };
    double arrD[] = { 4,6,78,1,5,7,89,11};

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arrD[i] << " ";
    }
    cout << endl;
    cout << endl;

    sortBubl(arr, 8);
    sortBubl(arrD, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arrD[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    int arr2[] = { 2,9,4,6,87,1,2,4 };
    double arrD2[] = { 4,6,78,1,5,7,89,11 };

    for (int i = 0; i < 8; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arrD2[i] << " ";
    }
    cout << endl;
    cout << endl;
    sortTemplate(arr2, 8);
    sortTemplate(arrD2, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arrD2[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    newton();
    system("pause");
}


