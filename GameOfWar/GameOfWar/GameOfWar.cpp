/*
	A Game of War
	-> 3 Different Classes
		-Damage
		-Health
		-Luck
	-> 2 Players
	-> Goal: Be the first to deplete the other players health
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Functions
void mainMenu();
void dmgClass();
void hpClass();
void luckClass();
void getClass();
void firstMove();
void dmgP1();
void dmgP2();
void battleSim();
void winCondition();

//Public Variables
string nameA, nameB, classA, classB;
int dmg1, hp1, luck1, dmg2, hp2, luck2, dmg3, hp3, luck3;
int dmgA, hpA, luckA, dmgB, hpB, luckB;
int a, b;
int playerTurn;

int main()
{	
	srand(time(NULL));
	mainMenu();
	firstMove();
	battleSim();
}

void mainMenu()
{
	//Header
	cout << "Welcome to the Game of War!" << endl;
	cout << "---------------------------" << endl;

	//Get Player Names
	cout << "Player 1, please enter your name: ";
	cin >> nameA;
	cout << "\nPlayer 2, please enter your name: ";
	cin >> nameB;

	//Display Class
	cout << "\n-----------------------------------------------------------" << endl;
	dmgClass();
	hpClass();
	luckClass();
	cout << "-----------------------------------------------------------" << endl;

	//Get Player Classes
	cout << nameA << ", please select a class (Damage/Health/Luck): ";
	cin >> classA;
	cout << endl;
	cout << nameB << ", please select a class (Damage/Health/Luck): ";
	cin >> classB;
	cout << endl << endl;
	system("cls");

	//Get Class
	getClass();

	//Welcome
	cout << "Goal: Defeat the other player by dropping their health to 0." << endl;
	cout << "\nBegin!\n" << endl;
}


void dmgClass()
{
	hp1 = 100, dmg1 = 10, luck1 = 37;
	cout << "(Damage) Class	| Health: " << hp1 << "	| Damage: " << dmg1 << "	| Luck: " << luck1 << endl;
}

void hpClass()
{
	hp2 = 120, dmg2 = 7, luck2 = 67;
	cout << "(Health) Class	| Health: " << hp2 << "	| Damage: " << dmg2 << "	| Luck: " << luck2 << endl;
}

void luckClass()
{
	hp3 = 100, dmg3 = 5, luck3 = 100;
	cout << "(Luck) Class	| Health: " << hp3 << "	| Damage: " << dmg3 << "	| Luck: " << luck3 << endl;
}

void getClass()
{
	if (classA == "Damage")
	{
		cout << nameA << " has selected the Damage Class!" << endl;
		hpA = hp1; dmgA = dmg1; luckA = luck1;
		dmgClass();
		cout << "-----------------------------------------------------------" << endl;
	}
	else if (classA == "Health")
	{
		cout << nameA << " has selected the Health Class!" << endl;
		hpA = hp2; dmgA = dmg2; luckA = luck2;
		hpClass();
		cout << "-----------------------------------------------------------" << endl;
	}
	else if (classA == "Luck")
	{
		cout << nameA << " has selected the Luck Class!" << endl;
		hpA = hp3; dmgA = dmg3; luckA = luck3;
		luckClass();
		cout << "-----------------------------------------------------------" << endl;
	}
	if (classB == "Damage")
	{
		cout << nameB << " has selected the Damage Class!" << endl;
		hpB = hp1; dmgB = dmg1; luckB = luck1;
		dmgClass();
		cout << "-----------------------------------------------------------" << endl;
	}
	else if (classB == "Health")
	{
		cout << nameB << " has selected the Health Class!" << endl;
		hpB = hp2; dmgB = dmg2; luckB = luck2;
		hpClass();
		cout << "-----------------------------------------------------------" << endl;
	}
	else if (classB == "Luck")
	{
		cout << nameB << " has selected the Luck Class!" << endl;
		hpB = hp3; dmgB = dmg3; luckB = luck3;
		luckClass();
		cout << "-----------------------------------------------------------" << endl;
	}
}

void firstMove()
{
	playerTurn = rand() % 2 + 1;

	if (playerTurn == 1)
	{
		cout << nameA << ", you're up first!" << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
	else
	{
		cout << nameB << ", you're up first!" << endl;
		cout << "-----------------------------------------------------------" << endl;
	}

}

void battleSim()
{
	while (hpA != 0 || hpB != 0)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;

		switch (playerTurn)
		{
		case 1:
			if (a <= luckA)
			{
				cout << nameA << "'s Turn: " << endl << endl;
				dmgP2();
				cout << "-----------------------------------------------------------" << endl;
				playerTurn = 2;
			}
			else
			{
				cout << nameA << "'s Turn: " << endl << endl;
				cout << nameA << " has missed! It is now " << nameB << "'s turn." << endl;
				cout << "-----------------------------------------------------------" << endl;
				playerTurn = 2;
			}
		case 2:
			if (b <= luckB)
			{
				cout << nameB << "'s Turn: " << endl << endl;
				dmgP1();
				cout << "-----------------------------------------------------------" << endl;
				playerTurn = 1;
			}
			else
			{
				cout << nameB << "'s Turn: " << endl << endl;
				cout << nameB << " has missed! It is now " << nameA << "'s turn." << endl;
				cout << "-----------------------------------------------------------" << endl;
				playerTurn = 1;
			}
		}
	}
	winCondition();
}

void dmgP1()
{
	hpA = hpA - dmgB;
	cout << nameB << " has hit " << nameA << " for " << dmgB << " damage!" << endl;
	cout << nameA << " has " << hpA << " health left." << endl;
}

void dmgP2()
{
	hpB = hpB - dmgA;
	cout << nameA << " has hit " << nameB << " for " << dmgA << " damage!" << endl;
	cout << nameB << " has " << hpB << " health left." << endl;
}

void winCondition()
{
	if (hpA <= 0)
	{	
		cout << endl;
		cout << nameB << " survived with " << hpB << " health! Congratulations " << nameB << ", you are the winner!" << endl;
	}
	else if (hpB <= 0)
	{
		cout << endl;
		cout << nameA << " survived with " << hpB << " health! Congratulations " << nameA << ", you are the winner!" << endl;
	}
}
