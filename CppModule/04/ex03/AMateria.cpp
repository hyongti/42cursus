#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria &ref)
{
	*this = ref;
}

AMateria::~AMateria()
{
}

AMateria		&AMateria::operator=(const AMateria &ref)
{
	this->_type = ref._type;
	this->_xp = ref._xp;
	return (*this);
}

std::string const&	AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter &target)
{
	this->_xp += 10;
	(void)target;
}