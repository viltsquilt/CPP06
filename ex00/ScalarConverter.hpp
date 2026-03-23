#pragma once

#include <iostream>
#include <limits>
#include <cctype>

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& orig);
			ScalarCoverter&	operator=(const ScalarConverter& orig);
			~ScalarConverer();
			static void	convert(std::string value);
};
