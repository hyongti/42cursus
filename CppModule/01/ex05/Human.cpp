#include "Human.hpp"

const Brain		&Human::getBrain(void) const
{
	return (this->brain);
}

std::string		Human::identify(void) const
{
	return (this->brain.identify());
}
