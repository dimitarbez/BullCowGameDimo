// BullCowGameDimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void Introduction();
std::string GetGuess();
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
	std::cout << "Welcome to yeet and skeet, a juicy meme game!\n";
	std::cout << "Can you guess of the " << WORD_LENGTH << " letter isogram ya boi is thinking of?";
	std::cout << std::endl;
	return;
}

std::string GetGuess()
{	
	// asks for a guess
	std::cout << "Enter a word: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);


	return Guess;
}



void PlayGame()
{
	FBullCowGame BCGame; // instantiate a new game

	constexpr int MAX_TRIES = 5;
	for (int i = 0; i < MAX_TRIES; i++)
	{
		std::string Guess = GetGuess();

		// print the guess back
		std::cout << "Your guess was: " << Guess << std::endl;


		std::cout << std::endl;
	}

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string response = "";
	std::getline(std::cin, response);
	std::cout << "Is it y?\n" ;
	if ((response[0] == 'y') || (response[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}

}
