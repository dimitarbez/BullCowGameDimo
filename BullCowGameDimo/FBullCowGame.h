#pragma once

#include <string>

class FBullCowGame{
public:
	FBullCowGame(); // CONSTRUCTOR
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	void Reset(); // TODO make a more rich return value

private:
	// see constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};