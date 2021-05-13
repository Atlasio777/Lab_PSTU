#include <iostream>
#include "Time.h"
using namespace std;

// удалить все записи, где заданное время меньше времени объектов
Time* removeWhere(Time *&time, int &size)
{
	// зададим время
	// ввод данных с клавиатуры
	Time t;
	unsigned int m, s;// переменные для ввода с клавиатуры
	cout << "Удаление записей, больших заданного:\n";
	cout << "минуты = "; cin >> m;
	cout << "секунды = "; cin >> s;
	// установка параметров в объект класса
	t.setMinutes(m);
	t.setSeconds(s);

	Time *tmp = new Time[size];// временный массив для удаления элементов
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i] < t) {
			// копируем не удаляемый элемент во временный массив
			tmp[index++] = time[i];
		}
	}
	// перепишем из временного массива элементы, которые остались после удаления
	time = tmp;
	size = index;
	return time;
}


// добавить К записей после записи с номером N
void addRecords(Time *&time, int& size)
{
	cout << "добавить К записей после записи с номером N:\n";
	unsigned int m, s;// переменные для ввода с клавиатуры
	int N = 0;
	int K = 0;
	cout << "N = "; cin >> N;
	cout << "K = "; cin >> K;
	N--; // поправка на индексацию с нуля
	// массив для добавления
	Time tmp[1000];
	int index = 0;
	// копируем элементы до N
	for (index = 0; index <= N; index++)
		tmp[index] = time[index];


	// добавляем новые K записей
	for (int i = 0; i < K; i++) {
		// ввод данных с клавиатуры
		cout << "минуты = "; cin >> m;
		cout << "секунды = "; cin >> s;
		// установка параметров в объект класса
		tmp[index + i].setMinutes(m);
		tmp[index + i].setSeconds(s);
		if (i + 1 == K) index += i + 1;
	}

	// добавляем оставшиеся записи с первого массива
	for (int i=N+1; i < size; i++)
		tmp[index++] = time[i];

	time = tmp;
	size = index;
}


int main()
{
	setlocale(LC_ALL, "RU");

	int index = 0;// индекс для массива объектов
	Time *time = new Time[1000];// массив объектов класса
	unsigned int m, s;// переменные для ввода с клавиатуры

	// ввод данных
	cout << "Ввод данных:\n";
	int size = 0;
	cout << "Колво вводимых значений: "; cin >> size;
	for (int i = 0; i < size; i++)
	{
		// ввод данных с клавиатуры
		cout << "минуты = "; cin >> m;
		cout << "секунды = "; cin >> s;
		// установка параметров в объект класса
		time[index + i].setMinutes(m);
		time[index + i].setSeconds(s);
		if (i + 1 == size) index += i+1;
	}
	
	
	// вывод данных
	for (int i = 0; i < index; i++)
		cout << "Время: " << time[i].toString() << endl;
	
	

	// увеличить все записи с заданным значением на 1 мин 30 сек
	Time tmp(1,30);
	for (int i = 0; i < index; i++)
		time[i] = time[i] + tmp;
		
	// вывод данных
	cout << "\nДанные после прибавления 1 мин 30 сек:\n";
	for (int i = 0; i < index; i++)
		cout << "Время: " << time[i].toString() << endl;
	


	// добавить К записей после записи с номером N
	addRecords(time, index);
	cout << "\nДанные после добавления K записей:\n";
	for (int i = 0; i < index; i++)
		cout << "Время: " << time[i].toString() << endl;
	
	
	
	// удалить все записи, где заданное время больше времени объектов
	time = removeWhere(time, index);

	// вывод данных
	cout << "\nДанные после удаления:\n";
	for (int i = 0; i < index; i++)
		cout << "Время: " << time[i].toString() << endl;
	

	cout << endl;
	system("pause");
	return 0;
}