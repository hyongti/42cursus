#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &ref): Enemy(ref)
{
	*this = ref;
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaarg..." << std::endl;
}

SuperMutant		&SuperMutant::operator=(const SuperMutant &ref)
{
	Enemy::operator=(ref);
	return (*this);
}

void	SuperMutant::takeDamage(int damage)
{
	if (this->getHP() > 0 && damage > 3)
		this->setHP(this->getHP() - damage + 3);
}