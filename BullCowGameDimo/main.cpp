// BullCowGameDimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>


using namespace std;


void Introduction();
string GetGuess();
void PlayGame();


int main()
{
	Introduction();
	
	// loop for the number of turns asking for guesses
	PlayGame();

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
