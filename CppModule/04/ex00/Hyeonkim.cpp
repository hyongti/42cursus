#include "Hyeonkim.hpp"

Hyeonkim::Hyeonkim(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Hyeonkim::Hyeonkim(const Hyeonkim &ref): Victim(ref.name)
{
	std::cout << "Zog zog." << std::endl;
}

Hyeonkim::~Hyeonkim()
{
	std::cout << "Bleuark..." << std::endl;
}

Hyeonkim		&Hyeonkim::operator=(const Hyeonkim &ref)
{
	this->name = ref.name;
	return (*this);
}

void		Hyeonkim::getPolymorphed() const
{
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}
