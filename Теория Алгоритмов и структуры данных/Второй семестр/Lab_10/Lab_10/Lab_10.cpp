// подключение библиотек
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// пространство имен
using namespace std;

// структура данных
struct Credit {
    string name;
    string kindOfCredit;
    int creditSum;
    int term;
    int flag;
};

// прототипы функций
void createDb(char* databaseName);
void loadDb(char* databaseName, vector<Credit> &credits);
void insertRecord(vector<Credit>& credits);
Credit *deleteRecord(vector<Credit>& credits, string name);
void updateRecord(vector<Credit>& credits, string name);
void printDb(vector<Credit>& credits);
void cancelDelete(vector<Credit>& books, Credit* credit);
void findByKindOfCredit(vector<Credit>& credits, string kindOfCredit);
void findMaxCredit(vector<Credit>& credits);
void save(vector<Credit>& credits, char* fileName);

// главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    // название базы данных
    char databaseName[] = "D:\\db.txt";
    // вектор хранящий массив структуры
    vector <Credit> credits;
    // указатель на структуру удаленного объекта
    Credit* lastDeleted = NULL;
    // флаг определения загрузки БД
    int dbWasLoaded = 0;
    // переменная для выполнения цикла программы
    int action = -1;
    // пока выполняется цикл
    while (action) {
        // вывод меню программы
        cout << "Меню:\n  1.Загрузка базы данных\n  2.Ввод данных\n  3.Удаление данных"
            << "\n  4.Отмена последнего удаления\n  5.Обновление данных\n  6.Печать\n  7.Поиск максимального кредита" 
            << "\n  8.Поиск по виду кредита\n  9.Сохранять данные\n  0.Выход";
        cout << "\n\nВведите пункт: ";
        // ввод пункта меню
        cin >> action;
        // данные для ввод с клавиатуры
        string helpStr, name1, name2, name3;
        // определение выбранного пункта
        switch (action) {
            // выход из цикла
            case 0: break;
            // Загрузка базы данных
            case 1: // если база уже была загружена
                if (dbWasLoaded) {
                    cout << "\nБаза данных уже загружена\n\n";
                    break;
                }
                dbWasLoaded = 1;
                // загрузка БД из файла в вектор
                loadDb(databaseName, credits);
                break;
            case 2: // Ввод данных
                insertRecord(credits);
                break;
            case 3:// Удаление данных
                // ввод ФИО с клавиатуры для удаления записи
                cout << "\nФамилия: ";
                cin >> name1;
                cout << "Имя: ";
                cin >> name2;
                cout << "Отчество: ";
                cin >> name3;
                // удаление записи из вектора по введенным ФИО
                lastDeleted = deleteRecord(credits, name1 + " " + name2 + " " + name3);
                break;
            case 4:// Отмена последнего удаления
                cancelDelete(credits, lastDeleted);
                break;
            case 5:// Обновление данных
                // ввод данных с клавиатуры
                cout << "\nФамилия: ";
                cin >> name1;
                cout << "Имя: ";
                cin >> name2;
                cout << "Отчество: ";
                cin >> name3;
                // редактирование данных по ФИО
                updateRecord(credits, name1 + " " + name2 + " " + name3);
                break;
            case 6:// вывод записей
                printDb(credits);
                break;
            case 7:// Поиск максимального кредита
                findMaxCredit(credits);
                break;
            case 8:// Поиск по виду кредита
                cout << "\nВид кредита: ";
                cin >> helpStr;
                findByKindOfCredit(credits, helpStr);
                break;
            case 9:// Сохранять данные
                save(credits, databaseName);
                break;
            default:
                cout << "\nInvalid action";
                break;
            
        }
    }
}

// загрузка БД из файла в вектор
void loadDb(char* databaseName, vector<Credit> &credits) {
    // открытие файлового потока для чтения файла databaseName
    ifstream in(databaseName);
    string line, name, kindOfCredit, creditSum, term;
    int count = 0;// счетчик разделов по записи
    // если файл успешно открыт
    if (in.is_open()) {
        // считываем файл построчно в переменную line
        while (getline(in, line)) {
            // получение значений из записи
            // название
            if (count == 0) {
                name = line;
                count++;
            } 
            // сумма кредита
            else if (count == 1) {
                creditSum = line;
                count++;
            } 
            // вид кредита
            else if (count == 2) {
                kindOfCredit = line;
                count++;
            } else {
                // запись считанных данных о записи в структуру и 
                // добавление данного объекта структуры в вектор credits 
                term = line;
                // объект структуры
                Credit* credit = new Credit();
                // копирование значения в поля объекта
                credit->name = name;
                credit->kindOfCredit = kindOfCredit;
                credit->creditSum = stoi(creditSum);
                credit->term = stoi(term);
                credit->flag = 0;
                // запись объекта структуры в вектор credits
                credits.push_back(*credit);
                count = 0;// сброс счетчика разделов
            }
        }
    }

    cout << "\nБД была загружена\n\n";
    // закрытие файлового потока
    in.close();
}

// Ввод данных
void insertRecord(vector<Credit>& credits) {
    // создание указателя на структуры с выделением динамической памяти для объекта
    Credit* credit = new Credit();
    // объявление строчных переменных для ввода значений с клавиатуры
    string name1, name2, name3;

    // запрос на ввод данных и ввод данных с клавиатуре о клиенте и кредите
    cout << "\nСоздание новой записи\nФамилия: ";
    cin >> name1;
    cout << "Имя: ";
    cin >> name2;
    cout << "Отчество: ";
    cin >> name3;
    // копирование значений в поле объекта структуры
    credit->name = name1 + " " + name2 + " " + name3;
    cout << "Сумма кредита: ";
    cin >> credit->creditSum;
    cout << "Вид кредита: ";
    cin >> credit->kindOfCredit;
    cout << "Термин: ";
    cin >> credit->term;
    credit->flag = 1;

    cout << "\nЗапись была добавлена\n\n";
    // добавление объекта в который были добавлены введенные значения в вектор credits
    credits.push_back(*credit);
}

