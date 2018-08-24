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
	std::string encodedWord = std::string() + "A";
	while (encodedWord.length() < 4) {
		encodedWord += "_";
	}

	return encodedWord;
}
