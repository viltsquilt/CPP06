#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	const std::string literal = argv[1];
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
	}
	ScalarConverter::convert(literal);
	return (0);
}
