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

TEST_CASE("The code first letter is the same as the unencoded string's", "[soundex][encode]") {
	REQUIRE(Soundex::encode("ABCD").front() == 'A');
}

TEST_CASE("Encode should ignore occurences of the characters [a, e, i, o, u, y, h, w] after the first character of the word", "[soundex][encode]") {
	REQUIRE(Soundex::encode("NAEIHI") == "N000");
}

TEST_CASE("The code should be of lenght four", "[soundex][encode]") {
	CHECK(Soundex::codeLength == 4);

	REQUIRE(Soundex::encode("English").length() == Soundex::codeLength);
}

TEST_CASE("Code that aren't of the correct length should be padded with zeroes", "[soundex][encode]") {
	REQUIRE(Soundex::encode("Be") == ("B000"));
}