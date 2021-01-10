#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include <windows.h>

using namespace std;

void goto_xy(int x, int y) // x is column position left to right left is 0, y is row position top to bottom top is 0
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

void ShowPlayerName(int playerNo, bool yourTurn, const char playerName[])
{
	goto_xy(5, 21 + playerNo); cout << "Player " << playerNo << ":" << playerName;

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

	char nextGame;
	char whichline;
	char player1Name[20];
	char player2Name[20];	

	ShowGameMainPage();

	// input player names	
	goto_xy(1, 1); cout << "Player 1: ";
	goto_xy(1, 2); cout << "Player 2: ";

	goto_xy(11, 1); cin.getline(player1Name, 20);
	goto_xy(11, 2); cin.getline(player2Name, 20);

	replayGame:
	system("cls");

	int inputCount;
	int currentPlayer = 0;
	int inputCursorXPosition = 60;
	int box1 = 0, box2 = 0, box3 = 0, box4 = 0;

	const char* playerNames[2] = {player1Name, player2Name};
	int playerPoints[2] = {0, 0};
	string pastInputs = "";

	ShowSampleGameLines();
	ShowSampleGameNumbering();

	ShowPlayerName(0, true, playerNames[0]);
	ShowPlayerName(1, false, playerNames[1]);

	goto_xy(5, 18); cout << "Enter the appropriate alphabet to draw line.";
	goto_xy(60, 20); cout << "R :--- REPLAY GAME ";
	goto_xy(60, 21); cout << "N :--- NEW GAME ";
	goto_xy(60, 22); cout << "X :--- EXIT GAME";
	
	DrawGameDots();
	DrawOutlineStars();

	for (inputCount = 1; inputCount < 13; inputCount++)
	{
		int otherPlayer = (currentPlayer == 0) ? 1 : 0;

		ShowPlayerName(currentPlayer, true, playerNames[currentPlayer]);
		ShowPlayerName(otherPlayer, false, playerNames[otherPlayer]);	

		goto_xy(inputCursorXPosition, 18);
		whichline = getchar();
		while ((getchar()) != '\n'); // remove \n from the previous input

		inputCursorXPosition++;

		whichline = tolower(whichline);

		std::size_t found = pastInputs.find(whichline);
  		if (found < pastInputs.length())
		{
			inputCount--; continue; // repeated user input so don't increase the input count
		}

		switch (whichline)
		{
			case 'a': 
				box1++;
				DrawGameHorizontalLine(6, 1); break;
			case 'b':
				box2++;
				DrawGameHorizontalLine(16, 1); break;
			case 'c':
				box2++;
				DrawGameVerticalLine(25, 1); break;
			case 'd':
				box4++;
				DrawGameVerticalLine(25, 8); break;
			case 'e':
				box4++;
				DrawGameHorizontalLine(16, 15); break;
			case 'f':
				box3++;
				DrawGameHorizontalLine(6, 15); break;
			case 'g':
				box3++;
				DrawGameVerticalLine(5, 8); break;
			case 'h':
				box1++;
				DrawGameVerticalLine(5, 1); break;
			case 'i':
				box1++; box3++;	
				DrawGameHorizontalLine(6, 8); break;
			case 'j':
				box1++; box2++;
				DrawGameVerticalLine(15, 1); break;
			case 'k':
				box3++; box4++;
				DrawGameVerticalLine(15, 8); break;
			case 'l':
				box2++; box4++;	
				DrawGameHorizontalLine(16, 8); break;
			case 'r': goto replayGame;	
			case 'n': goto startGame;
			case 'x': goto end;
			default : inputCount--; continue; // wrong user input so don't increase the input count
		}

		pastInputs += whichline;
	
		int boxesCreated = 0; 
		if (box1 == 4) 
		{
			box1++;
			boxesCreated++;
			goto_xy(7, 4); cout << playerNames[currentPlayer];
		}

		if (box2 == 4) 
		{
			box2++;
			boxesCreated++;
			goto_xy(17, 4); cout << playerNames[currentPlayer];
		}

		if (box3 == 4) 
		{
			box3++;
			boxesCreated++;
			goto_xy(7, 12); cout << playerNames[currentPlayer];
		}

		if (box4 == 4) 
		{
			box4++;
			boxesCreated++;
			goto_xy(17, 12); cout << playerNames[currentPlayer];
		}

		// Change the turn of the players
		// Players keep the turn if they complete one or more boxes
		if (boxesCreated == 0)
		{
			currentPlayer = otherPlayer;
		}		
		else
		{
			playerPoints[currentPlayer] += boxesCreated;
		}
	}

	goto_xy(5, 23);
	if (playerPoints[0] > playerPoints[1])
	{
		cout << "Congratulations " << player1Name << ". You win with " << playerPoints[0] << " points.";
	}
	else if (playerPoints[1] > playerPoints[0])
	{
		cout << "Congratulations " << player2Name << ". You win with " << playerPoints[1] << " points.";
	}
	else if (playerPoints[0] == playerPoints[1])
	{
		cout << "Wow, It's a tie";
	}

	goto_xy(5, 24); cout << "Enter r to Replay, n to start New game or x to Quit.";
	goto_xy(60, 24); nextGame = getchar();

	while ((getchar()) != '\n'); // remove \n from the previous input

	if (nextGame == 'r')
	{
		goto replayGame;
	}
	else if (nextGame == 'n')
	{
		goto startGame;
	}
	else
		goto end;

	end: return(0);
}
