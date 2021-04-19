#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;


struct HUMAN {
	// ���� ���������
	// �������, ���, ��������
	char surname[50];
	char name[50];
	char midname[50];
	// ��� ��������
	int yearOfBirth;
	int grew;// ����
	int weight;// ���

public:

	// ����������
	~HUMAN()
	{
		// ������� �����
		clear();
	}

	// ������� �����
	void clear()
	{
		this->yearOfBirth = 0;
		this->grew = 0;
		this->weight = 0;
		strcpy(this->surname, "");
		strcpy(this->name, "");
		strcpy(this->midname, "");
	}

	// ������ ������ � ����
	void add(int yearOfBirth, int grew, int weight, 
		char surname[50], char name[50], char midname[50])
	{
		this->yearOfBirth = yearOfBirth;
		this->grew = grew;
		this->weight = weight;
		strcpy(this->surname, surname);
		strcpy(this->name, name);
		strcpy(this->midname, midname);
	}

	// ����� ������� �����
	void display() 
	{
		cout <<  this->surname << " " << this->name << " " << this->midname << endl;
		cout << "��� ��������: " << this->yearOfBirth << endl;
		cout << "����: " << this->grew << endl;
		cout << "����: " << this->weight << endl;
		cout << endl;
	}

	// ��������� ������ ��� �����
	const char* getLine()
	{
		char str[255];
		strcpy(str, this->surname);
		strcat(str, " ");
		strcat(str, this->name);
		strcat(str, " ");
		strcat(str, this->midname);
		strcat(str, " ");

		char string[6] = "";
		// ��� � ������
		_itoa(this->yearOfBirth, string, 10);
		strcat(str, string);
		strcat(str, " ");
		// ���� � ������
		_itoa(this->grew, string, 10);
		strcat(str, string);
		strcat(str, " ");
		// ��� � ������
		_itoa(this->weight, string, 10);
		strcat(str, string);

		strcat(str, "\n");
		return str;
	}

	const char* getSurname() { return this->surname; }
	const int getGrew() { return this->grew; }
	const int getWeight() { return this->weight; }
};

// �������� �� ������ ������ �������������� ��� ������������ ������
bool isdigit(char* s)
{
	int i = 0;
	int len = strlen(s);
	while (i < len) {
		if (s[i] < '0' || s[i] > '9') return false;
		i++;
	}
	return true;
}


// ������� ������� � �������� ������� �������
void insert(const int &index, int &totalCount, HUMAN *obj, 
	int yearOfBirth, int grew, int weight,
	char surname[50], char name[50], char midname[50])
{
	// �������� ������ � ����� ������, ����� �������� ����� �������
	int pos = -1;
	int t = 0;
	HUMAN objTemp[1000];// ����� ������ � ����������� ���������
	for (int i = 0; i < totalCount; i++) {
		// �������� � ��������� �������, ���� ����� �������� ����� �������
		if (i == index) {
			pos = i;
			t = 1;
		}
		// �������� �������� ������� � ������
		objTemp[i + t] = obj[i];
	}// for

	// ������� ������ �������� � ��������� �������
	objTemp[pos].add(yearOfBirth, grew, weight, surname, name, midname);
	totalCount++;

	// ����������� ������� � ������ ������ 
	for (int i = 0; i < totalCount; i++) {
		obj[i] = objTemp[i];
	}
}

// ���� ����� � ��������� �� ����
void correctingInsert(const char msg[100], int &value)
{// msg - ���������, value - ���������� ��������
	// ����� ������� �����
	int countTry = 0;
	char sValue[10];
	do {
		if (countTry > 0) {
			printf("������������ ���� �����!\n");
			system("pause");
			system("CLS");
		}
		cout << msg;
		cin >> sValue;
	} while (!isdigit(sValue));
	value = atoi(sValue);
}

void create(HUMAN* obj, int& totalCount, int inxInsert = -1)
{// bool inxInsert = -1 ������� / >= 0 - ������ ���������� ������
	char surname[50];
	char name[50];
	char midname[50];
	// ��� ��������
	int yearOfBirth;
	int grew;// ����
	int weight;// ���


	cout << "���������� ������\n";

	cout << "������� ��� ��������: ";
	cin >> surname;
	cin >> name;
	cin >> midname;

	// ���� ����� � ��������� �� ����
	correctingInsert("��� �������: ", yearOfBirth);
	correctingInsert("����: ", grew);
	correctingInsert("���: ", weight);

	// ���������� ������ � ������
	if (inxInsert == -1) 
		obj[totalCount++].add(yearOfBirth, grew, weight, surname, name, midname);
	// ������� ������� � �������� ������
	else insert(inxInsert, totalCount, obj, 
		yearOfBirth, grew, weight, 
		surname, name, midname);

	cout << "������ ������� ��������!\n";
}

// ����� ������� ������ �� �������
int searchBySurname(HUMAN* obj, int& totalCount)
{
	// ���� ������� ���������
	char surname[100];// ������� ��� �����
	printf("������� ������� ��� �������: ");
	scanf("%s", surname);

	// �����
	int inxFound = -1;// ������ ��������� ������ � �������
	for (int i = 0; i < totalCount; i++) {
		if (strcmp(surname, obj[i].getSurname()) == 0) {
			inxFound = i;// ������ �������
			break;
		}
	}

	if (inxFound < 0) printf("������ �� �������!\n");
	return inxFound;
}

