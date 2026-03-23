#pragma once

#include <iostream>
#include <limits>
#include <cctype>

#define CHAR 0
#define INT 1
#define DOUBLE 2
#define FLOAT 3
#define ERROR 4
#define IMPOSSIBLE 5
#define OK 6

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& orig);
			ScalarCoverter&	operator=(const ScalarConverter& orig);
			~ScalarConverer();
			static void	convert(std::string value);
};
bool	My_IsChar(std::string s);
int		My_IsNum(std::string s);
int		NumToChar(int num);
