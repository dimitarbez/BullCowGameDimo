#pragma once

#include <string>

using FString = std::string;
using int32 = int;

// all integers initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame{
public:
	FBullCowGame(); // CONSTRUCTOR
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	void Reset(); // TODO make a more rich return value
	// provide a method for counting bulls and cows and increasing turn number, assuming valid guess
	FBullCowCount SubmitGuess(FString);

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};