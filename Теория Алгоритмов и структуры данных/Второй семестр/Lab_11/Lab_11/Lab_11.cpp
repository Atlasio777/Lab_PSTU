// подключение библиотек
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// пространство имен
using namespace std;

// структура данных
struct Node {
    string name;
    string pasport;
};
// структура данных
struct Bucket {
    int hash;
    vector<Node> buckets;
};

// прототипы функций
void printHashTable(vector<Bucket>& hashTable);
void insert(vector<Bucket>& hashTable, string name, string pasport);
void remove(vector<Bucket>& hashTable, string key);
void find(vector<Bucket>& hashTable, string key);
void loadFromFile(char* databaseName, vector<Bucket>& hashTable);
void save(char* fileName, vector<Bucket>& hashTable);
void countConflict(vector<Bucket>& hashTable);

// главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    // объявление объекта вектора структуры Bucket
    vector<Bucket> hashTable;
    int size = 20;// размерность вектора 20
    // название файла
    char fileName[] = "D:\\lab11.txt";
    // заполнение вектора данными от 0 до 19
    for (int i = 0; i < 20; i++) {
        Bucket* bucket = new Bucket();
        bucket->hash = i;
        hashTable.push_back(*bucket);
    }

    int help;
    // загрузка данных в хэш таблицу из файла
    loadFromFile(fileName, hashTable);
    // печать хэш-таблицы
    printHashTable(hashTable);

    cout << "\nВведите колво записей для вставки в хэш-таблицу: ";
    cin >> help;
    // добавление в вектор заданное с клавиатуры колво записей help
    for (int i = 0; i < help; i++) {
        // объявление переменных для ввод с клавиатуры
        string name, pasport;
        // ввод данных с клавиатуры
        cout << "\nСоздание новой записи...\nВведите имя: ";
        cin >> name;
        cout << "Введите паспорт: ";
        cin >> pasport;
        // добавление данных в хэш-таблицу
        insert(hashTable, name, pasport);
    }
    // печать хэш-таблицы
    printHashTable(hashTable);

    cout << "\nВведите колво записей для удаления и хэш-таблицы: ";
    cin >> help;
    // удаление записей в количестве help из таблицы
    for (int i = 0; i < help; i++) {
        string key;// переменная для ввод ключа
        cout << "\nУдаление записи по ключу...\nВвод ключа: ";
        cin >> key;
        // удаление данных из таблицы по ключу
        remove(hashTable, key);
    }
    // печать хэш-таблицы
    printHashTable(hashTable);

    cout << "\nКоличество записей для поиска: ";
    cin >> help;
    // выполнение цикла заданное колво раз
    for (int i = 0; i < help; i++) {
        // объявление переменной строчного типа
        string key;
        cout << "\n\Поиск записи...\nВвод ключа: ";
        cin >> key;
        // поиск даных в хэш-таблице по ключу
        find(hashTable, key);
    }

    // подсчет количества коллизий
    countConflict(hashTable);
    // сохранение данных в файл
    save(fileName, hashTable);
}



// добавление даных в хэш-таблицу
void insert(vector<Bucket>& hashTable, string name, string pasport) {
    // объявление указателя на тип Node с выделением динамической памяти
    Node* node = new Node();
    // уставновка значений в поля объекта структуры
    node->name = name;
    node->pasport = pasport;

    // вычисление значения хэша ля таблицы
    int hash = (node->name.length()) % (hashTable.size());
    // флажок, содержит ли хэш-таблица уже такую запись
    int isContains = 0;
    // обход записей вектора заданного хэша
    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        // если такая запись есть, установим флажок и выйдем из цикла
        if (hashTable.at(hash).buckets.at(i).name == name) {
            isContains = 1;
            break;
        }
    }
    // если такой записи не существует, добавим объект в хэш-таблицу
    if (!isContains) {
        hashTable.at(hash).buckets.push_back(*node);
    }
}

