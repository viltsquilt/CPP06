#pragma once

#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include <cmath>
#include <regex>

class ScalarConverter
{
	private:
			enum valueType
			{
				CHAR,
				INT,
				DOUBLE,
				FLOAT,
				NEGINFF,
				POSINFF,
				NNANF,
				NEGINF,
				POSINF,
				NNAN,
				ERROR,
			};
			ScalarConverter();
			ScalarConverter(const ScalarConverter& orig);
			ScalarConverter&	operator=(const ScalarConverter& orig);
			~ScalarConverter();
			static valueType	matchType(const std::string &literal);
			static bool			checkLimits(double value);
			static bool			printTypes(const std::string &literal, valueType type);
	public:
			static void	convert(const std::string &literal);
};