// ������� ������ � ������ �������� ����� ��������� ������� �� �������
void insertData(HUMAN* obj, int& totalCount)
{
	int inxFound = searchBySurname(obj, totalCount);
	inxFound++;// ������� � ��������� ������
	if (inxFound < 0) printf("������ ����� �� �������!\n");
	else create(obj, totalCount, inxFound); // ������� ������ � ������
}

// ����� ���� ����������� ������
void displayAll(HUMAN* obj, int& totalCount)
{
	cout << "���������� � ���� �������:\n\n";
	if (totalCount > 0) {
		for (int i = 0; i < totalCount; i++)
			obj[i].display();
	}
	else cout << "������ ���...\n";
}

// �������� ��������� �������� �� ������� �� �������
bool removeElementByInx(HUMAN* obj, int& totalCount, int index)
{
	bool nResult = false;// ��������� ��������
	int t = 0;
	HUMAN objTemp[1000];// ����� ������ ��� ���������� ��������

	// �������� ������ � ����� ������ ��� ���������� ��������
	for (int i = 0; i < totalCount; i++) {
		// �������� �������� ������� � ������ �������� ���������
		if (i == index) {
			// ������� ������
			nResult = true;
			t = 1;
		}
		objTemp[i] = obj[i+t];
	}

	if (nResult) {
		// ����������� ������� � ������ ������ 
		for (int i = 0; i < totalCount; i++) {
			obj[i] = objTemp[i];
			// ������� ��������� �������
			if (i + 1 == totalCount) obj[i].clear();
		}
		totalCount--;
	}

	return nResult;
}

// �������� ��������� � ��������� ������ � �����
void removeData(HUMAN* obj, int& totalCount)
{
	int grew;// ����
	int weight;// ���
	// ���� ������ � ��������� ������������
	correctingInsert("����: ", grew);
	correctingInsert("���: ", weight);

	// ����� ������� ��� ��������, 
	// ��� �������� ��������� ���������� ����� � ����
	int countRemoved = 0;
	for (int i = 0; i < totalCount; i++) {
		if (obj[i].getGrew() == grew && obj[i].getWeight() == weight) {
			countRemoved += removeElementByInx(obj, totalCount, i);
			i--;
		}
	}

	if (countRemoved > 0) printf("������ �������!\n");
	else printf("������ � ���������� ���������� �� �������!\n");
}

// ������ ������� ��������� � �������� ����
bool writeArrObjToBinatyFile(const char* pathToFile, HUMAN* obj, unsigned size)
{
	// unsigned size// ����� ���� � �����
	FILE* iofile = NULL;// ��������� �� �������� �����

	// ������� ����, ���� ��� ��������� ���������� ������
	iofile = fopen(pathToFile, "wb");
	if (iofile == NULL) {
		printf("������ �������� �����");
		system("pause");
		return false;
	}
	
	// ������ ������� � �������� ����
	for (int i = 0; i < size; i++) {
		HUMAN tmp = obj[i];
		fwrite(&tmp, sizeof(HUMAN), 1, iofile);
	}
	// ��������� ����
	fclose(iofile);
	return true;
}

// ������ ������� ��������� �� ��������� �����
bool readArrObjFromBinatyFile(const char* pathToFile, HUMAN* obj, int &size)
{
	FILE *iofile = fopen(pathToFile, "rb");
	if (iofile == NULL)
	{
		printf("������ ������ �����...\n");
		return false;
	}
	while (!feof(iofile) && size <= 1000)
	{
		fread(&obj[size], sizeof(HUMAN), 1, iofile);
		size++;
	}
	size--;
	fclose(iofile);
	return true;
}

// ���������� ���� ���������
int menu()
{// ���������� ���� ���������
	system("CLS");//������� ���� �������
	cout << "1. ���������� �������\n";
	cout << "2. ������ ���� �������\n";
	cout << "3. �������� ������ ����� ��������� �������\n";
	cout << "4. �������� �������\n";
	cout << "0. �����\n";
	cout << "����: ";

	int choose;
	cin >> choose;
	//������� ���������� ������ ����
	return choose;
}



int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	HUMAN obj[1000];// �������
	int totalCount = 0;// ����������� ����� �������
	readArrObjFromBinatyFile("myFile.dat", obj, totalCount);
	
	bool loop = true;
	while (loop) {
		int choose = menu();
		system("CLS");
		switch (choose)
		{
		case 1: create(obj, totalCount); break;
		case 2: displayAll(obj, totalCount); break;
		case 3: insertData(obj, totalCount); break;
		case 4: removeData(obj, totalCount); break;
		case 0: loop = false; break;
		default: cout << "�������� �����...\n"; break;
		}//switch
		if (loop) system("pause");
	}//while 

	// ������ ����� � �������� ����
	writeArrObjToBinatyFile("myFile.dat", obj, totalCount);
	return 0;
}