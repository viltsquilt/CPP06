#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& orig)
{
	(void)orig;
}

Serializer&	Serializer::operator=(const Serializer& orig)
{
	(void)orig;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	address = reinterpret_cast<uintptr_t>(ptr);
	return (address);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}

Data::Data()
{
}

Data::Data(const Data& orig)
{
	name = orig.name;
	level = orig.level;
}

Data&	Data::operator=(const Data& orig)
{
	if (this != &orig)
	{
		name = orig.name;
		level = orig.level;
	}
	return (*this);
}

Data::~Data()
{
}

std::ostream&	operator<<(std::ostream& os, const Data& orig)
{
	os << "Data address: " << &orig << std::endl;
	return (os);
}
