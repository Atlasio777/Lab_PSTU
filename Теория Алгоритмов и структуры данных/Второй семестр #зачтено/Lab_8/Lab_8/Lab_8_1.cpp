#include <iostream>

using namespace std;

struct point {
    char data;
    point* next;
};

struct point* init(char data);
struct point* addToHead(point* head, char data);
struct point* addToTail(point* tail, char data);
void addAfterElement(point* head, char data, char afterdata);
void printList(point* head);
void deleteList(point* head);

int main() {
    point *Head;
    point *Tail;
    
    Head = init('b');
    Tail = Head;
    Head = addToHead(Head, 'a');
    Tail = addToTail(Tail, 'c');
    Tail = addToTail(Tail, 'd');
    Head = addToHead(Head, 'h');
    printList(Head);

    cout << "Add '4' after 'c'\n";
    addAfterElement(Head, '4', 'c');
    printList(Head);

    deleteList(Head);
    Head = NULL;
    Tail = NULL;

    return 0;
}


struct point* init(char data) {
    struct point* firstPoint;
    firstPoint = (struct point*)malloc(sizeof(struct point));
    firstPoint -> data = data;
    firstPoint -> next = NULL;
    return(firstPoint);
}


struct point* addToHead(point *head, char data) {
    struct point *newElement = (struct point*)malloc(sizeof(point));
    newElement -> data = data;
    newElement -> next = head;
    return newElement;
}


struct point* addToTail(point* tail, char data) {
    struct point* newElement = (struct point*)malloc(sizeof(point));
    newElement->data = data;
    newElement->next = NULL;
    tail -> next = newElement;
    return newElement;
}


void addAfterElement(point *head, char data, char afterdata) {
    struct point* newElement = (struct point*)malloc(sizeof(point));
    (*newElement).data = data;
    point* current = head;
    while (current != NULL) {
        if ((*current).data == afterdata) {
            (*newElement).next = (*current).next;
            (*current).next = newElement;
            break;
        }
        current = current->next;
    }
}


void printList(point *head) {
    cout << "List = {";
    point* current = head;
    if (current == NULL) {
        cout << "Empty";
        return;
    }
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "}\n";
}


void deleteList(point *head) {
    point* current = head;
    while (current != NULL) {
        point* toDeleteElement = current;
        current = current->next;
        free(toDeleteElement);
    }
    cout << "List was deleted";
}
