#pragma	once

#include <iostream>
#include <cstdint>

struct	Data
{
	public:
			Data();
			Data(const Data& orig);
			Data&	operator=(const Data& orig);
			~Data();
			std::string	name = "human";
			int	level = 1;
};

class	Serializer
{
	private:
			Serializer();
			Serializer(const Serializer& orig);
			Serializer&	operator=(const Serializer& orig);
			~Serializer();
	public:
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);
};

std::ostream&	operator<<(std::ostream& os, const Data& orig);
