#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& orig)
{
	(void)orig;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& orig)
{
	(void)orig;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string &literal)
{
	valueType	type;

	type = matchType(literal);
	if (printTypes(literal, type))
		return ;
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool	ScalarConverter::printTypes(const std::string &literal, valueType type)
{
	double	value;

	if (type == CHAR)
	{
		value = literal[0];
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
		std::cout << "int: " << static_cast<int>(value) << "\n";
		std::cout << "float: " << static_cast<float>(value) << ".0f\n";
		std::cout << "double: " << static_cast<double>(value) << ".0\n";
		return (true);
	}
	else if (type == INT || type == FLOAT || type == DOUBLE)
	{
		try
		{
			value = std::stod(literal);
		}
		catch (std::exception &e)
		{
			return (false);
		}
		if ((value >= 0 && value <= 32) || (value >= 48 && value <= 57) || (value >= 127 && value < 255))
			std::cout << "char: non displayable\n";
		if (value >= 255)
			std::cout << "char: impossible\n";
		if ((value >= 33 && value <= 47) || (value >= 58 && value <= 126))
			std::cout << "char: '" << static_cast<char>(value) << "'\n";
		if (checkLimits(value))
			return (true);
		else
			return (false);
	}
	else if (type == POSINFF || type == POSINF)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return (true);
	}
	else if (type == NEGINFF || type == NEGINF)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return (true);
	}
	else if (type == NNANF || type == NNAN)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return (true);
	}
	return (false);
}

bool ScalarConverter::checkLimits(double value)
{
	double	rounded = std::round(value);

	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
	{
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		if (rounded == value)
			std::cout << "double: " << value << ".0\n";
		else
			std::cout << "double: " << value << "\n";
		return (true);
	}
	else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible\n";
		if (rounded == value)
		{
			std::cout << "float: " << static_cast<float>(value) << ".0f\n";
			std::cout << "double: " << value << ".0\n";
		}
		else
		{
			std::cout << "float: " << static_cast<float>(value) << "f\n";
			std::cout << "double: " << value << "\n";
		}
		return (true);
	}
	else if (value <= std::numeric_limits<int>::max() || value >= std::numeric_limits<int>::min())
	{
		std::cout << "int: " << static_cast<int>(value) << "\n";
		if (rounded == value)
		{
			std::cout << "float: " << static_cast<float>(value) << ".0f\n";
			std::cout << "double: " << value << ".0\n";
		}
		else
		{
			std::cout << "float: " << static_cast<float>(value) << "f\n";
			std::cout << "double: " << value << "\n";
		}
		return (true);
	}
	else
		return (false);
}

ScalarConverter::valueType	ScalarConverter::matchType(const std::string &literal)
{
	const std::regex	reInt("(^\\+|-)?\\d+$");
	const std::regex	reFloat("^(\\+|-)?(\\d+\\.\\d+|\\.\\d+|\\d+\\.)\\f$");
	const std::regex	reDouble("^(\\+|-)?(\\d+\\.\\d+$|\\.\\d+$|\\d+\\.$)");
	const std::regex	reChar("^.$");
	const std::regex	rePosInff("^\\+inff$");
	const std::regex	reNegInff("^\\-inff$");
	const std::regex	rePosInf("^\\+inf$");
	const std::regex	reNegInf("^\\-inf$");
	const std::regex	reNanf("^nanf$");
	const std::regex	reNan("^nan$");


	if (std::regex_match(literal, reInt))
		return (INT);
	else if (std::regex_match(literal, reFloat))
		return (FLOAT);
	else if (std::regex_match(literal, reDouble))
		return (DOUBLE);
	else if (std::regex_match(literal, reChar))
		return (CHAR);
	else if (std::regex_match(literal, rePosInff))
		return (POSINFF);
	else if (std::regex_match(literal, reNegInff))
		return (NEGINFF);
	else if (std::regex_match(literal, rePosInf))
		return (POSINF);
	else if (std::regex_match(literal, reNegInf))
		return (NEGINF);
	else if (std::regex_match(literal, reNanf))
		return (NNANF);
	else if (std::regex_match(literal, reNan))
		return (NNAN);
	else
		return (ERROR);
}
