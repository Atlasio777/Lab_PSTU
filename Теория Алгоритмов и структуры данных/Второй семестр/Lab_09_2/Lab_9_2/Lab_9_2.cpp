// подключение библиотек ввода/вывода работы с файловыми потоками и строками
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
// пространство имен
using namespace std;


// прототипы функций
void readFile(char* fileName);
void writeInFile(char* fileName);
void findByHeightAndWeight(char *fileName, int height, int weight);
void writeToStart(char* fileName);

// главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    // считаем
    char fileName[] = "D:\\file.txt";

    // ввод числа с клавиатуры
    int n;
    cout << "N = "; cin >> n;

    // ввод записи заданное количество раз (n)
    for (int i = 0; i < n; i++) {
        // запись в файла данных введенных с клавиатуры
        writeInFile(fileName);
    }
    // чтение файла fileName
    readFile(fileName);
   
    int height, weight;
    cout << "Высота: ";
    cin >> height;
    cout << "Ширина: ";
    cin >> weight;

    // поиск записи по высоте и весу
    findByHeightAndWeight(fileName, height, weight);
    // чтение файла
    readFile(fileName);
    // запись в начало файла
    writeToStart(fileName);
    // чтение файла
    readFile(fileName);
}

// запись в файла данных введенных с клавиатуры
void writeInFile(char* fileName) {
    cout << "Ввод новой записи:\n";
    // переменные для ввода строк
    char name1[50];
    char name2[50];
    char name3[50];
    char year[50];
    char height[50];
    char weight[50];

    // ввод значений с клавиатуры
    cout << "Фамилия: ";
    cin >> name1;
    cout << "Имя: ";
    cin >> name2;
    cout << "Отчество: ";
    cin >> name3;
    cout << "День рождения: ";
    cin >> year;
    cout << "Рост: ";
    cin >> height;
    cout << "Вес: ";
    cin >> weight;

    // запись введеных данных в файл
    ofstream out(fileName, ios::app);
    // открытие файла fileName для записи
    if (out.is_open()) {
        // вывод данных из строк в файл
        out <<  name1 << " " << name2 << " " << name3 << " " << endl;
        out <<  year << endl;
        out <<  height << endl;
        out <<  weight << endl;
    }
    // закрытие файлового потока
    out.close();
}

// чтение файла fileName
void readFile(char *fileName) {
    // объявление переменной строчного типа
    string line;
    // объявление переменной файлового потока для чтения файла fileName
    ifstream in(fileName);

    cout << "Файл: " << fileName;
    cout << "\n--------------------------\n";

    // если файл удается открыть, считываем его построчно в переменную line и выводим в консоль
    if (in.is_open()){
        while (getline(in, line)){
            cout << line << std::endl;
        }
    }

    cout << "--------------------------\n";
    // закрытие файлового потока
    in.close();
}

// поиск записи по высоте и весу
void findByHeightAndWeight(char *fileName, int height, int weight) {
    // объявление переменной строчного типа
    string line;
    // объявление переменной файлового потока для чтения файла fileName
    ifstream in(fileName);

    int count = 0;
    int currentRecord = 1;
    int recordByHeight = 0;
    int recordByWeight = 0;
    // если файл удается открыть, считываем его построчно в переменную line
    if (in.is_open()) {
        while (getline(in, line)) {
            // если подзапись хранит рост
            if (count == 2) {
                // значения совпадают, запомним в переменную recordByHeight
                if (stoi(line) == height) {
                    recordByHeight = currentRecord;
                }
                count++;// переход к следующей подзаписи
            } 
            // если подзапись хранит вес
            else if (count == 3) {
                // значения совпадают, запомним в переменную recordByWeight
                if (stoi(line) == weight) {
                    recordByWeight = currentRecord;
                }
                // переход к следующей записип
                currentRecord++;
                // сброс счетчика подзаписей
                count = 0;
            } else {
                // переход к следующей подзаписи
                count++;
            }
        }
    }
    // если рост и вес несовпадают, закроем файловый поток и выйдем из функции
    if (recordByHeight != recordByWeight) {
        in.close();
        return;
    }

    int recordToDelete = recordByHeight;
    // закрытие потока файла
    in.close();
    // открытие файлового потока
    in.open(fileName);
    // чтение файла temp
    ofstream out("D:\\temp.txt", ios_base::trunc);


    currentRecord = 1;
    count = 0;
    // если файл удается открыть, считываем его построчно в переменную line
    if (in.is_open()) {
        while (getline(in, line)) {
            // если значения не совпадают, запишем их в файл, другие записи будут пропущены и удалены
            if (currentRecord != recordToDelete) {
                out << line << endl;
            }
            // переход к новой записи
            if (count == 3) {
                currentRecord++;
                count = 0;
            } else {
                // переход к следующей подзаписи
                count++;
            }
        }
    }

    // закрытие файловых потоков
    out.close();
    in.close();
    // откртые файловых потоков
    out.open(fileName, ios_base::trunc);
    in.open("D:\\temp.txt", ios_base::in);
    // копирование одного файла в другой
    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }
    // закрытие файловых потоков
    out.close();
    in.close();
}

// запись в начало файла
void writeToStart(char *fileName) {
    // файловые потоки для вывода и ввода в файл
    ofstream out;
    ifstream in(fileName);
    // строчная переменная
    string line;
    // открытие файла для записи
    out.open("D:\\temp.txt", ios_base::trunc);
    // если удается открыть и считать файл построчно, запишем его содержимое в файл temp
    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }
    // закрытие файловых потоков
    in.close();
    out.close();
    // открытие файловых потоков для уничтожения
    //ios::trunc обусловливает уничтожение содержимого файла с заданным именем и усечение дли­ны файла до нуля.
    in.open("D:\\temp.txt");
    out.open(fileName, ios_base::trunc);
    out.close();
    // ввод числа с клавиатуры
    int n;
    cout << "N = ";
    cin >> n;

    // создание записей в количестве nи запись в файл
    for (int i = 0; i < n; i++) {
        writeInFile(fileName);
    }
    // открытие файлового потока для добавления записей в конец файла
    out.open(fileName, ios_base::app);
    // запись в конец файла
    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }
}
