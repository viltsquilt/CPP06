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
	std::string	resi;
	std::string	resf;
	std::string	resd;
	int			cflag = 0;
	int			iflag = 0;
	int			fflag = 0;
	int			dflag = 0;

	for(int i = 0; value[i] != '\0'; i++)
	{
		if (value.len() >= 1)
		{
			cflag = 2;
			int	numres = my_isnum(value);
			if (numres == 0)//int
			{
				iflag = 1;
			}
			else if (numres == 2)
			{
				dflag = 1;
			}
			else if (numres == 3)
			{
				fflag = 1;
			}
		}
		else if (value.len() == 1)
		{
			if (my_ischar(value))
				cflag = 1;
		}
	}
	if (cflag == 0)
	{
		resc = "Non displayable";
	}
	else if (cflag == 2)
	{
		resc = "Impossible";
	}

	std::cout << "char: " << resc << std::endl;
	std::cout << "int: " << resi << std::endl;
	std::cout << "float: " << resf << std::endl;
	std::cout << "double: " << resd << std::endl;
}

static bool	my_ischar(std::string s)
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

static int	my_isnum(std::string s)
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
		return (1);
	else if (iflag && dotflag == 1 && !fflag)
		return (2);
	else if (iflag && dotflag == 0 && !fflag)
		return  (0);
	else if (iflag && dotflag == 1 && fflag)
		return (3);
	else
		return (1);
}
