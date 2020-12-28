#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include <windows.h>

using namespace std;

void goto_xy(int x, int y)
{
	// Specify the position of the cursor
	COORD coord;
	coord.X = x;
	coord.Y = y;

	// Get the console buffer handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!SetConsoleCursorPosition(hConsole, coord))
	{

	}
}

void DrawSampleHorizontalLine(int y)
{
	goto_xy(55, y); cout << "@_______@________@";
}
void DrawSampleVerticalLine(int index)
{
	for (int i = 3; i < 12; i++)
	{
		if (i != 7)
		{
			goto_xy(index, i); cout << "|";
		}
	}
}
void ShowSampleGameLines()
{
	DrawSampleHorizontalLine(2);
	DrawSampleHorizontalLine(7);
	DrawSampleHorizontalLine(12);

	DrawSampleVerticalLine(55);
	DrawSampleVerticalLine(63);
	DrawSampleVerticalLine(72);
}

void ShowSampleGameNumbering()
{
	goto_xy(58, 3); cout << "a";
	goto_xy(67, 3); cout << "b";
	goto_xy(53, 5); cout << "h";
	goto_xy(53, 10); cout << "g";
	goto_xy(74, 5); cout << "c";
	goto_xy(74, 10); cout << "d";
	goto_xy(58, 14); cout << "f";
	goto_xy(67, 14); cout << "e";
	goto_xy(58, 6); cout << "i";
	goto_xy(68, 6); cout << "l";
	goto_xy(64, 5); cout << "j";
	goto_xy(64, 10); cout << "k";
}

void ShowPlayerName(int playerNo, bool yourTurn, char playerName[])
{
	goto_xy(5, 20 + playerNo); cout << "Player " << playerNo << ":" << playerName;

	if (yourTurn)
		cout << ". Your turn to draw";
	else
		cout << ".                  ";
}

void DrawGameDots()
{
	goto_xy(5, 1); cout << "@";
	goto_xy(5, 8); cout << "@";
	goto_xy(5, 15); cout << "@";
	goto_xy(25, 1); cout << "@";
	goto_xy(25, 8); cout << "@";
	goto_xy(25, 15); cout << "@";
	goto_xy(15, 1); cout << "@";
	goto_xy(15, 8); cout << "@";
	goto_xy(15, 15); cout << "@";
}
void DrawGameHorizontalLine(int x, int y)
{
	goto_xy(x, y);
	for (int i = 1; i < 10; i++) cout << "_";
}
void DrawGameVerticalLine(int x, int yStart)
{
	for (int y = (yStart + 1); y < (yStart + 7); y++)
	{
		goto_xy(x, y); cout << "|";
	}
}

void ShowGameMainPage()
{
	goto_xy(10, 5); cout << "C C C C   O O O O   S S S S   M     M   O O O O   S S S S";
	goto_xy(10, 6); cout << "C         O     O   S         M M M M   O     O   S      ";
	goto_xy(10, 7); cout << "C         O     O   S S S S   M  M  M   O     O   S S S S";
	goto_xy(10, 8); cout << "C         O     O         S   M     M   O     O         S";
	goto_xy(10, 9); cout << "C C C C   O O O O   S S S S   M     M   O O O O   S S S S";

	goto_xy(20, 20); cout << "******* GAME MADE BY *******\n";
	goto_xy(20, 21); cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	goto_xy(20, 23); cout << "Jiva Nath Bagale\n";
}
void DrawOutlineStars()
{
	for (int i = 0; i < 25; i++) 
	{
		goto_xy(1, i); cout << "*";  // stars on the left
		goto_xy(79, i); cout << "*"; // stars on the right
	}
	for (int i = 1; i < 80; i++) 
	{
		goto_xy(i, 0); cout << "*"; // stars on the top
		goto_xy(i, 25); cout << "*"; // stars on the bottom
	}
}

