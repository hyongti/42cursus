#include "Victim.hpp"

Victim::Victim(std::string name): name(name)
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &ref)
{
	*this = ref;
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim		&Victim::operator=(const Victim &ref)
{
	this->name = ref.name;
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, const Victim &ref)
{
	os << "I am " << ref.getName() << " and I like otters!" << std::endl;
	return (os);
}

std::string		Victim::getName() const
{
	return (this->name);
}

void		Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}
