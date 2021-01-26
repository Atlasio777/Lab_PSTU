#include <iostream>
#include <iomanip>

using namespace std;

struct point {
    char data;
    point* left;
    point* right;
};

point* initTree(char data);
void addToTree(point* root, char data);
void printTree(point* p, int indent);
int findH(point* root);

int main() {
    point* Root = initTree('k');
    
    addToTree(Root, 'f');
    addToTree(Root, 'c');
    addToTree(Root, 'h');
    addToTree(Root, 'y');
    addToTree(Root, 'a');
    addToTree(Root, 'o');
    addToTree(Root, 'b');
    addToTree(Root, 'e');

    cout << "\n";
    printTree(Root, 0);

    int h = findH(Root);
    cout << "H = " << h;

}

point* initTree(char data) {
    struct point* newElement = (struct point*)malloc(sizeof(struct point));
    (*newElement).data = data;
    (*newElement).right = NULL;
    (*newElement).left = NULL;
    return newElement;
}

void addToTree(point* root, char data) {
    cout << "\nCurrent root = " << (*root).data;
    if ((*root).data < data) {
        cout << "Left";
        if ((*root).right != NULL) {
            addToTree((*root).right, data);
        } else {
            struct point* newElement = (struct point*)malloc(sizeof(struct point));
            (*newElement).data = data;
            (*newElement).right = NULL;
            (*newElement).left = NULL;
            (*root).right = newElement;
        }
    } else if ((*root).data > data) {
        cout << "Right";
        if ((*root).left != NULL) {
            addToTree((*root).left, data);
        } else {
            struct point* newElement = (struct point*)malloc(sizeof(struct point));
            (*newElement).data = data;
            (*newElement).right = NULL;
            (*newElement).left = NULL;
            (*root).left = newElement;
        }
    } else {
        cout << "MIddle";
        return;
    }
}

int findH(point* root) {
    if (root == NULL) {
        return 0;
    }
    int hR = findH((*root).right);
    int hL = findH((*root).left);

    if (hR > hL) {
        return ++hR;
    } else {
        return ++hL;
    }
}

void printTree(point* p, int indent)
{
    if (p != NULL) {
        if (p->right) {
            printTree(p->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
        std::cout << p->data << "\n ";
        if (p->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printTree(p->left, indent + 4);
        }
    }
}
