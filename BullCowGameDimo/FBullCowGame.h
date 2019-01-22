#pragma once

#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame{
public:
	FBullCowGame(); // CONSTRUCTOR
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	void Reset(); // TODO make a more rich return value
	// provide a method for counting bulls and cows and increasing turn number 

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};