// подколючение библиотек
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <math.h >


// главная функция
int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    // объявление переменных
    char str[100];// массив символов
    FILE* fin;// работа с файлами
    // открытие файлового потка указанного файла для чтения
    fin = fopen("D:\\file.txt", "r");


    printf("---ФАЙЛ после загрузки---\n");
    int count = 0;
    // считывание содержимого файла и вывод его строк на экран
    while (1) {
        // если строку удается считать в переменную str, выводим ее на экран
        if (NULL != fgets(str, 100, fin)){
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            printf("%s", str);
            count++;
        }
        else {
            // файл закончился выход из цикла
            break;
        }
    }

    // закрытие файла
    fclose(fin);
    // целочисленные переменные для ввода веса и роста
    int weight;
    int height;

    // ввод значений с клавиатуры
    printf("\nРост: ");
    scanf("%d", &height);
    printf("\nВест: ");
    scanf("%d", &weight);
    // открытие файлового потка указанного файла для чтения
    fin = fopen("D:\\file.txt", "r");

    // подготовка целочисленных переменных для работы
    count = 0;// колво обходов записи
    int currentRecord = 1;
    int recordByHeight = 0;
    int recordByWeight = 0;
    int currentWeight = 0;
    // выполнение бесконечного цикла
    while (1) {
        // пока удается считать данные из файла в строку str
        if (NULL != fgets(str, 100, fin)) {
            // обошли запись
            if (count == 4) {
                count = 0;
                // увеличение счетчика на единицу
                currentRecord++;
            }
            // если счетчик равен 2, подошли к значению РОСТ
            if (count == 2) {
                int currentHeight = 0;
                int i;
                for (i = 0; str[i] != '\0'; i++) {
               
                }
                i -=2;
                // вычисление роста из файла текущей записи в переменную currentHeight
                for (int j = 0; str[j] != '\0'; j++) {
                    currentHeight += ((int)str[j] - (int)'0') * (int)pow(10, i);
                    i--;
                }
                // если рост соответствует введенному с клавиетуры, запомним данную запись для удаления
                if (currentHeight == height) {
                    recordByHeight = currentRecord;
                }
            }
            // если счетчик равен 3, подошли к значению ВЕС
            if (count == 3) {
                int currentWeight = 0;
                int i;
                for (i = 0; str[i] != '\n'; i++);
                i--;
                // вычисление веста из файла текущей записи в переменную currentWeight
                for (int j = 0; str[j] != '\0'; j++) {
                    currentWeight += ((int)str[j] - (int)'0') * (int)pow(10, i);
                    i--;
                }
                // если вес соответствует введенному с клавиетуры, запомним данную запись для удаления
                if (currentWeight == weight) {
                    recordByWeight = currentRecord;
                }
            }
            // переход к подразделу записи
            count++;
        }
        else {
            // выход из бесконечного цикла
            break;
        }
    }
    // закрытие файла
    fclose(fin);

    // если колво записей с весом и ростом для удаления совпадают. Выполним удаление из файла
    int isNeedDeleted = 0;
    if (recordByHeight == recordByWeight) {
        isNeedDeleted = recordByHeight;
    }

    // объявление переменной для чтения файла
    FILE* temp;
    // если есть необходимость в удалении
    if (isNeedDeleted) {
        // открытие файлового потока для чтения и записи
        fin = fopen("D:\\file.txt", "r");
        temp = fopen("D:\\temp.txt", "wb");

        count = 0;
        currentRecord = 1;
        // бесконечный цикл копирования одного файла в другой
        while (1) {
            // чтение файла, пока не закончится
            if (NULL != fgets(str, 100, fin)) {
                // переход к следующей записи
                if (count == 4) {
                    count = 0;
                    currentRecord++;
                }
                // если данную запись удалять не нужно, перезапишем данную строку str в файл temp
                if (currentRecord != isNeedDeleted) {
                    fprintf(temp, "%s", str);
                }
                count++;
            }
            else {
                // выход из бесконечного цикла, если файл закончился
                break;
            }
        }
        // закрытие файловых потоков
        fclose(temp);
        fclose(fin);
    }

    // открытие файлового потока для чтения файла
    temp = fopen("D:\\temp.txt", "r");

    printf("\n---Содиржимое файла после удаления---\n");
    // считываем содержимое файла в бесконечном цикле
    while (1) {
        // пока текст файла удается считывать в переменную str
        if (NULL != fgets(str, 100, temp)) {
            // переход к новой записи
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            // вывод строки файла в консоль
            printf("%s", str);
            count++;
        }
        else {
            // выход из бесконечного цикла, если файл закончился
            break;
        }
    }
    // закрытие файлового потока
    fclose(temp);

    int k = 2;// добавление двух записей
    // открытие файлового потока для дозаписи в конец temp файла
    temp = fopen("D:\\temp.txt", "a");

    printf("\n");
    // массив символов для ввода с клавиатуры
    char input[50];

    // добавление двух записей
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            // запрос на ввод значения с клавиатуры
            if (j == 0) {
                printf("Имя:\n");
            } else if (j == 1) {
                printf("Дата рождения:\n");
            } else if (j == 2) {
                printf("Рост:\n");
            } else {
                printf("Вес:\n");
            }
           
            // ввод значения с клавиатуры
            scanf("%s", input);
            // запись в файл введенного значения
            fprintf(temp, "%s", input);
            fprintf(temp, "%s", "\n");
        }
    }
    // закрытие файла
    fclose(temp);
    // открытие файлового потока для чтения
    temp = fopen("D:\\temp.txt", "r");

    printf("\n---Файл после добавления данных---\n");
    // чтение и вывод содержимого файла temp.txt
    while (1) {
        // пока удается считать содержимое файла
        if (NULL != fgets(str, 100, temp)) {
            // переход к новой записи
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            // вывод текущего значения
            printf("%s", str);
            count++;// переход к подразделу записи
        }
        else {
            // выход из бесконечного цикла, если файл закончился
            break;
        }
    }
    // закрытие файлового потока
    fclose(temp);

}
