#include <iostream>       // std::cout
#include <stdio.h>
#include "my_class.h" // header file
#include <stdlib.h>   // srand, rand 
#include <time.h>     // time 
#include <string>         // std::string
#include <locale>         // std::locale, std::isdigit
#include <sstream>        // std::stringstream
#include <algorithm>
int main()
{
	// ramdom gererator claas func 
	srand((unsigned int)time(NULL));
	// link the heade file
	N::my_class mc;
	// welcome to player, tip and a explanation
	mc.Set_game();

	// game loop
	while (mc.input != "quit")
	{

		std::cin >> mc.input;// get the guess of player
		//int toupper(int c);
		std::for_each(mc.input.begin(), mc.input.end(), [](char& c) // putting the guess in lower case letter
			{
			c = ::tolower(c);
			});
		
		if (mc.validWord(mc.input)) // validation the player guess
		{
			mc.IsCorrect(mc.input); // comparing the guess and the secret word
		}
		else if (mc.input != "reset" && mc.input != "quit") // restart or quit the game or the player wrote it wrong
		{
			std::cout << "write correctly: ";
		}
		else if (mc.input == "reset")
		{
			mc.Set_game();
		}
		
	}

	return 0;
}

// function to compare the entry and secret word
void N::my_class::IsCorrect(std::string inputWord)
{
	if (inputWord != secretWord) // if the guess(inputWord) is not equal to secret word, the program will count the bulls and cows
	{
		for (size_t i = 0; i < secretWord.length(); i++)
		{
			if (secretWord[i] == inputWord[i])
				cow++;

			for (size_t j = 0; j < secretWord.length(); j++)
			{
				if (secretWord[i] == input[j] && i != j)
				bull++;
			}
		}
	}
	else
	{
		std::cout << "Is correct word, if you want to play again type \"reset\" ou \"quit\" to end game:";
		return; // break the function to not show the count of bulls and cows because the guess is right
	}

	if (inputWord != "quit" && inputWord != "reset")
		std::cout << "bull: " << bull << " cow: " << cow << std::endl;

	cow, bull = 0;
}

// function to validate the entry
bool N::my_class::validWord(std::string inputWord)
{
	int a{};
	if (inputWord.length() == secretWord.length()) {
		for (size_t i = 0; i < secretWord.length(); i++)// loop to see if there are duplicate letters
		{

			for (size_t j = i + 1; j < secretWord.length(); j++)
			{
				if (inputWord[i] == inputWord[j] && i != j)
					return false;
			}
		}
		for (size_t i = 0; i < secretWord.length(); i++)// loop to see if there are number
		{
			if (isdigit(inputWord[i]))
			{
				a++;
			}
		}
		for (size_t i = 0; i < secretWord.length(); i++)
		{
			if (!(inputWord[i] >= 97 && inputWord[i] <= 122))
				return false;		
		}
	}
	if ((secretWord.length() != inputWord.length()) || (a != 0))
		return false;

	return true;

}

// function that generates the secret word
std::string N::my_class::randonWord(int numLetter)
{
	// based on the length given by the random number you get a random word from a list of 10 words
	if (numLetter == 3)
	{
		return screctWord3[rand() % 9 + 0];
	}
	else if (numLetter == 4)
	{
		return screctWord4[rand() % 9 + 0];
	}
	else
	{
		return screctWord5[rand() % 9 + 0];
	}
	std::cout << "ERROR" << std::endl;
	return NULL;
}

// function that prepares the game and the welcome
void N::my_class::Set_game()
{
	// getting the secret word based on a first random number to determine its length
	secretWord = randonWord(rand() % 5 + 3);
	//clean the screen
	system("cls");
	std::cout << "Welcome to Bull and Cow game!!!\n" <<
		" \"Cow\" means a letter in the wrong position, while \"Bull\" means a letter in the right position.\n" <<
		"Tip: the word has no duplicate letters and have " << secretWord.length() <<
		" letters. \nWrite: ";
}