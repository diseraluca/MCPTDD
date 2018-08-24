// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : Soundex.cpp

#include "Soundex.h"

std::string Soundex::encode(const std::string & word)
{
	std::string encodedWord = std::string() + word.front();

	return padToLength(encodedWord, '0', Soundex::codeLength);
}

std::string Soundex::padToLength(const std::string & word, char paddingChar, unsigned int length)
{
	std::string paddedWord{ word };
	while (paddedWord.length() < length) {
		paddedWord += paddingChar;
	}

	return paddedWord;
}
