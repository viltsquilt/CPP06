#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	(void)argc;
	try
	{
		const std::string literal = argv[1];
		ScalarConverter::convert(literal);
	}
	catch (std::exception &e)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
	}
	return (0);
}
