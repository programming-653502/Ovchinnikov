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
	cout<<"������� ����������� �������(�� ������ 4):";
	cin>>a;
	if (a<0 || a>4) {
	cout<<"errorr";
	getch();
	return -1;
	}
	bool E = false;
	//*************���������� ��n �������
	cout<<"������� M ������ �������:";
	cin>>m;
	cout<<"������� ������ N �������:";
	cin>>n;
	clrscr();
	float **torteg = new float* [m]; // ��� ������ � �������
	for (int count = 0; count < m; count++)
		torteg[count] = new float [n]; // � ���� ��������
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			torteg[i][j] = 1;
		}
	}
	torteg[m-1][0] = 0;
	//******************** �����
	for (int i = 0; i < m; i++) {
		cout<<"\n";
		for (int j = 0; j < n; j++) {
		 cout<<torteg[i][j];
		}
	}
	cout<<"\n";
	//*******************���� ����
	c=1;
	for (int j = 0; j < v; j++) {
		int f,g;
		cout<<"��� "<<j+1<<":\n";

		cout<<"����� "<<c<<":\n";

		cout<<"��������� �����:\n";
		cout<<"������:";
		cin>>f;
		cout<<"\n�������:";
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
			cout<<"���� �����������";
			getch();
			return 0;
		}
		if (E==true)
		{
			cout<<"����� "<<c<<" ��������";
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
