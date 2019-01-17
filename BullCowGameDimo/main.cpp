// BullCowGameDimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void Introduction();
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

int main()
{
	bool bPlayAgain = false;
	do
	{
		Introduction();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	
	return 0;
}


void Introduction()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to yeet and skeet, a juicy meme game!\n";
	cout << "Can you guess of the " << WORD_LENGTH << " letter isogram ya boi is thinking of?";
	cout << endl;
	return;
}

string GetGuess()
{	
	// asks for a guess
	cout << "Enter a word: ";
	string Guess = "";
	getline(cin, Guess);


	return Guess;
}



void PlayGame()
{
	constexpr int MAX_TRIES = 5;
	for (int i = 0; i < MAX_TRIES; i++)
	{
		string Guess = GetGuess();

		// print the guess back
		cout << "Your guess was: " << Guess << endl;


		cout << endl;
	}

}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n) ";
	string response = "";
	getline(cin, response);
	cout << "Is it y?" ;
	if ((response[0] == 'y') || (response[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}

}
