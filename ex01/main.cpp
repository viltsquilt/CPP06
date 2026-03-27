#include "Serializer.hpp"

int	main(void)
{
	Data	value;
	Data*	ptr = &value;

	std::cout << ptr << std::endl;
	uintptr_t	raw = Serializer::serialize(ptr);
	std::cout << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << ptr << std::endl;
	return(0);
}