// HERE STARTS THE MAIN PROGRAM
int main()
{
	startGame:
	system("cls");

	char g1;
	char whichline;
	char player1Name[20];
	char player2Name[20];

	char set1[4] = { 'a','h','j','i' };
	char set2[4] = { 'b','c','j','l' };
	char set3[4] = { 'g','f','k','i' };
	char set4[4] = { 'd','e','k','l' };
	char setc1[4] = { 'p','p','p','p' };
	char setc2[4] = { 'q','q','q','q' };
	char setc3[4] = { 'r','r','r','r' };
	char setc4[4] = { 's','s','s','s' };

	int inputCount;
	int player1Points = 0;
	int player2Points = 0;
	int inputCursorXPosition = 60;
	int currentPlayer = 1;

	ShowGameMainPage();

	// input player names	
	goto_xy(1, 1);
	cout << "Player 1:";
	cin >> player1Name;
	cout << " Player 2:";
	cin >> player2Name;
	cout << "Enjoy the game " << player1Name << " & " << player2Name << endl;

	system("cls");

	ShowSampleGameLines();
	ShowSampleGameNumbering();

	ShowPlayerName(1, true, player1Name);
	ShowPlayerName(2, false, player2Name);

	goto_xy(5, 18); cout << "Enter the appropriate alphabet to draw line.";
	goto_xy(60, 21); cout << "N :---NEW GAME ";
	goto_xy(60, 22); cout << "X :---EXIT GAME";
	
	DrawGameDots();
	DrawOutlineStars();

	for (inputCount = 1; inputCount <= 12; inputCount++)
	{
		if (currentPlayer == 1)
		{
			ShowPlayerName(1, true, player1Name);
			ShowPlayerName(2, false, player2Name);
		}
		else
		{
			ShowPlayerName(1, false, player1Name);
			ShowPlayerName(2, true, player2Name);
		}

		goto_xy(inputCursorXPosition, 18);
		cin >> whichline;

		inputCursorXPosition++;

		whichline = tolower(whichline);

		switch (whichline)
		{
			case 'a': 
				setc1[0] = 'a';
				DrawGameHorizontalLine(6, 1); break;
			case 'b':
				setc2[0] = 'b';
				DrawGameHorizontalLine(16, 1); break;
			case 'c':
				setc2[1] = 'c';
				DrawGameVerticalLine(25, 1); break;
			case 'd':
				setc4[0] = 'd';
				DrawGameVerticalLine(25, 8); break;
			case 'e':
				setc4[1] = 'e';
				DrawGameHorizontalLine(16, 15); break;
			case 'f':
				setc3[1] = 'f';
				DrawGameHorizontalLine(6, 15); break;
			case 'g':
				setc3[0] = 'g';
				DrawGameVerticalLine(5, 8); break;
			case 'h':
				setc1[1] = 'h';
				DrawGameVerticalLine(5, 1); break;
			case 'i':
				setc1[3] = setc3[3] = 'i';		
				DrawGameHorizontalLine(6, 8); break;
			case 'j':
				setc1[2] = setc2[2] = 'j';
				DrawGameVerticalLine(15, 1); break;
			case 'k':
				setc3[2] = setc4[2] ='k';
				DrawGameVerticalLine(15, 8); break;
			case 'l':
				setc2[3] = setc4[3] = 'l';		
				DrawGameHorizontalLine(16, 8); break;	
			case 'n': goto startGame;
			case 'x': goto end;
			default : inputCount--; continue; // wrong user input so don't increase the input count
		}

		if ((setc1[1] == set1[1]) && (setc1[2] == set1[2]) && (setc1[3] == set1[3]) && (setc1[0] == set1[0] && setc2[1] == set2[1]) && (setc2[2] == set2[2]) && (setc2[3] == set2[3]) && (setc2[0] == set2[0]))
		{
			if (currentPlayer == 1) { player1Points++; player1Points++; currentPlayer = 2; goto_xy(17, 4); cout << player1Name; goto_xy(7, 4); cout << player1Name; }
			else { player2Points++; player2Points++; currentPlayer = 1; goto_xy(17, 4); cout << player2Name; goto_xy(7, 4); cout << player2Name; }
			setc1[0] = 'p';
			setc1[1] = 'p';
			setc1[2] = 'p';
			setc1[3] = 'p';
			setc2[0] = 'q';
			setc2[1] = 'q';
			setc2[2] = 'q';
			setc2[3] = 'q';
		}
		else if ((setc2[1] == set2[1]) && (setc2[2] == set2[2]) && (setc2[3] == set2[3]) && (setc2[0] == set2[0] && setc4[1] == set4[1]) && (setc4[2] == set4[2]) && (setc4[3] == set4[3]) && (setc4[0] == set4[0]))
		{
			if (currentPlayer == 1) { player1Points++; player1Points++; currentPlayer = 2; goto_xy(17, 12); cout << player1Name; goto_xy(17, 4); cout << player1Name; }
			else { player2Points++; player2Points++; currentPlayer = 1; goto_xy(17, 12); cout << player2Name;; goto_xy(17, 4); cout << player2Name; }

			setc2[0] = 'q';
			setc2[1] = 'q';
			setc2[2] = 'q';
			setc2[3] = 'q';
			setc4[0] = 's';
			setc4[1] = 's';
			setc4[2] = 's';
			setc4[3] = 's';
		}
		else if ((setc4[1] == set4[1]) && (setc4[2] == set4[2]) && (setc4[3] == set4[3]) && (setc4[0] == set4[0] && setc3[1] == set3[1]) && (setc3[2] == set3[2]) && (setc3[3] == set3[3]) && (setc3[0] == set3[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; player1Points++; goto_xy(17, 12); cout << player1Name; goto_xy(7, 12); cout << player1Name; }
			else { player2Points++; currentPlayer = 1; player2Points++; goto_xy(17, 12); cout << player2Name; goto_xy(7, 12); cout << player2Name; }
			setc3[0] = 'r';
			setc3[1] = 'r';
			setc3[2] = 'r';
			setc3[3] = 'r';
			setc4[0] = 's';
			setc4[1] = 's';
			setc4[2] = 's';
			setc4[3] = 's';
		}
		else if ((setc1[1] == set1[1]) && (setc1[2] == set1[2]) && (setc1[3] == set1[3]) && (setc1[0] == set1[0] && setc3[1] == set3[1]) && (setc3[2] == set3[2]) && (setc3[3] == set3[3]) && (setc3[0] == set3[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; player1Points++; goto_xy(7, 12); cout << player1Name; goto_xy(7, 4); cout << player1Name; }
			else { player2Points++; currentPlayer = 1;  player2Points++; goto_xy(7, 12); cout << player2Name; goto_xy(7, 4); cout << player2Name; }
			setc1[0] = 'p';
			setc1[1] = 'p';
			setc1[2] = 'p';
			setc1[3] = 'p';
			setc3[0] = 'r';
			setc3[1] = 'r';
			setc3[2] = 'r';
			setc3[3] = 'r';
		}
		else if ((setc1[1] == set1[1]) && (setc1[2] == set1[2]) && (setc1[3] == set1[3]) && (setc1[0] == set1[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; goto_xy(7, 4); cout << player1Name; }
			else { player2Points++; currentPlayer = 1; goto_xy(7, 4); cout << player2Name; }

			setc1[0] = 'p';
			setc1[1] = 'p';
			setc1[2] = 'p';
			setc1[3] = 'p';
		}
		else  if ((setc2[1] == set2[1]) && (setc2[2] == set2[2]) && (setc2[3] == set2[3]) && (setc2[0] == set2[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; goto_xy(17, 4); cout << player1Name; }
			else { player2Points++; currentPlayer = 1; goto_xy(17, 4); cout << player2Name; }
			setc2[0] = 'q';
			setc2[1] = 'q';
			setc2[2] = 'q';
			setc2[3] = 'q';
		}
		else if ((setc3[1] == set3[1]) && (setc3[2] == set3[2]) && (setc3[3] == set3[3]) && (setc3[0] == set3[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; goto_xy(7, 12); cout << player1Name; }
			else { player2Points++; currentPlayer = 1; goto_xy(7, 12); cout << player2Name; }
			setc3[0] = 'r';
			setc3[1] = 'r';
			setc3[2] = 'r';
			setc3[3] = 'r';
		}
		else if ((setc4[1] == set4[1]) && (setc4[2] == set4[2]) && (setc4[3] == set4[3]) && (setc4[0] == set4[0]))
		{
			if (currentPlayer == 1) { player1Points++; currentPlayer = 2; goto_xy(17, 12); cout << player1Name; }
			else { player2Points++; currentPlayer = 1; goto_xy(17, 12); cout << player2Name; }
			setc4[0] = 's';
			setc4[1] = 's';
			setc4[2] = 's';
			setc4[3] = 's';
		}

		// Change the turn of the players
		currentPlayer = currentPlayer % 2;
		currentPlayer++;
	}

	goto_xy(5, 23);
	if (player1Points > player2Points)
	{
		cout << "Congratulations " << player1Name << ". You win with " << player1Points << " points.";
	}
	else if (player2Points > player1Points)
	{
		cout << "Congratulations " << player2Name << "  You win with " << player2Points << " points.";
	}
	else if (player1Points == player2Points)
	{
		cout << "Wow, It's a tie";
	}

	goto_xy(5, 24); cout << "Enter n to Start another game or x to Quit the game.";
	goto_xy(60, 24);

	cin >> g1;

	if (g1 == 'n')
		goto startGame;
	else
		goto end;

	end: return(0);
}
