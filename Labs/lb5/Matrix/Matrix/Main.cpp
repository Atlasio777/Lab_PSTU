#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<ctime>
using namespace std;


int** CreateArray(int N)
{
    srand(time(NULL));
    int** arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    return arr;
}


int** CreateUnitArray(int N)
{
    int** arr = new int* [N];
    for (int i = 0; i<N; i++)
    {
        arr[i] = new int[N];
    }

    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            if (i == j || j == N - i - 1)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    return arr;
}


void DestroyArray(int** arr, int N)
{
    for (int i = 0; i < N; i++)
        delete(arr[i]);
    delete(arr);
}


void PrintArray(int** arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<setw(5)<<arr[i][j];
        cout << endl;
    }
    cout << endl;
}


int DotProduct(int* a, int* b, int N)
{
    int i, sum;
    for (i = sum = 0; i < N; i++)
        sum += a[i] * b[i];
    return sum;
}


int IsOrthogonal(int** arr, int N)
{
    int res = 1;
    for (int i = 0; i < N; i++)
    {
        if (DotProduct(arr[i], arr[i], N) != 1)
            res *= 0;
        for (int j = i + 1; j < N; j++)
            if (DotProduct(arr[i], arr[j], N))
                res *= 0;
    }
    return res;
}


void Check(int** arr, int N)
{
    if (IsOrthogonal(arr, N))
        cout << "Матрица ортонормированная." << endl;
    else
        cout << "Матрица не ортонормированная." << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введите N: ";
    cin >> N;
    cout << "Заполните массив:" << endl;
    int** random = CreateArray(N);
    int** unit = CreateUnitArray(N);

    cout<<"\n\nИсходный массив:\n";
    PrintArray(random, N);
    Check(random, N);

    cout<<"\nЕдиничный массив:\n";
    PrintArray(unit, N);
    Check(unit, N);

    DestroyArray(random, N);
    DestroyArray(unit, N);
    return 0;
}