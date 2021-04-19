#include <iostream>
using namespace std;


// ����� ���������������� ������
class UnidirectionalList {
private:
	// ����� ���� ������
	class NODE {
	public:
		NODE* pNext;// ��������� �� ��������� ������� �������
		int number;// �������� �������� �������

		// ����������� �������� ������ � ����������� ����������
		NODE(int n, NODE* pNext = nullptr)
		{
			this->number = n;
			this->pNext = pNext;
		}
	};
	// ��������� �� ������ ������
	NODE* head;
	int size; // ����� ���������

public:
	// ����������� �� ���������
	UnidirectionalList() { this->head = nullptr; this->size = 0; }

	// ���������� ������ 
	~UnidirectionalList() { this->clear(); }

	// �������� ����� ������
	void clear() { while (this->size) this->pop_front(); }

	// �������� ������� ��������
	void pop_front()
	{
		NODE* tmp = this->head;
		this->head = this->head->pNext;
		delete tmp;
		this->size--;
	}

	// ���������� �������� � ����� ������
	void push_back(int number)
	{
		if (this->head == nullptr) this->head = new NODE(number);
		else {
			NODE* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new NODE(number);
		}
		this->size++;
	}

	// �������� �������� �� �������
	bool removeAt(int inx)
	{
		if (inx > this->size) return false;
		if (inx == 0) this->pop_front();
		else {
			NODE* current = this->head;
			for (int i = 0; i < inx - 1; i++) {
				current = current->pNext;
			}

			NODE* toDelete = current->pNext;
			current->pNext = toDelete->pNext;
			delete toDelete;
			this->size--;
		}
		return true;
	}

	// ��������� ������� ������
	int getSize() { return this->size; }

	// ����� ���������� �� ��������� �������
	void displayAt(const int inx)
	{
		int counter = 0;
		NODE* current = this->head;

		while (current != nullptr)
		{
			if (counter == inx) {
				cout << current->number << " ";
				break;
			}
			current = current->pNext;
			counter++;
		}
	}

	// ����� ���� �������
	void displayAll()
	{
		if (this->size == 0) { cout << "������ ����...\n"; return; }
		cout << "\n������ ��������� �������:\n";
		for (int i = 0; i < this->size; i++) this->displayAt(i);
		cout << "\n";
	}

	// ����� ���������� �� ��������� �������
	NODE* getElementByIndex(int index)
	{
		NODE* curr = this->head;
		int counter = 0;
		// ������ ������������ ������� ���� � ������
		while (curr != nullptr)
		{// ���� ������ �� ������� ����, ���������� ����� �������� ���� � ��������
			//������� ���������� ����
			if (counter == index) return curr;
			// ������� � ������ ����
			curr = curr->pNext;
			counter++;
		}
	}

	// ������� �������� � ������ ����� �������� � �������� index
	bool insert(int value, int index)
	{
		NODE* curr = this->head;
		int counter = 0;
		// ������ ������������ ������� ���� � ������
		while (curr != nullptr)
		{// ���� ������ �� ������� ����, ���������� ����� �������� ���� � ��������
			// ������� �������� ����� �������� � �������� index
			if (counter + 1 == index) {
				NODE* obj = new NODE(value);
				obj->pNext = curr->pNext;
				curr->pNext = obj;
				this->size++;
				// ������ ������� ���������
				return true;
			}
			// ������� � ������ ����
			curr = curr->pNext;
			counter++;
		}// while
		// �� ������� �������� ������
		return false;
	}

	// �������� ������ (��� ���������� � ����������)
	void createList()
	{
		int nInputVal;
		cout << "[���������� ������]\n" <<
			"������� �������� ���������������, ������� Enter.\n" <<
			"����� �������� ���������� ���������, ������� ����.\n";
		this->clear();
		while (true) {
			cout << "���� �����: ";
			cin >> nInputVal;
			if (nInputVal == 0) break;
			this->push_back(nInputVal);
		}
	}

	// �������� � ���������, ������� � ��������� ������ 
	void addFromPos(int K, int pos)
	{
		for (int i = pos; i < pos + K; i++)
			insert(i + 1, i);
	}

	// ������� �� ������, x2 ���������, ������� � ��������� ������ x1
	bool removeRange(int x1, int x2)
	{
		//�������� �� ���������� ��������
		if (x1 < 0 || x1 + x2 >= this->getSize()) return false;

		// �������� ���������
		int temp = 0;
		for (int i = x1; i < x1 + x2; i++) {
			this->removeAt(i + temp);
			temp--;
		}

		return true;
	}

	// ������ ������ � ����
	bool saveToFile(const char fileName[50])
	{
		if (this->size == 0) return false;
		FILE* file;
		// �������� ����� ��� ������
		fopen_s(&file, fileName, "w");
		// ������ ������ � ����
		int value = 0;
		for (int i = 0; i < this->size; i++) {
			// ������ � ����
			value = getElementByIndex(i)->number;
			fprintf(file, "%d ", value);
		}
		// �������� ������ �����
		fclose(file);
		return true;
	}

	// ������ ����� � ������
	bool readFile(const char fileName[50])
	{
		FILE* file;
		// �������� ����� � ������ ������
		fopen_s(&file, fileName, "r");
		if (file == NULL) return false;
		//������ ����� �����
		int value = 0;
		while (!feof(file)){
			fscanf_s(file, "%d ", &value);
			// ���������� �������� � ������
			push_back(value);
		} 

		fclose(file);
		return true;
	}

};





int main()
{
	setlocale(LC_ALL, "RU");
	// �������� ������� ������ ����������������� ������
	UnidirectionalList list;
	list.createList();
	list.displayAll();

	
	// ������� �� ������, � ���������, ������� � ��������� ������
	int countToRemove = 0;
	int pos = 0;
	cout << "������� �� ������� ������� � ���������� K = ";
	cin >> countToRemove;
	cout << "�����, � �������� ����� ������ �������� N = ";
	cin >> pos;
	bool bSuccess = list.removeRange(pos, countToRemove);
	if (bSuccess) {
		cout << "������ ����� ��������..\n";
		list.displayAll();
	}

	// �������� � ���������, ������� � ��������� ������
	pos = 0;
	int countAdd = 0;
	cout << "�������� ��������� � ���������� K = ";
	cin >> countAdd;
	cout << "�����, � �������� ����� ������ ���������� N = ";
	cin >> pos;

	list.addFromPos(countAdd, pos);
	cout << "������ ����� ����������..";
	list.displayAll();

	// ���������� ������ � ����
	bSuccess = list.saveToFile("output.txt");
	if (bSuccess) {
		cout << "������ �������� � ����..\n";
	}
	cout << "������ ���������..\n";
	list.clear();
	list.displayAll();

	// ������ ������ �� ����� � ������
	cout << "������ �� �����..\n";
	bSuccess = list.readFile("output.txt");
	if (bSuccess) {
		list.displayAll();
	}else cout << "�� ������ ������� ���� \n";

	cout << endl;
	system("pause");
}