#pragma once
#include <string>
#include <iostream>
#include <vector>

#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

// testing namespace
namespace N
{

	class my_class
	{
	public:

		// words to discover
		std::string screctWord3[10] = { "ceu", "mal", "paz", "dia", "sol", "rua", "som", "sal", "mar", "uva" };
		std::string screctWord4[10] = { "amor", "ruim", "vida", "alvo", "doce", "joia", "selo", "mato", "peso", "lixo" };
		std::string screctWord5[10] = { "nobre", "vigor", "poder", "afeto", "justo", "tempo", "mundo", "vetor", "multa", "chuva" };
		
		// all var used in the game and func
		int cow{}, bull{}, iter{};
		std::string palavraSecreta{}, input{};
		std::vector <int> vector1, vector2;
		std::vector<std::vector<int>> vector_2d;

		// header functions
		void IsCorrect(std::string inputWord); // function to compare the entry and secret word
		bool validWord(std::string inputWord); // function to validate the entry
		std::string randonWord(int numLetter); // function that generates the secret word
		void Set_game(); // function that prepares the game and the welcome
		
	};
}

#endif/* MY_CLASS_H */