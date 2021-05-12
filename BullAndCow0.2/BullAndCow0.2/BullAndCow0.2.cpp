#include <iostream>
#include <stdio.h>
#include "my_class.h" // header file
#include <stdlib.h>   // srand, rand 
#include <time.h>     // time 


int main()
{
	srand(time(NULL));
	N::my_class mc;

	mc.Set_game();

	while (mc.input != "fim")
	{
		//std::cout << "escreva a palavra:";
		std::cin >> mc.input;


		if (mc.validWord(mc.input))
		{
			mc.IsCorrect(mc.input);
		}
		else if (mc.input != "reset" && mc.input != "fim")
		{
			std::cout << "escreva corretamente: ";
		}
		else if (mc.input == "reset")
		{
			mc.Set_game();
		}
	}

	return 0;
}

void N::my_class::IsCorrect(std::string inputWord)
{
	if (inputWord != palavraSecreta)
	{
		for (int i = 0; i < palavraSecreta.length(); i++)
		{
			if (palavraSecreta[i] == inputWord[i])
				bull++;

			for (int j = 0; j < palavraSecreta.length(); j++)
			{
				if (palavraSecreta[i] == input[j] && i != j)
					cow++;
			}
		}
	}
	else
	{
		std::cout << "Is correct word, if you want to play again type reset:";
		return;
	}

	if (inputWord != "fim" && inputWord != "reset")
		std::cout << "bull: " << bull << " cow: " << cow << std::endl;

	cow = 0, bull = 0;
}

bool N::my_class::validWord(std::string inputWord)
{

	for (int i = 0; i < palavraSecreta.length(); i++)
	{
		for (int j = i + 1; j < palavraSecreta.length(); j++)
		{
			if (inputWord[i] == inputWord[j] && i != j)
				return false;
		}
	}

	if (palavraSecreta.length() != inputWord.length())
		return false;

	return true;

}

std::string N::my_class::randonWord(int numLetter)
{
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
	return "ERROR";
}

void N::my_class::Set_game()
{
	palavraSecreta = randonWord(rand() % 5 + 3);
	system("clear");
	std::cout << "Welcome to Bull and Cow game!!!\n" <<
		"Tip: word have " << palavraSecreta.length() <<
		" letters. \nEscreva: ";
}