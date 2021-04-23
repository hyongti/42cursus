#include "ScavTrap.hpp"

std::string	ScavTrap::challenges[5] = {
	"Did you try to open me?",
	"A single mag won't be enough!",
	"Let's get this party started!",
	"You call yourself a badass?",
	"Did someone feel something?"
};

ScavTrap::ScavTrap(): ClapTrap()
{
	// srand(time(NULL));
	// for(int i = 0; i < 8; i++)
	// 	_name += rand() % 26 + 'a';
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(_name);
	std::cout << "(driven) was created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(_name);
	std::cout << "(driven) was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original): ClapTrap(original._name)
{
	*this = original;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(original._name);
	std::cout << "(driven) was created" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &original)
{
	this->_name = original._name;
	this->_hitPoints = original._hitPoints;
	this->_maxHitPoints = original._maxHitPoints;
	this->_energyPoints = original._energyPoints;
	this->_level = original._level;
	this->_meleeAttackDamage = original._meleeAttackDamage;
	this->_rangedAttackDamage = original._rangedAttackDamage;
	this->_armorDamageReduction = original._armorDamageReduction;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "pop!!! ";
	OutputInGreen(_name);
	std::cout << "(driven) was destroyed" << std::endl;
}

void	ScavTrap::ChallengeNewcomer(void)
{
	OutputInGreen(_name);
	std::cout << ": " << challenges[rand() % 5] << std::endl;
}