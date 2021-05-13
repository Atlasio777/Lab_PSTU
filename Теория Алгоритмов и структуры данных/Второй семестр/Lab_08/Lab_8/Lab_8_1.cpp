// библиотека ввода-вывода
#include <iostream>
// пространство имен
using namespace std;

// структура данных
struct point {
    char data;
    point* next;
};

// прототипы функций
struct point* init(char data);
struct point* addToHead(point* head, char data);
struct point* addToTail(point* tail, char data);
void addAfterElement(point* head, char data, char afterdata);
void printList(point* head);
void deleteList(point* head);


// главная функция программы
int main() {
    setlocale(LC_ALL, "RU");
    // объявление указателя на голову и хвост списка
    point *Head;
    point *Tail;
    
    // инициализация головы списка с передачей параметра
    Head = init('b');
    // хвост будет указывать на голову списка
    Tail = Head;
    
    // добавление значения в начало писка
    Head = addToHead(Head, 'a');
    // добавление значения в конец писка
    Tail = addToTail(Tail, 'c');
    // добавление значения в конец писка
    Tail = addToTail(Tail, 'd');
    // добавление значения в начало писка
    Head = addToHead(Head, 'h');
    // печать списка
    printList(Head);

    cout << "Добавление значения '4' после зназчения 'c'\n";
    // вставка значения в список
    addAfterElement(Head, '4', 'c');
    // печать списка
    printList(Head);
    // освобождение динамической памяти элементов списка
    deleteList(Head);
    // сброс указателей на голову и хвост списка
    Head = NULL;
    Tail = NULL;

    return 0;
}

// инициализация головы списка
struct point* init(char data) {
    // указатель на структуру point
    struct point* firstPoint;
    // динамическое выделение памяти
    firstPoint = (struct point*)malloc(sizeof(struct point));
    // передача значения в объект
    firstPoint -> data = data;
    // указатель на следующий элемент списка будет равен NULL
    firstPoint -> next = NULL;
    // возврат указателя на структуру
    return(firstPoint);
}

// добавление значения в начало писка
struct point* addToHead(point *head, char data) {
    // объявление указателя на структуру point с выделением памяти
    struct point *newElement = (struct point*)malloc(sizeof(point));
    // передача значения
    newElement -> data = data;
    // следующий элемент списка будет хранить указатель на голову списка
    newElement -> next = head;
    // возврат указателя
    return newElement;
}

// добавление значения в конец писка
struct point* addToTail(point* tail, char data) {
    // объявление указателя на структуру point с выделением памяти
    struct point* newElement = (struct point*)malloc(sizeof(point));
    // передача значения
    newElement->data = data;
    // следующий элемент списка будет хранить указатель на NULL
    newElement->next = NULL;
    // следующий элемент списка будет хранить указатель на newElement
    tail -> next = newElement;
    // возврат указателя
    return newElement;
}

// вставка значения в список
void addAfterElement(point *head, char data, char afterdata) {
    // объявление указателя на структуру point с выделением памяти
    struct point* newElement = (struct point*)malloc(sizeof(point));
    // разыменование указателя с передачей ему значения
    (*newElement).data = data;
    // объявление указателя с присвоением указателя на голову списка
    point* current = head;
    // движение по списку с головы
    while (current != NULL) {
        // если значения совпадают
        if ((*current).data == afterdata) {
            // вставка значения в список в заданное место
            (*newElement).next = (*current).next;
            (*current).next = newElement;
            break;// экстренный выход после вставки
        }
        // изменяем указатель на следующий элемент в списке
        current = current->next;
    }
}

// печать списка с головы
void printList(point *head) {
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
void deleteList(point *head) {
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
