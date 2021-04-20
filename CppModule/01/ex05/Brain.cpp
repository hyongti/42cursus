#include "Brain.hpp"

std::string	Brain::identify(void) const
{
	std::ostringstream	address;

	address << this;
	return (address.str());
}
