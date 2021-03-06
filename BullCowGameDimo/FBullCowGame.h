/*
The game logic (no view code or direct user interaction)
The game is the simple guess the word based on Mastermind
*/

#pragma once

#include <string>

// make syntax UE4 friendly
using FString = std::string;
using int32 = int;

// all integers initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame{
public:
	FBullCowGame(); // CONSTRUCTOR
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;
	

	void Reset();
	// provide a method for counting bulls and cows and increasing turn number, assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};