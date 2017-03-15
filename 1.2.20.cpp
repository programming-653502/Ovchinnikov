//---------------------------------------------------------------------------

#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------

#pragma argsused
char S[44];
int N[44];

int integer(int z,int c);
int integer1(int v,int c);
int _tmain(int argc, _TCHAR* argv[])
{
system("chcp 1251");
system("cls");
  int n=0,i,L=0,M1=0,M2=0, b,v,z,q=0;
 // ввод строки
 char S[44];
  gets(S);
  b=strlen(S) - 1 ;
 char *N= new char [b];
 //счетчики целой и дробной частей
  for (i = 0; i < b+1 ; i++) {

	 if (S[i]=='.' || S[i]==',' ) {
		 n=L;
		for (int M = 0 , i = 0; M < n; M++ , i++)
		{
			 N[M]=S[i];
		}
		L=-1;
		q++;
	 }
 /* cout<<S[i];*/
   L++;
  }
  if (q>1) {
  printf("колличество знаков .(,) превышает допустимый лимит, колличество знаков %d",q);
  getch();
  return -1;
  }
  //сумма чифр дробной части
  for (int c = n+1; c <=L+n; c++)
   {
   N[c]=S[c];
   z=N[c];
   /*C1[c]=integer(S,c);*/
   M2+=/*C1[c]*/integer(z,c);
   }
   //сумма цифр целой части
  for (int c = 0; c < n ; c++) {
	v=N[c];
   /*N1[c]=integer1(N,c); */
	M1+=/*N1[c]*/integer1(v,c);
  }
  //вывод обоих результатов и большего
  cout<<M1<<"  "<<M2<<"\n";
  if (M1>M2)
	{
	printf("наибольшая сумма целой части:%d",M1);
	}
  else
	printf("сумма дробной части наибольшая:%d",M2);
  getch();
	return 0;
}
int integer(int z,int c){
int k;
switch (z) {
case '1':
k=1;
break;
case '0':
k=0;
break;
case '2':
k=2;
break;
case '3':
k=3;
break;
case '4':
k=4;
break;
case '5':
k=5;
break;
case '6':
k=6;
break;
case '7':
k=7;
break;
case '8':
k=8;
break;
case '9':
k=9;
break;
default:
	;

}
return k;
}
int integer1(int v,int c){
int r;
switch (v) {
case '1':
r=1;
break;
case '0':
r=0;
break;
case '2':
r=2;
break;
case '3':
r=3;
break;
case '4':
r=4;
break;
case '5':
r=5;
break;
case '6':
r=6;
break;
case '7':
r=7;
break;
case '8':
r=8;
break;
case '9':
r=9;
break;
default:
	;

}
return r;
}
//---------------------------------------------------------------------------
