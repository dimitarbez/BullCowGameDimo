#pragma once

#include <string>

using FString = std::string;

class FBullCowGame{
public:
	FBullCowGame(); // CONSTRUCTOR
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	void Reset(); // TODO make a more rich return value
	// provide a method for counting bulls and cows and increasing turn number 

private:
	// see constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};