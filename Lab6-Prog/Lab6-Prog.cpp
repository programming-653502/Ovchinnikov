// Lab6-Prog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "BST.h"
//#include "BST.cpp"
using namespace std;


int main()
{
	int TreeKeys[9] = { 50, 76, 21, 4, 2, 32, 64, 80, 15};
	BST MyTree;
	int input = 0; 
	
	for (int i = 0; i < 9; i++) 
	{
		MyTree.AddLeaf(TreeKeys[i]);
	}
	MyTree.PrintInOrder();
	
	printf_s("\n");
	cout<<"smallest key is: "<<MyTree.Smallest()<<endl;
	cout << "What node do you want to delete?\n";
	while (input != -1) 
	{
		cin >> input;
		if (input != -1) 
		{
			cout << endl;
			MyTree.RemoveNode(input);
			MyTree.PrintInOrder();
			cout << endl;
		}
	}
	system("pause");
    return 0;
}

