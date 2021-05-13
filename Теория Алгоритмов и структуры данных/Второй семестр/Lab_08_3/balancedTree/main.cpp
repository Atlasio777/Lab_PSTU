#include <iostream>
using namespace std;


// ���������������� ������

// ��������� ��� ������������� ����� ������
struct Node 
{
    char key; // ����� �������
    unsigned char height; // ������ ���������
    Node* left; // c����� �� ������ ����
    Node* right; // ������ �� ������� ����
    // ������ ������� ��� �����
    Node(char k) 
    { 
        key = k; 
        left = right = 0; 
        height = 1; 
    } 
};

// ��������� ������ �������
unsigned char height(Node* currNode) 
{
    // ������� ������ ��������� ��������: 
    // ���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
    return currNode ? currNode->height : 0;
}

// �������� ����� ����� ���������
int difference(Node* currNode)
{
    // ������� ��������� �������
    return height(currNode->right) - height(currNode->left);
}

// ������� ������, ���� ������������������ ��������
void fixHeight(Node* currNode)
{
    // ������ ������ ����
    unsigned char hl = height(currNode->left);
    // ������ ������� ����
    unsigned char hr = height(currNode->right);
    // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
    currNode->height = (hl > hr ? hl : hr) + 1;
}

// ������ ������� ������ ����
Node* rotateRight(Node* currNode)
{
    // �������� ������ � ������� ����
    Node* q = currNode->left;  
    currNode->left = q->right;
    q->right = currNode;
    // ����� ������
    fixHeight(currNode);
    fixHeight(q);
    return q;
}

Node* rotateLeft(Node* currNode) // ����� ������� ������ ����
{
    // �������� ������� � ������ ����
    Node* tempNode = currNode->right; 
    currNode->right = tempNode->left;
    tempNode->left = currNode;
    fixHeight(currNode);
    fixHeight(tempNode);
    return tempNode;
}

// ������������ ��������� ���� 
Node* balance(Node* currNode)
{
    //���� ����� ��� ������ ������ ������� ������� ������ �������
    fixHeight(currNode);
    if (difference(currNode) == 2)
    {
        if (difference(currNode->right) < 0)
            currNode->right = rotateRight(currNode->right);
        return rotateLeft(currNode);
    }
    // ���� ������ ��� ����� ������ ������ ������� ����� �������
    if (difference(currNode) == -2) 
    {
        if (difference(currNode->left) > 0)
            currNode->left = rotateLeft(currNode->left);
        return rotateRight(currNode);
    }
    // ������������ �� �����
    return currNode; 
}

// ������� ����� k � ������ � ������ currNode
Node* insert(Node* currNode, char k)
{
    // ���� ������ ������ �������� ���
    if (!currNode) return new Node(k); 
    // ���� ���� ������ �������, ������� ��� ���������� �� ������ ����
    if (k < currNode->key) 
        currNode->left = insert(currNode->left, k);
    else
        // ���� ���� ������ �������, ������� �������� �� ������ ����
        currNode->right = insert(currNode->right, k); 
    // ������������� �������
    return balance(currNode); 
}

// ����������� ��������� ������
void display(Node* currNode, int n)
{
    if (currNode != NULL)
    {
        // �������� � ������� ������� ���������� �������� ����
        display((*currNode).right, n + 1);
        for (int i = 1; i <= n; i++) cout << "   ";
        // ����� �������� ��������
        cout << (*currNode).key << endl;
        // �������� � ������� ������ ���������� �������� ����
        display((*currNode).left, n + 1);
    }
}

// ������������ ������ � ������ ���� �����
void freeTree(Node* tree)
{
    // ���� ���� ����, ������� �� �������
    if (tree == NULL) return;
    // ���� ���� ����� ��������, ��������� ��� � �������
    if (tree->left)   freeTree(tree->left);
    // ���� ���� ������ ��������, ��������� ��� � �������
    if (tree->right)  freeTree(tree->right);
    // ������������ ������ ����
    free(tree);
}

int main()
{
	setlocale(LC_ALL, "RU");

    // ������ ��� ����
    Node* tree = NULL;
    char yesno;
    char value;

    // ���� ������
    while (true)
    {
    	printf_s("��������: ");
        cin >> value;
    	tree = insert(tree, value);

    	printf("���������� ����?\n");
    	printf("������� (y/n): "); cin >> yesno;
    	if (yesno == 'n' || yesno == 'N') break;
    }

    
    // ���������� ����� ����������������� �����
    int n = height(tree);
    cout << "����� �����: " << n << endl;
    // ����� ����������������� �����
    display(tree, 0);
    // ����������� ������ ����������������� �����
    freeTree(tree);





	cout << endl;
	system("pause");
	return 0;
}