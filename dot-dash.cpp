	#include<iostream>
	#include<stdio.h>
	#include<math.h>
	#include<conio.h>
	#include<string.h>

	#include <windows.h>

	//#include<graphics.h>

	using namespace std;

	void gotoxy(int column, int line)
	{
		// Create a COORD structure and fill in its members.
		// This specifies the new position of the cursor that we will set.
		COORD coord;
		coord.X = column;
		coord.Y = line;

		// Obtain a handle to the console screen buffer.
		// (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
		// in conjunction with the GetStdHandle() to retrieve the handle.)
		// Note that because it is a standard handle, we don't need to close it.
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		// Finally, call the SetConsoleCursorPosition function.
		if (!SetConsoleCursorPosition(hConsole, coord))
		{
		// Uh-oh! The function call failed, so you need to handle the error.
		// You can call GetLastError() to get a more specific error code.
		// ...
		}
	}

	void horizontal_line()
	{
		gotoxy(55,2);cout<<"@_______@________@";
		gotoxy(55,7);cout<<"@_______@________@";
		gotoxy(55,12);cout<<"@_______@________@";
	}
	void vertical_line(int index)
	{
		for(int i=3;i<12;i++)
		{
			if(i!=7)
			{
				gotoxy(index,i);cout<<"|"; 
			}
		}
	}
	void numbering()
	{
		gotoxy(58,3);cout<<"a";
		gotoxy(67,3);cout<<"b";
		gotoxy(53,5);cout<<"h";
		gotoxy(53,10);cout<<"g";
		gotoxy(74,5);cout<<"c";
		gotoxy(74,10);cout<<"d";
		gotoxy(58,14);cout<<"f";
		gotoxy(67,14);cout<<"e";
		gotoxy(58,6);cout<<"i";
		gotoxy(68,6);cout<<"l";
		gotoxy(64,5);cout<<"j";
		gotoxy(64,10);cout<<"k";
	}
	void game()
	{
		gotoxy(5,1);cout<<"@";
		gotoxy(5,8);cout<<"@";
		gotoxy(5,15);cout<<"@";
		gotoxy(25,1);cout<<"@";
		gotoxy(25,8);cout<<"@";
		gotoxy(25,15);cout<<"@";
		gotoxy(15,1);cout<<"@";
		gotoxy(15,8);cout<<"@";
		gotoxy(15,15);cout<<"@";
	}
	void plothline()
	{
		int i;
		for(i=1;i<10;i++)cout<<"_";
	}
	void plotvline(int i,int j)
	{
		int p;
		for(p=(j+1);p<(j+7);p++)
		{
			gotoxy(i,p);cout<<"|";
		}
	}
	void line1()
	{
		gotoxy(6,1);plothline();
	}
	void  line2()
	{
		gotoxy(16,1);plothline();
	}
	void line3()
	{
		plotvline(25,1);
	}
	void line4()
	{
		plotvline(25,8);
	}
	void line5()
	{
		gotoxy(16,15); plothline();
	}
	void line6()
	{
		gotoxy(6,15);plothline();
	}
	void line7()
	{
		plotvline(5,8);
	}
	void line8()
	{
		plotvline(5,1);
	}
	void line9()
	{
		gotoxy(6,8);plothline();
	}
	void line10()
	{
		plotvline(15,1);
	}
	void line11()
	{
		plotvline(15,8);
	}
	void line12()
	{
		gotoxy(16,8);plothline();
	}
	void cosmos()
	{
		gotoxy(10,5);cout<<"C C C C   O O O O   S S S S   M     M   O O O O   S S S S";
		gotoxy(10,6);cout<<"C         O     O   S         M M M M   O     O   S      ";
		gotoxy(10,7);cout<<"C         O     O   S S S S   M  M  M   O     O   S S S S";
		gotoxy(10,8);cout<<"C         O     O         S   M     M   O     O         S";
		gotoxy(10,9);cout<<"C C C C   O O O O   S S S S   M     M   O O O O   S S S S";
	}
	void star()
	{
	//for(int i=0;i<78;i++)
	//{
	//gotoxy(i,1);cout<<"*";
	//}
	for(int i=1;i<79;i++)
	{
		gotoxy(i,25);cout<<"*";
	}
	for(int i=0;i<25;i++)
	{
		gotoxy(1,i);cout<<"*";
	}
	for(int i=0;i<25;i++)
	{
		gotoxy(79,i);cout<<"*";
	}
	gotoxy(78,24);cout<<"*";
	}
	// HERE STARTS THE MAIN PROGRAM
	main()
	{
	start:
	system("cls");

	//int driver= DETECT;
	int mode;
	//initgraph(&driver,&mode,"//bgi");
	char g1;
	char whichline;
	int j;
	char player1[10];
	char player2[10];
	char set1[4]={'a','h','j','i'};
	char set2[4]={'b','c','j','l'};
	char set3[4]={'g','f','k','i'};
	char set4[4]={'d','e','k','l'};
	char setc1[4]={'p','p','p','p'};
	char setc2[4]={'q','q','q','q'};
	char setc3[4]={'r','r','r','r'};
	char setc4[4]={'s','s','s','s'};
	int p1=0;
	int p2=0;
	int p=60;

	int turn=1;
	gotoxy(20,20);
	//setcolor(BLUE);
	cout<<"*******GAME MADE BY *******\n";
	cout<<"                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"  \n Jiva Nath Bagale \n" ;

	cosmos();
	gotoxy(1,1);
	cout<<"Player 1:";
	cin>>player1;
	cout<<"Player 2:";
	cin>>player2;
	
	system("cls");

	horizontal_line();
	vertical_line(55);
	vertical_line(63);
	vertical_line(72);
	numbering();
	gotoxy(5,23);cout<<"Player 1:"<<player1;
	gotoxy(5,24);cout<<"Player 2:"<<player2;
	gotoxy(60,23);
	cout<<"N :---NEW GAME ";
	gotoxy(60,24);
	cout<<"X :---EXIT GAME";
	gotoxy(18,22);cout<<"enter the appropriate alphabet to draw line";
	cout<<endl;
	game();
	star();
	for(j=1;j<=12;j++)
	{

	if(turn==1)
	{
	gotoxy(55,21);
	cout<<player1<<" it's your turn";
	}
	else if(turn==2)
	{
	gotoxy(55,21);
	cout<<player2<<" it's your turn";
	}
	gotoxy(p,20);
	cin>>whichline;

	if(whichline=='a')
	{
		setc1[0]='a';
	}
	if(whichline=='b')
	{
		setc2[0]='b';
	}
	if(whichline=='c')
	{
		setc2[1]='c';
	}
	if(whichline=='d')
	{
		setc4[0]='d';
	}
	if(whichline=='e')
	{
		setc4[1]='e';
	}
	if(whichline=='f')
	{
		setc3[1]='f';
	}
	if(whichline=='g')
	{
		setc3[0]='g';
	}
	if(whichline=='h')
	{
		setc1[1]='h';
	}
	if(whichline=='i')
	{
		setc1[3]='i';
		setc3[3]='i';
	}
	if(whichline=='j')
	{
		setc1[2]='j';
		setc2[2]='j';
	}
	if(whichline=='k')
	{
	setc3[2]='k';
	setc4[2]='k';
	}
	if(whichline=='l')
	{
	setc2[3]='l';
	setc4[3]='l';
	}
	switch(whichline)
	{
	case 'a':line1(); break;
	case 'b':line2(); break;
	case 'c':line3(); break;
	case 'd':line4(); break;
	case 'e':line5(); break;
	case 'f':line6(); break;
	case 'g':line7(); break;
	case 'h':line8(); break;
	case 'i':line9(); break;
	case 'j':line10();break;
	case 'k':line11();break;
	case 'l':line12();break;
	default:j-- ;
	}
	if((setc1[1]==set1[1])&&(setc1[2]==set1[2])&&(setc1[3]==set1[3])&&(setc1[0]==set1[0]&&setc2[1]==set2[1])&&(setc2[2]==set2[2])&&(setc2[3]==set2[3])&&(setc2[0]==set2[0]))
	{
	if(turn==1){p1++;p1++;turn=2;gotoxy(17,4);cout<<player1;gotoxy(7,4);cout<<player1;}
	else {p2++;p2++;turn=1;gotoxy(17,4);cout<<player2;gotoxy(7,4);cout<<player2;}
	setc1[0]='p';
	setc1[1]='p';
	setc1[2]='p';
	setc1[3]='p';
	setc2[0]='q';
	setc2[1]='q';
	setc2[2]='q';
	setc2[3]='q';
	}
	else if((setc2[1]==set2[1])&&(setc2[2]==set2[2])&&(setc2[3]==set2[3])&&(setc2[0]==set2[0]&&setc4[1]==set4[1])&&(setc4[2]==set4[2])&&(setc4[3]==set4[3])&&(setc4[0]==set4[0]))

	{
	if(turn==1){p1++;p1++;turn=2;gotoxy(17,12);cout<<player1;gotoxy(17,4);cout<<player1;}
	else {p2++;p2++;turn=1;gotoxy(17,12);cout<<player2;;gotoxy(17,4);cout<<player2;}

	setc2[0]='q';
	setc2[1]='q';
	setc2[2]='q';
	setc2[3]='q';
	setc4[0]='s';
	setc4[1]='s';
	setc4[2]='s';
	setc4[3]='s';
	}
	else if((setc4[1]==set4[1])&&(setc4[2]==set4[2])&&(setc4[3]==set4[3])&&(setc4[0]==set4[0]&&setc3[1]==set3[1])&&(setc3[2]==set3[2])&&(setc3[3]==set3[3])&&(setc3[0]==set3[0]))
	{
	if(turn==1){p1++;turn=2;p1++;gotoxy(17,12);cout<<player1;gotoxy(7,12);cout<<player1;}
	else {p2++;turn=1;p2++;gotoxy(17,12);cout<<player2;gotoxy(7,12);cout<<player2;}
	setc3[0]='r';
	setc3[1]='r';
	setc3[2]='r';
	setc3[3]='r';
	setc4[0]='s';
	setc4[1]='s';
	setc4[2]='s';
	setc4[3]='s';
	}
	else if((setc1[1]==set1[1])&&(setc1[2]==set1[2])&&(setc1[3]==set1[3])&&(setc1[0]==set1[0]&&setc3[1]==set3[1])&&(setc3[2]==set3[2])&&(setc3[3]==set3[3])&&(setc3[0]==set3[0]))

	{
	if(turn==1){p1++;turn=2;p1++;gotoxy(7,12);cout<<player1;gotoxy(7,4);cout<<player1;}
	else {p2++;turn=1;  p2++;gotoxy(7,12);cout<<player2;gotoxy(7,4);cout<<player2;}
	setc1[0]='p';
	setc1[1]='p';
	setc1[2]='p';
	setc1[3]='p';
	setc3[0]='r';
	setc3[1]='r';
	setc3[2]='r';
	setc3[3]='r';
	}
	else if((setc1[1]==set1[1])&&(setc1[2]==set1[2])&&(setc1[3]==set1[3])&&(setc1[0]==set1[0]))

	{
	if(turn==1){p1++;turn=2;gotoxy(7,4);cout<<player1;}
	else {p2++;turn=1;gotoxy(7,4);cout<<player2;}

	setc1[0]='p';
	setc1[1]='p';
	setc1[2]='p';
	setc1[3]='p';
	}
	else  if((setc2[1]==set2[1])&&(setc2[2]==set2[2])&&(setc2[3]==set2[3])&&(setc2[0]==set2[0]))

	{
	if(turn==1){p1++;turn=2;gotoxy(17,4);cout<<player1;}
	else {p2++;turn=1;gotoxy(17,4);cout<<player2;}
	setc2[0]='q';
	setc2[1]='q';
	setc2[2]='q';
	setc2[3]='q';
	}
	else if((setc3[1]==set3[1])&&(setc3[2]==set3[2])&&(setc3[3]==set3[3])&&(setc3[0]==set3[0]))

	{
	if(turn==1){p1++;turn=2;gotoxy(7,12);cout<<player1;}
	else {p2++;turn=1;gotoxy(7,12);cout<<player2;}
	setc3[0]='r';
	setc3[1]='r';
	setc3[2]='r';
	setc3[3]='r';
	}
	else if((setc4[1]==set4[1])&&(setc4[2]==set4[2])&&(setc4[3]==set4[3])&&(setc4[0]==set4[0]))

	{
	if(turn==1){p1++;turn=2;gotoxy(17,12);cout<<player1;}
	else {p2++;turn=1;gotoxy(17,12);cout<<player2;}
	setc4[0]='s';
	setc4[1]='s';
	setc4[2]='s';
	setc4[3]='s';
	}

	p++;
	if(turn!=1)
	{
	turn=1;
	}
	else
	{
	turn=2;
	}

	}
	if(p1>p2)
	{
	gotoxy(24,24);
	cout<<player1<<"  Wins with "<<p1<<" pointS";
	}
	else if(p2>p1)
	{
	gotoxy(24,24);
	cout<<player2<<"  Wins with "<<p2<<" pointS";
	}
	else if(p1==p2)
	{
	gotoxy(20,24);
	cout<<"It's A draW";
	}
	gotoxy(77,24);
	//cout<<p1<<p2;
	//cout<<setc1[0]<<setc2[0]<<setc3[0]<<setc4[0];
	cin>>g1;
	if(g1=='n') goto start;
	else   goto end;


	end:return(0);
}
