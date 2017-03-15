//---------------------------------------------------------------------------

#pragma hdrstop
#include <windows.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <tchar.h>
//---------------------------------------------------------------------------

#pragma argsused
long double func1(double x,int n);
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
double E;
int n=2;
long double Le=0;
long double Ri=0;
cout<<"введите макс погрешность:";
cin>>E;
clrscr();
cout<<"введите x:";
double x;
cin>>x;
x/=57.7;
clrscr();
cout<<"погрешность E:"<<E<<"\nx:"<<x<<"\n";

Le= sin(x);
Ri_restart:
double D;
D=powl((-1),(n-1));
long double V;
V=func1(x,n);
Ri=(D*powl(x, (2*n-1)));
Ri+=Ri/V;
if ((Le-Ri)>E) {
n++;
goto Ri_restart;
}
if ((Le-Ri)<=E) {
cout<<"Left="<<Le<<"\nRight="<<Ri<<"\nпри n равном:"<<n;
}
getch();
	return 0;
}
long double func1(double x, int n)
{
long double S;
for (int i=0; i < n; i++) {
S=1;
S*=(2*i-1);
}
return S;
}
//---------------------------------------------------------------------------
