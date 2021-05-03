#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

const Brain&	Human::getBrain(void) const
{
	return (this->brain);
}

std::string		Human::identify(void) const
{
	return (this->brain.identify());
}
