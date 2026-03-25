#pragma once

#include <iostream>
#include <limits>
#include <cctype>

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
				NANF,
				NEGINF,
				POSINF,
				NAN,
				ERROR,
				IMPOSSIBLE,
				OK,
				INT_MAXMIN,
				FLOAT_MAXMIN,
				DOUBLE_MAXMIN,
			};
			ScalarConverter();
			ScalarConverter(const ScalarConverter& orig);
			ScalarConverter&	operator=(const ScalarConverter& orig);
			~ScalarConverter();
			static bool		My_IsChar(std::string s);
			static valueType	My_IsNum(std::string s);
			static valueType	NumToChar(int num);
	public:
			static void	convert(std::string value);
};
