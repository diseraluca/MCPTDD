#pragma once

#include <string>
#include <cctype>

namespace StringUtils {
	std::string head(const std::string& string) {
		return string.substr(0, 1);
	}

	std::string tail(const std::string& string) {
		return (string.length() == 0) ? "" : string.substr(1);
	}

	std::string upper(const std::string& string) {
		std::string uppercaseString{};

		for (auto character : string) {
			uppercaseString += std::toupper(character);
		}

		return uppercaseString;
	}

	std::string lower(const std::string& string) {
		std::string lowercaseString{};

		for (auto character : string) {
			lowercaseString += std::tolower(character);
		}

		return lowercaseString;
	}

	std::string padToLength(const std::string & string, char paddingChar, size_t length)
	{
		std::string paddedWord{ string };
		while (paddedWord.length() < length) {
			paddedWord += paddingChar;
		}

		return paddedWord;
	}

	std::string padWithZeroes(const std::string& string, size_t length) {
		return padToLength(string, '0', length);
	}
}