#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter(const ScalarConverter& orig)
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

static void	ScalarConverter::convert(std::string value)
{
	std::string	resc;
	int			resi;
	float		resf;
	double		resd;
	valueType	errflag;
	valueType	flag;

	if (value.len() >= 1)
	{
		errflag = IMPOSSIBLE;
		valueType	type = My_IsNum(value);
		if (type == INT)
		{
			flag = INT;
			resi = std::stoi(value);
			resf = static_cast<float>(resi);
			resd = static_cast<double>(resi);
		}
		else if (type == DOUBLE)
		{
			flag = DOUBLE;
			resd = std::stod(value);
			resi = static_cast<int>(resd);
			resf = static_cast<float>(resd);
		}
		else if (type == FLOAT)
		{
			flag = FLOAT;
			resf = std::stod(value);
			resi = static_cast<int>(resf);
			resd = static_cast<double>(resf);
		}
	}
	else if (value.len() == 1)
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
	}
	if (type == INT || type == DOUBLE || type == FLOAT)
	{
		valueType	chartype = NumToChar(resi);
		if (chartype == ERROR)
			errflag = ERROR;
		else if (chartype == IMPOSSIBLE)
			errflag = IMPOSSIBLE;
		else
		{
			errflag = OK;
			resc = static_cast<std::string>(resi);
		}
	}
	else if (type == NEGINF || type == NEGINFF)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (type == POSINF || type == POSINFF)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (type == NAN || type == NANF)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}//needs fixing
	if (errflag == ERROR)
	{
		resc = "Non displayable";
	}
	else if (errflag == IMPOSSIBLE)
	{
		resc = "Impossible";
	}
	std::cout << "char: '" << resc << "'" << std::endl;
	std::cout << "int: " << resi << std::endl;
	std::cout << "float: " << resf << std::endl;
	std::cout << "double: " << resd << std::endl;
}

valueType		NumToChar(int num)
{
	if (num <= 47 || num == 127)
		return (ERROR);
	else if (num > 127)
		return (IMPOSSIBLE);
	else
		return (OK);
}

bool	My_IsChar(std::string s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 21 && s[i] <= 47) || (s[i] >= 58 && s <= 126))
		{
			int	cflag = 1;
		}
		else
		{
			int	noflag = 1;
		}
	}
	if (noflag)
		return(false);
	return (true);
}

valueType	My_IsNum(std::string s)
{
	int	dotflag = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (i == 0 && (s[i] == '+' || s[i]  == '-'))
			continue;
		if (s[i] >= 48 && s[i] <= 57)
		{
			int	iflag = 1;
		}
		else if (s[i] == '.')
		{
			dotflag++;
		}
		else if (s[s.len() - 1] == 'f')
		{
			int	fflag = 1;
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
	if (iflag && dotflag == 1 && !fflag)
		return (DOUBLE);
	else if (iflag && dotflag == 0 && !fflag)
		return  (INT);
	else if (iflag && dotflag == 1 && fflag)
		return (FLOAT);
	else
		return (ERROR);
}
