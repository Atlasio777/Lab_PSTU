#include <iostream>
using namespace std;


// СБАЛАНСИРОВАННОЕ ДЕРЕВО

// структура для представления узлов дерева
struct Node 
{
    char key; // номер вершины
    unsigned char height; // высота поддерева
    Node* left; // cсылка на левого сына
    Node* right; // ссылка на правого сына
    // пустая вершина без детей
    Node(char k) 
    { 
        key = k; 
        left = right = 0; 
        height = 1; 
    } 
};

// получение высоты вершины
unsigned char height(Node* currNode) 
{
    // получим высоту следующим способом: 
    // если вершины нет, ответ 0 иначе высота поддерева этой вершины
    return currNode ? currNode->height : 0;
}

// разность высот между сыновьями
int difference(Node* currNode)
{
    // вручную посчитаем разницу
    return height(currNode->right) - height(currNode->left);
}

// обновим высоту, если сбалансированность нарушена
void fixHeight(Node* currNode)
{
    // высота левого сына
    unsigned char hl = height(currNode->left);
    // высота правого сына
    unsigned char hr = height(currNode->right);
    // высота вершины - это высота сына с макс высотой плюс 1
    currNode->height = (hl > hr ? hl : hr) + 1;
}

// правый поворот вокруг узла
Node* rotateRight(Node* currNode)
{
    // обменяем левого и правого сына
    Node* q = currNode->left;  
    currNode->left = q->right;
    q->right = currNode;
    // почин дерева
    fixHeight(currNode);
    fixHeight(q);
    return q;
}

Node* rotateLeft(Node* currNode) // левый поворот вокруг узла
{
    // обменяем правого и левого сына
    Node* tempNode = currNode->right; 
    currNode->right = tempNode->left;
    tempNode->left = currNode;
    fixHeight(currNode);
    fixHeight(tempNode);
    return tempNode;
}

// балансировка заданного узла 
Node* balance(Node* currNode)
{
    //если левый сын сильно больше правого сделаем правый поворот
    fixHeight(currNode);
    if (difference(currNode) == 2)
    {
        if (difference(currNode->right) < 0)
            currNode->right = rotateRight(currNode->right);
        return rotateLeft(currNode);
    }
    // если правый сын сибно больше левого сделаем левый поворот
    if (difference(currNode) == -2) 
    {
        if (difference(currNode->left) > 0)
            currNode->left = rotateLeft(currNode->left);
        return rotateRight(currNode);
    }
    // балансировка не нужна
    return currNode; 
}

// вставка ключа k в дерево с корнем currNode
Node* insert(Node* currNode, char k)
{
    // если дерево пустое создадим его
    if (!currNode) return new Node(k); 
    // если ключ больше вершины, вызомем это рекурсивно от левого сына
    if (k < currNode->key) 
        currNode->left = insert(currNode->left, k);
    else
        // если ключ меньше вершины, вызовем рекурсию от правго сына
        currNode->right = insert(currNode->right, k); 
    // отбалансируем вершину
    return balance(currNode); 
}

// изображение бинарного дерева
void display(Node* currNode, int n)
{
    if (currNode != NULL)
    {
        // передаем в функцию правого наследника текущего узла
        display((*currNode).right, n + 1);
        for (int i = 1; i <= n; i++) cout << "   ";
        // вывод текущего значения
        cout << (*currNode).key << endl;
        // передаем в функцию левого наследника текущего узла
        display((*currNode).left, n + 1);
    }
}

// освобождение памяти в каждом узле древа
void freeTree(Node* tree)
{
    // если узел пуст, возврат из функции
    if (tree == NULL) return;
    // если есть левый потопмок, передадим его в функцию
    if (tree->left)   freeTree(tree->left);
    // если есть правый потопмок, передадим его в функцию
    if (tree->right)  freeTree(tree->right);
    // освобождение памяти узла
    free(tree);
}

int main()
{
	setlocale(LC_ALL, "RU");

    // память под узел
    Node* tree = NULL;
    char yesno;
    char value;

    // ввод данных
    while (true)
    {
    	printf_s("Значение: ");
        cin >> value;
    	tree = insert(tree, value);

    	printf("Продолжить ввод?\n");
    	printf("Введите (y/n): "); cin >> yesno;
    	if (yesno == 'n' || yesno == 'N') break;
    }

    
    // количество узлов сбалансированного древа
    int n = height(tree);
    cout << "Колво узлов: " << n << endl;
    // вывод сбалансированного древа
    display(tree, 0);
    // особождение памяти сбалансированного древа
    freeTree(tree);





	cout << endl;
	system("pause");
	return 0;
}