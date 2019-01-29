#include "pch.h"
#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return false; }

FBullCowGame::FBullCowGame(){ Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

// recieves a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	int32 GuessWordLength = Guess.length();
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			// if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// if they're in the same place 
				if (MHWChar == GChar)
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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lower case 
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	// if the guess length is wrong
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Wrong_Length;
	}
	// otherwise
	else
	{
		// return OK
		return EGuessStatus::OK;
	}

}
