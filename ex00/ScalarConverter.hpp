#pragma once

#include <iostream>
#include <limits>
#include <cctype>

class ScalarConverter
{
	private:
			enum valueType
			{
				CHAR
				INT
				DOUBLE
				FLOAT
				NEGINFF
				POSINFF
				NANF
				NEGINF
				POSINF
				NAN
				ERROR
				IMPOSSIBLE
				OK
			};
			ScalarConverter();
			ScalarConverter(const ScalarConverter& orig);
			ScalarCoverter&	operator=(const ScalarConverter& orig);
			~ScalarConverer();
			bool	My_IsChar(std::string s);
			int		My_IsNum(std::string s);
			int		NumToChar(int num);
	public:
			static void	convert(std::string value);
};
