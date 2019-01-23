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
	std::cout << "Welcome to yeet and skeet, a juicy meme game!\n";
	std::cout << "Can you guess of the " << BCGame.GetHiddenWordLength() << " letter isogram ya boi is thinking of?";
	std::cout << std::endl;
	return;
}

// loop continuoussly until the user gives a valid guess
FText GetValidGuess() 
{	
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". ";
		// asks for a guess
		std::cout << "Enter a word: ";
		FText Guess = "";
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
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors

}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetValidGuess(); 

		// submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
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
