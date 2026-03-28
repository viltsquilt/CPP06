#pragma	once

#include <iostream>
#include <stdlib.h>
#include <time.h>

class	Base
{
	public:
			virtual	~Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
