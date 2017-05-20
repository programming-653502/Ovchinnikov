//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <dos.h>
#include <time.h>
#include <tchar.h>
#include <conio.h>
#include <iostream.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused
void menu(int GlobalTimer)
{
   if (GlobalTimer > 1000) {
   cout<<"Преветсвую, напишите сколько секунд магазин должен еще работать\n";
   }
   if (GlobalTimer <= 1000) {
   cout<<"Прекрасный выбор, нажмите любую клавишу, что бы начать историю";
   }

}
void Story(int MaxCount, int GlobalTimer)
{
	if(MaxCount == 0)
	{
		cout<<"Прекрасный летний день. В вашей голове промелькнула мысль, скорее даже идея, что вам нужен сладкий рулет.\n";
		cout<<"И вот вы уже стоите в очереди битый час, впереди вас стоит шайка из странного зверя и 3 людей вашего возраста.\n";
		cout<<"Их корзины полны продуктов будто под этими одеждами прячутся дворянины, а у вас только один сладкий рулет.\n";
		cout<<"Магазин закрывается на обед через "<<GlobalTimer<<" секунд,а очередь только начала свое движение, что вы будете делать?";
	}else if(MaxCount < 4)
	{
		cout<<"\nмагазин закрывается на обед, а вам пришлось расстаться с вашей сладостью,\nшайка с огромными сумками всякой еды медленно идет по домам, а вы ненавидите их всей душой";
	}
	else if (MaxCount > 4)
	{
    	cout<<"\nмагазин закрывается на обед, а вы держа в руках желаемое лакомство быстрым шагом идете домой.\nНо в подъезде вам опять попадется шайка из странного зверя и 3 людей вашего возраста.\nОни предлагают отдать сладкий рулет, иначе они побъют вас и заберут лакомство сами.\nЧто вы будете делать?";

	}
}

struct Person
{
 int PersonTimer, PersonalTimer;
 bool Served;
};
struct List
{
  Person person;
  List* next;
};


/*void Init(List **begin)
{
	(*begin) = new List;
	List *end = *begin;
	(*begin)->person.PersonTimer = random(5);
	(*begin)->person.PersonalTimer = random(20);
	while ((*begin)->person.PersonalTimer <= 10)
		(*begin)->person.PersonalTimer = random(20);
	for (int i = 0; i < 10; i++) {
		end->next = new List;
		end = end->next;
		end->person.PersonTimer = random(5);
		end->person.PersonalTimer = random(20);
		//Queue[i].PersonalTimer = random(20);
		while(end->person.PersonalTimer <= 10)
			//Queue[i].PersonalTimer = random(20);
			end->person.PersonalTimer = random(20);

	}


	end->next = NULL;
} */

int _tmain(int argc, _TCHAR* argv[])
{
List* begin = NULL;
begin = new List;
List *end = begin;
	begin->person.PersonTimer = random(5);
	begin->person.PersonalTimer = random(20);
	while (begin->person.PersonalTimer <= 10)
		begin->person.PersonalTimer = random(20);
	for (int i = 0; i < 10; i++) {
		end->next = new List;
		end = end->next;
		end->person.PersonTimer = random(5);
		end->person.PersonalTimer = random(20);
		//Queue[i].PersonalTimer = random(20);
		while(end->person.PersonalTimer <= 10)
			//Queue[i].PersonalTimer = random(20);
			end->person.PersonalTimer = random(20);
	end->next = NULL;
	}








SetConsoleCP(1251);
SetConsoleOutputCP(1251);
//Person *Queue;
Randomize();
int n, MaxTime = 0, MaxCount = 0;
n = 4;
//Queue = new Person[n];

int GlobalTimer;
menu(GlobalTimer);

cin>>GlobalTimer;
menu(GlobalTimer);

getch();
clrscr();
time_t GlobalTimerStart;
Story(MaxCount, GlobalTimer);
getch();

//Init(&begin);
/*for (int i = 0; i < 4; i++) {
	Queue[i].PersonTimer = random(2);
	Queue[i].PersonalTimer = random(20);
	while(Queue[i].PersonalTimer <= 10)
		Queue[i].PersonalTimer = random(20);
	} */
GlobalTimerStart = time(NULL);
time_t GlobalTimerEnd;
int T =5;
//
while ((difftime(GlobalTimerEnd,GlobalTimerStart) <= GlobalTimer))
{

	for( int i = 0; i<10; i++)
	{
		cout<<"\nпосетитель подходит к кассе";
		//sleep(Queue[i].PersonTimer);
		sleep(end->person.PersonTimer);
		//sleep(end->person.PersonTimer);
		cout<<"\nпосетитель обслуживается";
		sleep(end->person.PersonalTimer);
		//sleep(Queue[i].PersonalTimer);
		//Queue[i].Served = true;
		end->person.Served = true;
		cout<<"\nпоситетель уходит";
		GlobalTimerEnd = time(NULL);
		if((GlobalTimer - difftime(GlobalTimerEnd,GlobalTimerStart))>=0)
		cout<<"\nосталось:"<<(GlobalTimer - difftime(GlobalTimerEnd,GlobalTimerStart))<<"секунд";
		MaxCount++;
		if(difftime(GlobalTimerEnd,GlobalTimerStart) >= GlobalTimer){break;}
	}

	if ((difftime(GlobalTimerEnd,GlobalTimerStart) >= GlobalTimer)) {
	 break;
	}
	//sleep(T);

}
for (int i = 0; i < 4; i++) {
  /*	if (Queue[i].Served == true){
		MaxCount++;
	}*/
	if(MaxTime < end->person.PersonalTimer)
	{
		MaxTime = end->person.PersonalTimer;
	}
}
cout<<"\nмаксимальное колличество обслуженых посетеителей "<<MaxCount;
cout<<"\nмаксимальное время обслуживания "<<MaxTime<<" сек.";
Story(MaxCount, GlobalTimer);
	 getch();
	return 0;
}
//---------------------------------------------------------------------------
