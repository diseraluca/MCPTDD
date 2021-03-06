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

#include "StringUtils.h"

using namespace StringUtils;

const std::unordered_map<char, std::string> SoundexEncoder::characterEncodings{
	{ 'b', "1" },{ 'f', "1" },{ 'p', "1" },{ 'v', "1" },
	{ 'c', "2" },{ 'g', "2" },{ 'j', "2" },{ 'k', "2" },{ 'q', "2" },{ 's', "2" },{ 'x', "2" },{ 'z', "2" },
	{ 'd', "3" },{ 'r', "3" },
	{ 'l', "4" },
	{ 'm', "5" },{ 'n', "5" },
	{ 'r', "6" }
};

std::string SoundexEncoder::encode(const std::string & word)
{
	return padWithZeroes(head(upper(word)) + encodeDigits(tail(word)), SoundexEncoder::codeLength);
}

std::string SoundexEncoder::encodeDigits(const std::string word)
{
	std::string encodedWord{};

	for (auto letter : lower(word)) {
		encodedWord += encodeDigit(letter);
	}

	return encodedWord;
}

std::string SoundexEncoder::encodeDigit(const char letter)
{
	auto encodingsIterator{ characterEncodings.find(letter) };
	return ( encodingsIterator != characterEncodings.end()) ? encodingsIterator->second : "";
}
