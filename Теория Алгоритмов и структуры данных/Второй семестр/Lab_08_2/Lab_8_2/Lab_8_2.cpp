// библиотека ввода-вывода
#include <iostream>
// пространство имен
using namespace std;

// структура данных
struct point {
    int data;
    point* next;
    point* prev;
};

// прототипы функций
struct point* init(int data);
struct point* addToHead(point* head, int data);
struct point* addToTail(point* tail, int data);
void deleteEvenNumbers(point** head, point** tail);
void printList(point* head);
void deleteList(point* head);


// главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    // объявление указателя на голову и хвост списка
    point* Head;
    point* Tail;
    // инициализация головы списка с передачей параметра
    Head = init(2);
    // хвост будет указывать на голову списка
    Tail = Head;
    // добавление значения в начало писка
    Head = addToHead(Head, 1);
    // добавление значения в конец писка
    Tail = addToTail(Tail, 3);
    // добавление значения в конец писка
    Tail = addToTail(Tail, 4);
    // добавление значения в начало писка
    Head = addToHead(Head, 0);
    // печать списка
    printList(Head);

    cout << "Удаление четных чисел\n";
    deleteEvenNumbers(&Head, &Tail);
    // печать списка
    printList(Head);
    // освобождение динамической памяти элементов списка
    deleteList(Head);

    return 0;
}


// инициализация головы списка
struct point* init(int data) {
    // указатель на структуру point
    struct point* firstPoint;
    // динамическое выделение памяти
    firstPoint = (struct point*)malloc(sizeof(struct point));
    // передача значения в объект
    (*firstPoint).data = data;
    // указатель на следующий элемент списка будет равен NULL
    (*firstPoint).next = NULL;
    (*firstPoint).next = NULL;
    // возврат указателя на структуру
    return(firstPoint);
}


struct point* addToHead(point* head, int data) {
    struct point* newElement = (struct point*)malloc(sizeof(point));
    (*newElement).data = data;
    (*newElement).next = head;
    (*newElement).prev = NULL;
    (*head).prev = newElement;
    return newElement;
}

// добавление значения в начало писка
struct point* addToTail(point* tail, int data) {
    // объявление указателя на структуру point с выделением памяти
    struct point* newElement = (struct point*)malloc(sizeof(point));
    // передача значения
    (*newElement).data = data;
    // следующий элемент списка указывает на NULL
    (*newElement).next = NULL;
    // предыдущий элемент списка указывает на хвост
    (*newElement).prev = tail;
    //следующий элемент списка будет хранить указатель на newElement
    (*tail).next = newElement;
    // возврат указателя
    return newElement;
}

// удаление четных значений из списка
void deleteEvenNumbers(point** head, point** tail) {
    // указатель на голову списка
    point* current = *head;
    // выход из функции если список пуст
    if (current == NULL) {
        return;
    }

    // движение с головы списка пока он не закончится
    while (current != NULL) {
        // если текущее значение четное - удалим его из списка
        if ((*current).data % 2 == 0) {
            // указатель на предыдущий элемент списка
            point* prev = (*current).prev;
            // указатель на следующий элемент списка
            point* next = (*current).next;
            // если указатель на следующий элемент не пуст, а на предудущий пуст, 
            // предыдущий элемент будет указывать на NUL,
            // а голова списка будет указывать на следующий элемент
            if (prev == NULL && next != NULL) {
                (*next).prev == NULL;
                *head = next;
            }
            // если указатель на следующий элемент пуст, а на предудущий нет
            else if (next == NULL && prev != NULL) {
                (*prev).next = NULL;
                *tail = prev;
            }
            // если указатели пусты
            else if (next == NULL && prev == NULL) {
                // голова и хвост будут указывать на NULL
                *head = NULL;
                *tail = NULL;
            } else {
                // иначе, следующий элемет предыдущего будет указывать на следующий
                (*prev).next = next;
                // а, предыдущий элемет следующего будет указывать на предыдущий
                (*next).prev = prev;
                // таким образом выкитывается удаляемый указатель на элемент списка и 
                // элементы находящиеся с двух сторон удаляемого элемент изменяют свои указатели
            }
            // удаление элемента
            point* toDelete = current;
            // присвоение элементу указатель на следующий элемент
            current = current->next;
            // освобождение динамической памяти
            free(toDelete);
        } else {
            // присвоение элементу указатель на следующий элемент
            current = current->next;
        }  
    }
}


// печать списка с головы
void printList(point* head) {
    cout << "Список = {";
    // указатель указыват на голову списка
    point* current = head;
    // если список пуст, вывести сообщение
    if (current == NULL) {
        cout << "Пусто...\n";
        return;
    }
    // обход элементов списка с головы, пока не дойдем до конца
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "}\n";
}

// освобождение динамической памяти элементов списка
void deleteList(point* head) {
    // начинаем движение по списку с головы
    point* current = head;
    // пока не конец списка
    while (current != NULL) {
        // элемент будет удалятся
        point* toDeleteElement = current;
        // будет хранить указатель на следующий элемент списка
        current = current->next;
        // освобождение динамической памяти списка
        free(toDeleteElement);
    }
    cout << "Список был удален...\n";
}
