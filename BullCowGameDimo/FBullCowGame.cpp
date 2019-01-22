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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	int32 GuessWordLength = Guess.length();
	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if they match
			if (Guess[i] == MyHiddenWord[i])
			{
				// if they're in the same place 
				if (i == j)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}					
				// if they're not
				else
				{
					// increment cows
					BullCowCount.Cows++;
				}
					
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
