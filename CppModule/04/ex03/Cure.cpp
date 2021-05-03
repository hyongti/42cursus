#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure &ref): AMateria("cure")
{
	*this = ref;
}

Cure::~Cure()
{
}

Cure		&Cure::operator=(const Cure &ref)
{
	this->_type = ref._type;
	this->_xp = ref._xp;
	return (*this);
}

Cure*	Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

void	Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}