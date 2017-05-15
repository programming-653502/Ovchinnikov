

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void filter(const char* str, char** destlist);
void sort(char** strlist, int strcnt);

int main()
{

	FILE * File;
	setlocale(LC_ALL, "rus");
	fopen_s(&File, "C:\\Users\\MSI\\Desktop\\projects\\Lab4-2C++\\Lab4-2C++.txt", "r+");
	/*if (File == NULL)
	{
		cout << "файл не найден";
		return -1;
	}*/

	char   str[100];
	char** strlist;
	int    delimcnt = 0;

	fgets(str, 100, File);

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ',' || str[i] == '.' || str[i] == ' ')
			delimcnt++;

	if (delimcnt == 0) {
		cout << "Файл не возможно прочитать\n";
		return 1;
	}

	strlist = new char*[delimcnt];
	for (int i = 0; i < delimcnt; i++)
		strlist[i] = new char[20];

	filter(str, strlist);
	sort(strlist, delimcnt);

	for (int i = 0; i < delimcnt; i++)
	{
		cout << strlist[i] << endl;

	}
	fclose(File);
	system("pause");
	return 0;
}

void filter(const char* str, char** destlist)
{
	for (int i = 0, j = 0, k = 0; str[i] != '\0'; i++) {
		if (str[i] == ',' || str[i] == '.') {
			// Если j не равно нулю, то прибавить единицу, дабы не скопировать запятую
			strncpy(destlist[k], str + j + (j != 0), i - j - (j != 0));
			destlist[k][i - j] = '\0';
			k++;
			j = i;
		}
	}
}

void sort(char** strlist, int strcnt)
{
	for (int i = 0; i < strcnt - 1; i++)
		for (int j = i + 1; j < strcnt; j++)
			if (strcmp(strlist[i], strlist[j]) > 0) {
				char* tmp = strlist[i];
				strlist[i] = strlist[j];
				strlist[j] = tmp;
			}
}

