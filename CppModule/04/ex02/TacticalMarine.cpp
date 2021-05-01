#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
} 

TacticalMarine::TacticalMarine(const TacticalMarine &ref)
{
	(void)ref;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine		&TacticalMarine::operator=(const TacticalMarine &ref)
{
	(void)ref;
	return (*this);
}

TacticalMarine		*TacticalMarine::clone(void) const
{
	TacticalMarine	*copy = new TacticalMarine(*this);
	return (copy);
}

void	TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void	TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}