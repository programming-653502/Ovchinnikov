// LenyaLab4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <cstring>

struct WordChars {
	int FirstPos;
	int EndPos;
	char FirstChar;
	char EndChar;
	char word[9];
	bool IsChainTrue = false;

};

char ChainString[1000];
int Words;

using namespace std;

void WordsInput(int Words, WordChars* structArr)
{
	char string[9];

	for (int j = 0; j < Words; j++)
	{
		cout << "введите строку " << j << ":\n";//ввод строки 
		cin >> string;
		for (int i = 0; i < 8; i++)
		{

			structArr[j].word[i] = string[i];
			structArr[j].FirstChar = string[0];
			if (structArr[j].word[i] != '\0')
			{
				structArr[j].EndPos = i;
				structArr[j].EndChar = string[structArr[j].EndPos];
			}
			else 
				break;
		}
	}
}
int FirstLastWordsFinder(int &beginning, int &ending, WordChars* Array)
{
	
	int firstWordInChain = beginning;
	int lastWordInChain = ending;
	for (; firstWordInChain < Words; firstWordInChain++)
	{
		for (lastWordInChain = ending; lastWordInChain > firstWordInChain; lastWordInChain--)
		{
			if ((Array[firstWordInChain].FirstChar == Array[lastWordInChain].EndChar))//&& StructMass[i].IsChainTrue && StructMass[j].IsChainTrue)
			{
				break;
			}
		}
		if (firstWordInChain != lastWordInChain)
			break;
	}
	if (firstWordInChain == lastWordInChain)
	{
		return -1;
	}
	beginning = firstWordInChain;
	ending = lastWordInChain;
	return 0;
}

int main()
{



	setlocale(LC_ALL, "rus");
	
	cout << "введите колличество слов: ";//размер массива структуры, больше этого значенния обрабатываться не будет 
	cin >> Words;

	WordChars *StructMass;
	StructMass = new WordChars[Words];

	WordsInput(Words, StructMass);

	int firstWordInChain = 0;
	int lastWordInChain = Words - 1;
	

	while (!FirstLastWordsFinder(firstWordInChain, lastWordInChain, StructMass))
	{
		int i = firstWordInChain;
		int j = i;
		for ( ; i <= lastWordInChain; i++)
		{
			for (j = i + 1; j <= lastWordInChain; j++)
			{
				if (StructMass[i].EndChar == StructMass[j].FirstChar)// j != (Words - 1)
				{
					StructMass[j].IsChainTrue = true;
					StructMass[i].IsChainTrue = true;
					i = j;
				}
				else
				{
					StructMass[i].IsChainTrue = false;
				}
				/*else if (j == (Words - 1))
				{
					int i = j;
					int h = 0;
					if (StructMass[i].EndChar == StructMass[h].FirstChar)
					{
						StructMass[i].IsChainTrue = true;
						StructMass[h].IsChainTrue = true;
					}
				}*/
			}
		}
		if (StructMass[firstWordInChain].IsChainTrue && StructMass[lastWordInChain].IsChainTrue)
		{
			break;
		}
		else
		{
			i = 0;
			while (i < lastWordInChain)
			{
				if (StructMass[i].IsChainTrue)
				{
					break;
				}
				i++;
			}
			firstWordInChain = i;
			lastWordInChain = j;
		}
	}

	

	for (int i = 0; i < Words; i++)
	{
		if (StructMass[i].IsChainTrue)
		{
			strcat_s(ChainString, StructMass[i].word);
			strcat_s(ChainString, " ");
		}
	}

	cout << "Цепочка слов:" << ChainString;
	system("pause");
	return 0;
}