// удаление записи из вектора по введенным ФИО
Credit* deleteRecord(vector<Credit>& credits, string name) {
    // объявление указателя на структуру Credit
    Credit* toDelete = new Credit();
    // обход всех записей вектора
    for (int i = 0; i < credits.size(); i++) {
        // если полуенное ФИО совпадает с записью
        if (credits.at(i).name == name) {
            // копирование данных в указатель на объект Credit
            toDelete->name = credits.at(i).name;
            toDelete->creditSum = credits.at(i).creditSum;
            toDelete->kindOfCredit = credits.at(i).kindOfCredit;
            toDelete->term = credits.at(i).term;
            cout << "\nУдаление кредита: { " << credits.at(i).name << " : " << credits.at(i).creditSum <<
                " : " << credits.at(i).kindOfCredit << " : " << credits.at(i).term << " }\n\n";
            // удаление записи по индексу из вектора
            credits.erase(credits.begin() + i);
        }
    }
    // возврат указателя на удаленный объект toDelete
    return toDelete;
}

// Отмена последнего удаления
void cancelDelete(vector<Credit>& credits, Credit* credit) {
    // добавить в структуру полученный функцие указатель на объект
    credits.push_back(*credit);
    cout << "\n\nОтмена последнего удаления\n\n";
}

// редактирование данных по ФИО
void updateRecord(vector<Credit>& credits, string name) {
    // объявление указателя на структуру со значением NULL
    Credit* credit = NULL;
    // обход всех записей в поиске нужной
    for (int i = 0; i < credits.size(); i++) {
        // если найдена запись с данными ФИО
        if (credits.at(i).name == name) {
            // запишем в переменную ссылку на объекта структуры
            credit = &credits.at(i);
        }
    }

    // если запись не найдена, выйдем из функции
    if (credit == NULL) {
        cout << "Ничего не найдено!";
        return;
    }

    // объеявление переменнах для ввода данных с клавиатуры
    string name1, name2, name3;
    // вывод данных об обновляемом кредите
    cout << "Обновление кредита: { " << credit->name << " : " << credit->creditSum <<
        " : " << credit->kindOfCredit << " : " << credit->term << " }";
    // ввод данных с клавиетары для изменения значений записи
    cout << "\nЗамена фамилии -> ";
    cin >> name1;
    cout << "\nЗамена имени -> ";
    cin >> name2;
    cout << "\nЗамена отчества -> ";
    cin >> name3;
    // копирование введенных данных в объект структуры
    credit->name = name1 + " " + name2 + " " + name3;
    cout << "Замена суммы кредита -> ";
    cin >> credit->creditSum;
    cout << "Замена вида кредита -> ";
    cin >> credit->kindOfCredit;
    cout << "Замена термина -> ";
    cin >> credit->term;
    cout << "\n";
}

// вывод записей
void printDb(vector<Credit>& credits) {
    cout << "\ndb.txt";
    cout << "\n---------------------------------------------";
    // обход все записей вектора для вывода данных в консоль
    for (int i = 0; i < credits.size(); i++) {
        // получение записи вектора по инденксы и вывод даных на экран
        cout << "\nCredit { " << credits.at(i).name << " : " << credits.at(i).creditSum <<
            " : " << credits.at(i).kindOfCredit << " : " << credits.at(i).term << " }";
    }
    cout << "\n---------------------------------------------\n\n";
}

// Поиск максимального кредита
void findMaxCredit(vector<Credit>& credits) {
    cout << "\nПоиск максимального кредита...";
    int maxCredit = 0;// значение максимального кредита
    int index = 0;// индекс максимального кредита
    // обход всех записей вектора с кредитами
    for (int i = 0; i < credits.size(); i++) {
        // если текущая сумма кредита больше maxCredit, запомним индекс
        if (credits.at(i).creditSum > maxCredit) {
            maxCredit = credits.at(i).creditSum;
            index = i;
        }
    }
    // вывод максимального кредита
    cout << "\nМаксимальный кредит { " << credits.at(index).name << " : " << credits.at(index).creditSum <<
        " : " << credits.at(index).kindOfCredit << " : " << credits.at(index).term << " }\n\n";
}

// Поиск по виду кредита
void findByKindOfCredit(vector<Credit>& credits, string kindOfCredit) {
    // обход всех записей вектора с кредитами
    for (int i = 0; i < credits.size(); i++) {
        // если текущий вид кредита совпадает с заданным
        if (credits.at(i).kindOfCredit == kindOfCredit) {
            // вывод данных с текущей записью
            cout << "\nВид кредита { " << credits.at(i).name << " : " << credits.at(i).creditSum <<
                " : " << credits.at(i).kindOfCredit << " : " << credits.at(i).term << " }\n\n";
        }
    }
}

// Сохранять данные в файл
void save(vector<Credit>& credits, char* fileName) {
    // объявление переменной файлового потока
    ofstream out(fileName, ios::trunc);
    // если файл удалось открыть
    if (out.is_open()) {
        // запишем все записи в файл
        for (int i = 0; i < credits.size(); i++) {
            out << credits.at(i).name << endl;
            out << credits.at(i).creditSum << endl;
            out << credits.at(i).kindOfCredit << endl;
            out << credits.at(i).term << endl;
        }
    }

    cout << "\nБаза данных была сохранена\n\n";
    // закрытие файлового потока
    out.close();
}