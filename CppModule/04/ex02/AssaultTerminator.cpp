#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleprts from space *" << std::endl;
} 

AssaultTerminator::AssaultTerminator(const AssaultTerminator &ref)
{
	(void)ref;
	std::cout << "* teleprts from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator		&AssaultTerminator::operator=(const AssaultTerminator &ref)
{
	(void)ref;
	return (*this);
}

AssaultTerminator		*AssaultTerminator::clone(void) const
{
	AssaultTerminator	*copy = new AssaultTerminator(*this);
	return (copy);
}

void	AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is uncleaen. PURIFY IT!" << std::endl;
}

void	AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsfists *" << std::endl;
}