#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter(const ScalarConverter& orig)
{

}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& orig)
{

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
	int			errflag;
	int			flag;

	if (value.len() >= 1)
	{
		errflag = IMPOSSIBLE;
		int	type = My_IsNum(value);
		if (type == INT)
		{
			flag = INT;
			resi = value;
			resf = static_cast<float>(value);
			resd = static_cast<double>(value);
		}
		else if (type == DOUBLE)
		{
			flag = DOUBLE;
			resd = value;
			resi = static_cast<int>(value);
			resf = static_cast<float>(value);
		}
		else if (type == FLOAT)
		{
			flag = FLOAT;
			resf = value;
			resi = static_cast<int>(value);
			resd = static_cast<double>(value);
		}
	}
	else if (value.len() == 1)
	{
		if (My_IsChar(value))
		{
			flag = CHAR;
			errflag = OK;
			resc = value;
			resi = static_cast<int>(value);
			resf = static_cast<float>(value);
			resd = static_cast<double>(value);
		}
	}
	if (type == INT || type == DOUBLE || type == FLOAT)
	{
		int chartype = NumToChar(resi);
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
	if (errflag == ERROR)
	{
		resc = "Non displayable";
	}
	else if (errflag == IMPOSSIBLE)
	{
		resc = "Impossible";
	}
	std::cout << "char: " << resc << std::endl;
	std::cout << "int: " << resi << std::endl;
	std::cout << "float: " << resf << std::endl;
	std::cout << "double: " << resd << std::endl;
}

int		NumToChar(int num)
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

int	My_IsNum(std::string s)
{
	int	dotflag = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
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
		else
		{
			int noflag = 1;
		}
	}
	if (noflag)
		return (ERROR);
	else if (iflag && dotflag == 1 && !fflag)
		return (DOUBLE);
	else if (iflag && dotflag == 0 && !fflag)
		return  (INT);
	else if (iflag && dotflag == 1 && fflag)
		return (FLOAT);
	else
		return (ERROR);
}
