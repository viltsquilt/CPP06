#include "Base.hpp"

int	main(void)
{
	Base*	random = generate();
	identify(random);
	delete random;
	Base*	random2 = generate();
	identify(*random2);
	delete random2;
	return (0);
}
