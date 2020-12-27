#include <iostream>
#include <time.h>
using namespace std;

void displayArray(int *a, int size)
{
	std::cout << "\nОдномерный массив:\n";
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
}


int *removeMultipleNumbers(int a[], int &size)
{
	int newcount = 0;
	for (int i = 0; i < size; i++) {

		if (a[i] % 7 != 0) newcount++;
	}
	
	int* newArr = new int[newcount];
	
	int index = 0;
	for (int i = 0; i < size; i++) {
		
		if (a[i] % 7 != 0) newArr[index++] = a[i];
	}

	size = newcount;
	return newArr;
}


void addAfterOddZero(int *&arr, int &size)
{
	int newcount = size;
	for (int i = 0; i < size; i++) {

		if (arr[i] % 2 != 0) newcount++;
	}

	int* newArr = new int[newcount];

	int index = 0;
	for (int i = 0; i < size; i++) {
		newArr[index++] = arr[i];

		if (arr[i] % 2 != 0) newArr[index++] = 0;
	}


	size = newcount;
	delete[] arr;
	arr = newArr;
}


int main()
{
	setlocale(LC_ALL, "RU");

	const int max = 100;
	int arr[max];
	int size = 0;
	srand(time(0));
	
	std::cout << "N = ";
	std::cin >> size;
	
	if (size > max) size = max;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 30;
	}
	
	displayArray(arr, size);

	
	int* newArr = removeMultipleNumbers(arr, size);
	
	displayArray(newArr, size);
	addAfterOddZero(newArr, size);
	displayArray(newArr, size);

	cout << endl;
	system("pause");
	return 0;
}