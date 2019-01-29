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
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "\n\nWelcome to yeet and skeet, a juicy meme game!\n";
	std::cout << "Can you guess of the " << BCGame.GetHiddenWordLength() << " letter isogram ya boi is thinking of?";
	std::cout << std::endl;
	return;
}

// loop continuoussly until the user gives a valid guess
FText GetValidGuess() 
{	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". ";
		// asks for a guess
		std::cout << "Enter a word: ";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with out any repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << " Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;

}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won
	// and there asre still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); 

		// submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
	}
	// TODO add a game summary
	PrintGameSummary();
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n) ";
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

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "POBEDI BE SIN!\n";
	}
	else
	{
		std::cout << "E ne te biva brat toe\n";
	}
}
