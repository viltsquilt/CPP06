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

void	ScalarConverter::convert(std::string value)
{
	std::string	resc;
	int			resi;
	float		resf;
	double		resd;
	valueType	errflag;
	valueType	flag;

	if (value.length() >= 1)
	{
		errflag = IMPOSSIBLE;
		flag = My_IsNum(value);
		if (flag == INT)
		{
			resi = std::stoi(value);
			resf = static_cast<float>(resi);
			resd = static_cast<double>(resi);
		}
		else if (flag == DOUBLE)
		{
			resd = std::stod(value);
			resi = static_cast<int>(resd);
			resf = static_cast<float>(resd);
		}
		else if (flag == FLOAT)
		{
			resf = std::stod(value);
			resi = static_cast<int>(resf);
			resd = static_cast<double>(resf);
		}
		else if (flag == NEGINF || flag == NEGINFF)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return ;
		}
		else if (flag == POSINF || flag == POSINFF)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return ;
		}
		else if (flag == NAN || flag == NANF)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
	}
	else
	{
		if (My_IsChar(value))
		{
			flag = CHAR;
			errflag = OK;
			resc = value;
			resi = std::stoi(value);
			resf = static_cast<float>(resi);
			resd = static_cast<double>(resi);
		}
		else
		{
			flag = INT;
			errflag = ERROR;
		}
	}
	if (flag == INT || flag == DOUBLE || flag == FLOAT)
	{
		valueType	chartype = NumToChar(resi);
		if (chartype == ERROR)
			errflag = ERROR;
		else if (chartype == IMPOSSIBLE)
			errflag = IMPOSSIBLE;
		else
		{
			errflag = OK;
			resc = std::to_string(resi);
		}
	}
	if (errflag == ERROR)
	{
		resc = "Non displayable";
	}
	else if (errflag == IMPOSSIBLE)
	{
		resc = "Impossible";
	}
	else
	{
		std::cout << "char: '" << resc << "'" << std::endl;
		std::cout << "int: " << resi << std::endl;
		std::cout << "float: " << resf << std::endl;
		std::cout << "double: " << resd << std::endl;
	}
}

ScalarConverter::valueType		ScalarConverter::NumToChar(int num)
{
	if (num <= 47 || num == 127)
		return (ERROR);
	else if (num > 127)
		return (IMPOSSIBLE);
	else
		return (OK);
}

bool	ScalarConverter::My_IsChar(std::string s)
{
	int	noflag = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 21 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 126))
			continue;
		else
		{
			noflag = 1;
		}
	}
	if (noflag == 1)
		return(false);
	return (true);
}

ScalarConverter::valueType	ScalarConverter::My_IsNum(std::string s)
{
	int	iflag = 0;
	int	fflag = 0;
	int	dotflag = 0;
	long long num = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (i == 0 && (s[i] == '+' || s[i]  == '-'))
			continue;
		if (s[i] >= 48 && s[i] <= 57)
		{
			iflag = 1;
		}
		else if (s[i] == '.')
		{
			dotflag++;
		}
		else if (s[s.length() - 1] == 'f')
		{
			fflag = 1;
		}
		else if (s == "-inff")
			return (NEGINFF);
		else if (s == "+inff")
			return (POSINFF);
		else if (s == "nanf")
			return (NANF);
		else if (s == "-inf")
			return (NEGINF);
		else if (s == "+inf")
			return (POSINF);
		else if (s == "nan")
			return (NAN);
		else
			return (ERROR);
	}
	num = std::stoll(s);
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return (INT_MAXMIN);	
	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
		return (FLOAT_MAXMIN);
	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
		return (DOUBLE_MAXMIN);
	if (iflag == 1 && dotflag == 1 && fflag == 0)
		return (DOUBLE);
	else if (iflag == 1 && dotflag == 0 && fflag == 0)
		return  (INT);
	else if (iflag == 1 && dotflag == 1 && fflag == 1)
		return (FLOAT);
	else
		return (ERROR);
}
