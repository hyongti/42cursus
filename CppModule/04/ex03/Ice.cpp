#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice &ref): AMateria("ice")
{
	*this = ref;
}

Ice::~Ice()
{
}

Ice		&Ice::operator=(const Ice &ref)
{
	this->_type = ref._type;
	this->_xp = ref._xp;
	return (*this);
}

Ice*	Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

void	Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}