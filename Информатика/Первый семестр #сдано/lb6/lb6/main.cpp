#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void addPoint(char* str)
{
	int len = strlen(str);
	if (str[len - 1] != '.') {
		str[len] = '.';
		str[len + 1] = '\0';
	}
}


int splitStrBySymbol(char* str, const char separetor[], int* rows, char strings[100][50])
{
	char* tmpStr;
	
	tmpStr = strtok(str, separetor);
	
	do {
		
		strcpy(strings[*rows], tmpStr);
		(*rows)++;
		
		tmpStr = strtok(NULL, separetor);
	} while (tmpStr != NULL);
	return 0;
}

void trim(char* s)
{
	
	int i = 0, j;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i++;
	}
	if (i > 0)
	{
		for (j = 0; j < strlen(s); j++)
		{
			s[j] = s[j + i];
		}
		s[j] = '\0';
	}

	
	i = strlen(s) - 1;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i--;
	}
	if (i < (strlen(s) - 1))
	{
		s[i + 1] = '\0';
	}
}


bool compareStrings(char* str1, char* str2)
{
	int len = strlen(str1);
	if (len != strlen(str2)) return false;
	for (int i = 0; i < len; i++) {
		if (tolower(str1[i]) != tolower(str2[i])) return false;
	}
	return true;
}



int main()
{
	setlocale(LC_ALL, "RU");
	

	
	char str[256];

	cout << "str = ";
	gets_s(str);
	trim(str);
	addPoint(str);

	cout << str << endl;
	str[strlen(str) - 1] = '\0';

	char words[100][50];
	int rows = 0;
	splitStrBySymbol(str, " ", &rows, words);

	for (int i = 1; i < rows; i++) {
		if(compareStrings(words[0], words[i]))
			cout << words[i] << endl;
	}



	cout << endl;
	system("pause");
	return 0;
}