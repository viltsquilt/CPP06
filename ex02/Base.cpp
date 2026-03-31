#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base*	generate(void)
{
	srand(time(NULL));
	int	arrayNum[3] = {1, 2, 3};
	int	randIndex = rand() % 3;
	int	index = arrayNum[randIndex];
	if (index == 1)
		return (new A);
	else if (index == 2)
		return (new B);
	else
		return (new C);
	
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	if (p == NULL)
		std::cout << "I ain't got no type." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

