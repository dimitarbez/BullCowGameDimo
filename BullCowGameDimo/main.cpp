// BullCowGameDimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>


using namespace std;


void Introduction();
string GetGuessAndPrintBack();
void LoopTurns();


int main()
{
	Introduction();
	
	// loop for the number of turns asking for guesses
	LoopTurns();

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

string GetGuessAndPrintBack()
{	
	// asks for a guess
	cout << "Enter a word: ";
	string Guess = "";
	getline(cin, Guess);

	// print the guess back
	cout << "Your guess was: " << Guess << endl;

	return Guess;
}

void LoopTurns()
{
	constexpr int MAX_TRIES = 5;
	for (int i = 0; i < MAX_TRIES; i++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}
}
