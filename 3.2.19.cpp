//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <tchar.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused
bool End(int X);
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP (1251);
	int n,m,X,a,c,v=1;
	cout<<"введите колличество игроков(не больше 4):";
	cin>>a;
	if (a<0 || a>4) {
	cout<<"errorr";
	getch();
	return -1;
	}
	bool E = false;
	//*************объ€вление м’n массива
	cout<<"введите M размер тортега:";
	cin>>m;
	cout<<"введите размер N тортега:";
	cin>>n;
	clrscr();
	float **torteg = new float* [m]; // две строки в массиве
	for (int count = 0; count < m; count++)
		torteg[count] = new float [n]; // и п€ть столбцов
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			torteg[i][j] = 1;
		}
	}
	torteg[m-1][0] = 0;
	//******************** вывод
	for (int i = 0; i < m; i++) {
		cout<<"\n";
		for (int j = 0; j < n; j++) {
		 cout<<torteg[i][j];
		}
	}
	cout<<"\n";
	//*******************сама игра
	c=1;
	for (int j = 0; j < v; j++) {
		int f,g;
		cout<<"ход "<<j+1<<":\n";

		cout<<"игрок "<<c<<":\n";

		cout<<"выбирайте точку:\n";
		cout<<"строка:";
		cin>>f;
		cout<<"\nстолбец:";
		cin>>g;
		if (f>m || g>n||f<=0 || g<=0 )
		{
		  cout<<"errorr";
		  getch();
		  return -1;
		}
		if (f==m && g==1)
		{
			X=0;
		}
		for (int i =0; i < f; i++) {
		  for(int h=g-1; h<n; h++)
		  {
			torteg[i][h]=2;
		  }
		}

		for (int i = 0; i < m; i++) {
		cout<<"\n";
			for (int j = 0; j < n; j++) {
				if (torteg[i][j] !=2 )
				{
				cout<<torteg[i][j];
				}
			 }
		}
		cout<<"\n";
		E=End(X);
		if (E==true && v ==40)
		{
			cout<<"ходы закончились";
			getch();
			return 0;
		}
		if (E==true)
		{
			cout<<"игрок "<<c<<" проиграл";
			getch();
			return 0;
		}
		c++;
		if (c>a)
		{
			c=1;
		}
		v++;

		if (v==40)
		{
			E=End(X);
		}
	}

	cout<<"\n";


	getch();
	return 0;
}
bool End(int X)
{
	if (X == 0) {
	return true;
	}
	else return false;
}
//---------------------------------------------------------------------------
