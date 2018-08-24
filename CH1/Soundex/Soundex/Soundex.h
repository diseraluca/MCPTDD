// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : Soundex.h
//
// The SoundexEncoder class provides an interface to encode strings based on the Soundex Algorithm.
// Soundex is a phonetic algorithm for indexing names by sound.
// Soundex produces an identification code that is formed by a letter followed by three digits. Homophones are encoded to the same representation.
// The algorithm has the following sequence:
//
//1. Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.
//2. Replace consonants with digits as follows(after the first letter) :
//      b, f, p, v ¡ú 1
//      c, g, j, k, q, s, x, z ¡ú 2
//      d, t ¡ú 3
//      l ¡ú 4
//      m, n ¡ú 5
//      r ¡ú 6
//3. If two or more letters with the same number are adjacent in the original name(before step 1), only retain the first letter; also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice.This rule also applies to the first letter.
//4. If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. If you have more than 3 letters, just retain the first 3 numbers.

#pragma once

#include <string>

class Soundex {
public:
	static std::string encode(const std::string& word);

private:
	static std::string padToLength(const std::string& word, char paddingChar, unsigned int length);

public:
	static constexpr int codeLength{ 4 };
};