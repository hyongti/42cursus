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
	srand(time(NULL));
	_name = rand() % 26 + 'a';
	for(int i = 0; i < 7; i++)
		_name += rand() % 26 + 'a';
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "BbbBbBBBb... ScavTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "BbbBbBBBb... ScavTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original): ClapTrap(original._name)
{
	*this = original;
	std::cout << "BbbBbBBBb... ScavTrap[";
	OutputInGreen(original._name);
	std::cout << "](driven) was created" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &original)
{
	this->_name = original._name;
	this->_hitPoints = original._hitPoints;
	this->_maxHitPoints = original._maxHitPoints;
	this->_energyPoints = original._energyPoints;
	this->_maxEnergyPoints = original._maxEnergyPoints;
	this->_level = original._level;
	this->_meleeAttackDamage = original._meleeAttackDamage;
	this->_rangedAttackDamage = original._rangedAttackDamage;
	this->_armorDamageReduction = original._armorDamageReduction;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "pop!!! ScavTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was destroyed" << std::endl;
}

void	ScavTrap::ChallengeNewcomer(void)
{
	OutputInGreen(_name);
	std::cout << ": " << challenges[rand() % 5] << std::endl;
}