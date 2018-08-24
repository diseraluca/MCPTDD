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

TEST_CASE("TheEncodedCodeFirstLetterIsTheSameAsTheUnencodedString", "[soundex][encode]") {
	REQUIRE(Soundex::encode("ABCD").front() == 'A');
}

TEST_CASE("TheEncodedCodeShouldBeOfLenghtFour", "[soundex][encode]") {
	CHECK(Soundex::codeLength == 4);

	REQUIRE(Soundex::encode("English").length() == Soundex::codeLength);
}

TEST_CASE("EncodedCodeThatAren'tOfTheCorrectLengthShouldBePaddedWithZeroes", "[soundex][encode]") {
	REQUIRE(Soundex::encode("Be") == ("B000"));
}