#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ������� ������� ���� � ������
int countVowel(char* str)
{//��������� �������� �� ������ ������ ������� �������
	// ������ �� ���������� � ������� �������� ����
	char vowel[] = "AEIOUYaeiouy�����������������ި�";
	int len = strlen(vowel);// ��������� ����� ������
	int lenStr = strlen(str);// ����� ������
	int countSymbs = 0;// ����� ������� ���� � ������� ������

	// ����� ������ ��� �������� ������� �������
	for (int i = 0; i < lenStr; i++) {
		char ch = str[i];// ������� ������ ������
		// ����� ���� ������� �������� ����./���.
		for (int j = 0; j < len; j++) {
			// ���� ������� ������ ������ �������� ������� ������
			if (ch == vowel[j]) {
				countSymbs++;// ������� ���������� 
				break; // ����� �� ����� for j
			}
		}
	}
	// ������� ���������� ������� ��������
	return countSymbs;
}

// ������ ����� � ������ �����
bool readFileToArray(const char fileName[50], char str[100][256], int &count)
{
	FILE* file;
	// �������� ����� � ������ ������
	fopen_s(&file, fileName, "r");
	if (file == NULL) return false;
	//������ ����� �����
	const int MAXLINE = 256;
	char buf[MAXLINE];
	while (fgets(buf, MAXLINE, file) != NULL)
	{
		// ������� �� ������ ������ �������� �� ����� (\n)
		int index = strlen(buf) - 1;
		if(buf[index] == '\n') buf[index] = '\0';
		// ���������� �������� 
		strcpy_s(str[count++], buf);
	}

	fclose(file);
	return true;
}

// ������ ����� � ����
bool saveFile(const char fileName[50], char str[100][256], const int& count)
{
	FILE* file;
	file = fopen(fileName, "w");
	// ����������� � ���� F2 ������, ������� � � �� � + 5.
	int K = 0;
	printf("K = "); cin >> K;
	K--;// �������� �� ���������� � ����
	if (K + 5 > count) return false;
	for (int i = K; i < K+5; i++)
	{
		fprintf(file, "%s", str[i]);
		if(i+1 <K+5) fprintf(file, "%s\n", "");
	}
	fclose(file);
	return true;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int size = 0;// ����� �����
	char str[100][256];// ���������� ����� 1
	char str2[100][256];// ���������� ����� 2
	bool bSucc = readFileToArray("F1.txt", str, size);
	if (bSucc) {
		for (int i = 0; i < size; i++)
			printf("%s\n", str[i]);
		// ������ ������ �����
		bSucc = saveFile("F2.txt", str, size);
		if (bSucc) {
			// ������ ����� F2
			size = 0;
			readFileToArray("F2.txt", str2, size);
			printf("���������� �����: F2.txt\n");
			// ����� ����� ����� F2.txt � ������� � ��� ������� ����
			int totalCount = 0;// ����� ������� ���� =
			for (int i = 0; i < size; i++)
			{
				totalCount += countVowel(str2[i]);
				printf("%s\n", str2[i]);
			}
			printf("\n����� ������� ���� �����: F2.txt = %d\n", totalCount);
		} else printf("���� F2.txt �������� �� �������!\n");
	}
	else printf("���� F1.txt ������� �� �������!\n");
	
	cout << endl;
	system("pause");
}