#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream.h>
#define MASS_SIZE 5


struct Test
{
	int CorrectAnswer;
	char Question[100];
};

//#pragma argsused



int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int CurrectNumbers=0;

	Test* Inf;
	FILE* inf;
	Inf = new Test[MASS_SIZE];

	int Answer;
	inf = fopen("Test.txt", "r");
	if (inf == NULL) {
		printf("File not found\n");
		_getch();
		return -1;
	}
	for (int i = 0; i < MASS_SIZE && !feof(inf); i++) {
		fscanf(inf, "%s %d", Inf[i].Question, &Inf[i].CorrectAnswer);
	}
	fclose(inf);

	for (int i = 0; i < MASS_SIZE; i += 1)
	{
		printf("%s", Inf[i].Question);
		cin>>Answer;
		if(Answer == Inf[i].CorrectAnswer)
		{
			CurrectNumbers++;
		}

	}
	printf("вы решили %d из 5",CurrectNumbers);
	_getch();
	//system("pause");
	return 0;
}
