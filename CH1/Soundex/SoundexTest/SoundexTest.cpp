// Copyright 2018 Luca Di Sera
//		Contact: disera.luca@gmail.com
//				 https://github.com/diseraluca
//				 https://www.linkedin.com/in/luca-di-sera-200023167
//
// This code is licensed under the MIT License. 
// More informations can be found in the LICENSE file in the root folder of this repository
//
//
// File : SoundexTest.cpp

#include "catch.hpp"
#include "Soundex.h"

TEST_CASE("The code first letter is the same as the unencoded string's with upper case", "[soundex][encode]") {
	REQUIRE(SoundexEncoder::encode("aBCD").front() == 'A');
}

TEST_CASE("Encode should ignore occurences of the characters [a, e, i, o, u, y, h, w] after the first character of the word", "[soundex][encode]") {
	REQUIRE(SoundexEncoder::encode("NAEIHI") == "N000");
}

TEST_CASE("Encode is case insensitive", "[soundex][encode]") {
	REQUIRE(SoundexEncoder::encode("PoLiKeAn") == SoundexEncoder::encode("pOLikEaN"));
}

TEST_CASE("Encode replaces consonants with digits", "[soundex][encode]") {
	REQUIRE(SoundexEncoder::encode("KKN") == "K250");
}

TEST_CASE("The code should be of lenght four", "[soundex][encode]") {
	CHECK(SoundexEncoder::codeLength == 4);

	REQUIRE(SoundexEncoder::encode("Pee").length() == SoundexEncoder::codeLength);
}

TEST_CASE("Codes that aren't of the correct length should be padded with zeroes", "[soundex][encode]") {
	REQUIRE(SoundexEncoder::encode("Be") == ("B000"));
}