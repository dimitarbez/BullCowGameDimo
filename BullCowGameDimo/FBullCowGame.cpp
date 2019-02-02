#pragma once

#include "pch.h"
#include "FBullCowGame.h"
#include <map>
// make syntax UE4 friendly
#define TMap std::map


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsWon; }


bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{	
		// if the letter is not lower case
		if (!islower(Letter))
		{
			// false it
			return false;
		}
	}
	// otherwise
	return true;
}

FBullCowGame::FBullCowGame(){ Reset(); } // default constructor

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,6},{5,10},{6,15},{7,20}};
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this MUST be an isogram

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsWon = false;

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
	// num of bulls fills the word
	if (BullCowCount.Bulls == GuessWordLength)
	{
		bIsWon = true;
	}
	else
	{
		bIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{	
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	// setup our map
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)	// for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case letters

		if (LetterSeen[Letter] == true) // if the letter is in the map
		{
			return false; // we do not have an isogram
		}
		else // otherwise
		{
			LetterSeen[Letter] = true; // add it to the map
		}
			
				
			
				
	}
	return true; // for example in cases where /0 is entered
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lower case 
	else if (!IsLowerCase(Guess))	
	{
		return EGuessStatus::Not_Lowercase;	// TODO write function 
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