// печать хэш-таблицы
void printHashTable(vector<Bucket>& hashTable) {
    cout << "\n------------------------------------ ХЭШ-ТАБЛИЦА ------------------------------------";
    // обход всех записей хэш-талицы (вектора)
    for (int i = 0; i < hashTable.size(); i++) {
        cout << "\nхэш = " << hashTable.at(i).hash << "   ";
        for (int j = 0; j < hashTable.at(i).buckets.size(); j++) {
            // вывод данных в консоль
            cout << " { " << hashTable.at(i).buckets.at(j).name << " : " << hashTable.at(i).buckets.at(j).pasport << " } ->";
        }
    }
    cout << "\n--------------------------------------------------------------------------------\n";
}

// удаление данных из таблицы по ключу
void remove(vector<Bucket> &hashTable, string key) {
    // получение хэша таблицы
    int hash = key.length() % 20;
    // обход данных заданого хэша таблицы
    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        // если ключ совпадает с записью заданного хеша, удалим данную запись из вектора (хэш-таблицы)
        if (key == hashTable.at(hash).buckets.at(i).name) {
            hashTable.at(hash).buckets.erase(hashTable.at(hash).buckets.begin() + i);
        }
    }
}

// поиск даных в хэш-таблице по ключу
void find(vector<Bucket>& hashTable, string key) {
    // получение хэша таблицы
    int hash = key.length() % 20;
    // обход данных заданого хэша таблицы
    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        // если ключ совпадает с записью заданного хеша, выведем данную запись из вектора (хэш-таблицы) на экран
        if (key == hashTable.at(hash).buckets.at(i).name) {
            cout << " { " << hashTable.at(hash).buckets.at(i).name << " : " << hashTable.at(hash).buckets.at(i).pasport << " }";
        }
    }
}


// загрузка данных в хэш таблицу из файла
void loadFromFile(char* fileName, vector<Bucket>& hashTable) {
    // объявление переменной для работы с файлом 
    ifstream in(fileName);
    // объявление переменных для получения значений в них
    string line, name, pasport;

    int count = 0;// колво подзаписей записи
    // если удалось открыть файл
    if (in.is_open()) {
        // считывание файла построчно
        while (getline(in, line)) {
            // если данная операция выполняется
            if (count == 0) {
                // запишем строку в переменную name и перейдем на следующую подзапись
                name = line;
                count++;
            } else {
                // запишем строку в переменную pasport 
                pasport = line;
                count = 0;// сбросим счетчик подзаписи
                // добавим даные в хэш-таблицу
                insert(hashTable, name, pasport);
            }
        }
    }
    // закрытие файлового потока
    in.close();
}

// подсчет количества коллизий
void countConflict(vector<Bucket>& hashTable) {
    int count = 0;// колво коллизий
    // обход всех записей хэш-таблицы
    for (int i = 0; i < hashTable.size(); i++) {
        // если условие выполняется, прибавим количество коллизий в счетчик
        if (hashTable.at(i).buckets.size() > 1) {
            count += hashTable.at(i).buckets.size() - 1;
        }
    }
    // вывод результатов подсчета
    cout << "\nКоличество коллизий: " << count << "\n";
}

// сохранение данных хэш-таблицы в файл
void save(char* fileName, vector<Bucket>& hashTable) {
    // объявление переменной для ввода даных в файл
    ofstream out(fileName, ios::trunc);
    // если заданный файл удалось
    if (out.is_open()) {
        // обход всех записей хэш-таблицы
        for (int i = 0; i < hashTable.size(); i++) {
            // вывод данных всех хэшей таблицы в файл
            for (int j = 0; j < hashTable.at(i).buckets.size(); j++) {
                out << hashTable.at(i).buckets.at(j).name << endl;
                out << hashTable.at(i).buckets.at(j).pasport << endl;
            }
        }
    }
    // закрытие файла после записи
    out.close();
}



