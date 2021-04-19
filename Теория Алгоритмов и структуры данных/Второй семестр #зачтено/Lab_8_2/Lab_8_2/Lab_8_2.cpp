#include <iostream>

using namespace std;

struct point {
    int data;
    point* next;
    point* prev;
};

struct point* init(int data);
struct point* addToHead(point* head, int data);
struct point* addToTail(point* tail, int data);
void deleteEvenNumbers(point** head, point** tail);
void printList(point* head);
void deleteList(point* head);

int main() {
    point* Head;
    point* Tail;

    Head = init(2);
    Tail = Head;
    Head = addToHead(Head, 1);
    Tail = addToTail(Tail, 3);
    Tail = addToTail(Tail, 4);
    Head = addToHead(Head, 0);
    printList(Head);

    cout << "Delete even numbers\n";
    deleteEvenNumbers(&Head, &Tail);
    printList(Head);

    deleteList(Head);

    return 0;
}


struct point* init(int data) {
    struct point* firstPoint;
    firstPoint = (struct point*)malloc(sizeof(struct point));
    (*firstPoint).data = data;
    (*firstPoint).next = NULL;
    (*firstPoint).next = NULL;
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


struct point* addToTail(point* tail, int data) {
    struct point* newElement = (struct point*)malloc(sizeof(point));
    (*newElement).data = data;
    (*newElement).next = NULL;
    (*newElement).prev = tail;
    (*tail).next = newElement;
    return newElement;
}

void deleteEvenNumbers(point** head, point** tail) {
    point* current = *head;
    if (current == NULL) {
        return;
    }
    while (current != NULL) {
        if ((*current).data % 2 == 0) {
            point* prev = (*current).prev;
            point* next = (*current).next;
            if (prev == NULL && next != NULL) {
                (*next).prev == NULL;
                *head = next;
            } else if (next == NULL && prev != NULL) {
                (*prev).next = NULL;
                *tail = prev;
            } else if (next == NULL && prev == NULL) {
                *head = NULL;
                *tail = NULL;
            } else {
                (*prev).next = next;
                (*next).prev = prev;
            }
            point* toDelete = current;
            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }  
    }
}


void printList(point* head) {
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


void deleteList(point* head) {
    point* current = head;
    while (current != NULL) {
        point* toDeleteElement = current;
        current = current->next;
        free(toDeleteElement);
    }
    cout << "List was deleted";
}
