#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

std::string	Brain::identify(void) const
{
	std::ostringstream	address;

	address << this;
	return (address.str());
}
