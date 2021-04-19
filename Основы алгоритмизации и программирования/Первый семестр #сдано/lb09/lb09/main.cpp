#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// подсчет гласных букв в строке
int countVowel(char* str)
{//определим €вл€етс€ ли данный символ гласной буковой
	// строка из английских и русских глассных букв
	char vowel[] = "AEIOUYaeiouyауоыиэ€юЄеј”ќџ»Ёяё®≈";
	int len = strlen(vowel);// получение длины строки
	int lenStr = strlen(str);// длина строки
	int countSymbs = 0;// колво гласных букв в текущей строке

	// обход строки дл€ проверки каждого символа
	for (int i = 0; i < lenStr; i++) {
		char ch = str[i];// текущий символ строки
		// обход всех гласных символов англ./рус.
		for (int j = 0; j < len; j++) {
			// если текущий символ строки €вл€етс€ гласной буквой
			if (ch == vowel[j]) {
				countSymbs++;// подсчет количества 
				break; // выход из цикла for j
			}
		}
	}
	// возврат количества гласных символов
	return countSymbs;
}

// чтение файла в массив строк
bool readFileToArray(const char fileName[50], char str[100][256], int &count)
{
	FILE* file;
	// открытие файла в режиме чтени€
	fopen_s(&file, fileName, "r");
	if (file == NULL) return false;
	//чтение строк файла
	const int MAXLINE = 256;
	char buf[MAXLINE];
	while (fgets(buf, MAXLINE, file) != NULL)
	{
		// убираем из строки символ перехода на новую (\n)
		int index = strlen(buf) - 1;
		if(buf[index] == '\n') buf[index] = '\0';
		// добавление элемента 
		strcpy_s(str[count++], buf);
	}

	fclose(file);
	return true;
}

// запись строк в файл
bool saveFile(const char fileName[50], char str[100][256], const int& count)
{
	FILE* file;
	file = fopen(fileName, "w");
	// —копировать в файл F2 строки, начина€ с   до   + 5.
	int K = 0;
	printf("K = "); cin >> K;
	K--;// поправка на индексацию с нул€
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
	int size = 0;// колво строк
	char str[100][256];// содержимое файла 1
	char str2[100][256];// содержимое файла 2
	bool bSucc = readFileToArray("F1.txt", str, size);
	if (bSucc) {
		for (int i = 0; i < size; i++)
			printf("%s\n", str[i]);
		// запись нового файла
		bSucc = saveFile("F2.txt", str, size);
		if (bSucc) {
			// чтение файла F2
			size = 0;
			readFileToArray("F2.txt", str2, size);
			printf("—одержимое файла: F2.txt\n");
			// вывод строк файла F2.txt и подсчет в нем гласных букв
			int totalCount = 0;// колво гласных букв =
			for (int i = 0; i < size; i++)
			{
				totalCount += countVowel(str2[i]);
				printf("%s\n", str2[i]);
			}
			printf("\n олво гласных букв файла: F2.txt = %d\n", totalCount);
		} else printf("‘айл F2.txt записать не удалось!\n");
	}
	else printf("‘айл F1.txt считать не удалось!\n");
	
	cout << endl;
	system("pause");
}