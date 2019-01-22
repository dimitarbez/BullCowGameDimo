/*
	This is the console excecutable that makes use of the BullCow class
	This acts as the view in an MVC pattern, and is reponsible for all user interaction.
	For game logic and the FBullCowGame class.
*/
#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

void Introduction();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game	

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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to yeet and skeet, a juicy meme game!\n";
	std::cout << "Can you guess of the " << WORD_LENGTH << " letter isogram ya boi is thinking of?";
	std::cout << std::endl;
	return;
}

FText GetGuess()
{	
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". ";
	// asks for a guess
	std::cout << "Enter a word: ";
	FText Guess = "";
	std::getline(std::cin, Guess);


	return Guess;
}



void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid guesses

		// submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print the number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
	// TODO add a game summary
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText response = "";
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
