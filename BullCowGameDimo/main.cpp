// BullCowGameDimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
    cout << "Welcome to yeet and skeet, a juicy meme game!\n"; 
	cout << "Can you guess of the "<<WORD_LENGTH<<" letter isogram ya boi is thinking of?";
	cout << endl;

	// get a guess from the user
	string Guess = "";
	getline(cin, Guess);
	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	return 0;
}
