#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &ref): Victim(ref.name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon		&Peon::operator=(const Peon &ref)
{
	this->name = ref.name;
	return (*this);
}

void		Peon::getPolymorphed() const
{
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}
