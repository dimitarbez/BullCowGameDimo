#include "pch.h"
#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

FBullCowGame::FBullCowGame(){ Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

// recieves a valid guess, increments turn, returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;


	// loop through all letters in the guess
		//compare letters against the hidden word

	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
