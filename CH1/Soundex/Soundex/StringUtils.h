#pragma once

#include <string>

namespace StringUtils {
	std::string head(const std::string& string) {
		return std::string() + string.front();
	}

	std::string padToLength(const std::string & string, char paddingChar, unsigned int length)
	{
		std::string paddedWord{ string };
		while (paddedWord.length() < length) {
			paddedWord += paddingChar;
		}

		return paddedWord;
	}

	std::string padWithZeroes(const std::string& string, unsigned int length) {
		return padToLength(string, '0', length);
	}
}