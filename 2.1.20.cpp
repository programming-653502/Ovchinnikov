//---------------------------------------------------------------------------

#pragma hdrstop
#include <math.h>
#include <conio.h>
#include <iostream.h>
#include <tchar.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused

double func1(double v);
double func1(double R,int a);
double func2(double R);
double func3(double R);
double func4(double R);
int _tmain(int argc, _TCHAR* argv[])
{
restart:
double R;
double v1;
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout<<"\nвведите радиус окружности:";
cin>>R;
if (R<=0) {
		 goto restart;
}
//очистка сосноли
vrestart:
clrscr();
cout<<"радиус равен:"<<R;
int v;
cout<<"\nвыберите нужную операцию:\n1)площадь круга\n2)площадь сектора круга, угол а\n3)длинна окружности\n4)сторона крадрата,около которого описана окружность\n5)объем конуса, высота конуса радиус окружности, основания, сама окружность\n6)информация об авторе о версии программы\n0)выход\n";
cin>>v;
cout<<"\n\n";
switch (v) {

case 1:
v1=func1(R);
cout<<"S="<<v1;
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr\n";
goto vrestart;
}


case 2:
int a;
cout<<"введите значение угла а:";
cin>>a;
v1=func1(R,a);
cout<<"площадь сектора Sc="<<v1;
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr";
goto vrestart;
}


case 3:
v1=func2(R);
cout<<"длинна окружности L="<<v1;
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr";
goto vrestart;
}
break;


case 4:
v1=func3(R);
cout<<"сторона квадрата а="<<v1;
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr";
goto vrestart;
}
break;


case 5:
v1=func4(R);
cout<<"объем конуса V="<<v1;
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr";
goto vrestart;
}
break;


case 6:
cout<<"автор Овчинников Леонид\n студент группы 653502\n версия:1.0.0 релиз\n";
cout<<"\n1)назад\n2)выход\n";
cin>>v;
switch (v) {
case 1:
goto vrestart;
case 2:
goto end;
default:
cout<<"errorr";
goto vrestart;
}
break;


case 0:
goto end;
default:
cout<<"errorr";
goto vrestart;
}
end:
 cout<<"нажмите любую кнопку для завершение прогаммы";
 getch();
	return 0;
}
double func1(double R){
double S;
S= M_PI*powl(R,2);
return S;
}
double func1(double R,int a){
double Sc;
Sc=M_PI*powl(R,2)*a/360;
return Sc;
//Sc=
}

double func2(double R)
{
double L;
L=2*M_PI*R;
return L;
}
double func3(double R)
{
 double a;
 a=2*R /sqrt(2);
 return a;
}
double func4(double R)
{
  double V;
  V=M_PI*powl(R,2)*R/3;
  return V;
}
//---------------------------------------------------------------------------
