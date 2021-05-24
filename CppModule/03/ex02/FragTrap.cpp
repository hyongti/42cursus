#include "FragTrap.hpp"

std::string	FragTrap::skillset[5] = {
	"Drop the Hammer",
	"Coinsidental Combustion",
	"Hyperion Punch",
	"Repulsive",
	"Second Wind"
};

FragTrap::FragTrap(): ClapTrap()
{
	srand(time(NULL));
	_name = rand() % 26 + 'a';
	for(int i = 0; i < 7; i++)
		_name += rand() % 26 + 'a';
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(_name);
	std::cout << "(driven) was created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(_name);
	std::cout << "(driven) was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original): ClapTrap(original._name)
{
	*this = original;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(original._name);
	std::cout << "(driven) was created" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &original)
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

FragTrap::~FragTrap(void)
{
	std::cout << "pop!!! ";
	OutputInGreen(_name);
	std::cout << "(driven) was destroyed" << std::endl;
}

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	unsigned int	skillDamage[5] = {10, 15, 20, 25, 30};
	
	if (_energyPoints >= 25)
	{
		_energyPoints -= 25;
		int	index = rand() % 5;
		OutputInGreen(_name);
		std::cout << " attacks ";
		OutputInRed(target);
		std::cout << " by " << skillset[index] << " causing "
			<< skillDamage[index] << " points of damage (EP: " << _energyPoints
			<< ")" << std::endl;
		return (skillDamage[index]);
	}
	else
	{
		OutputInGreen(_name);
		std::cout << " has not enough energy (EP: 0)" << std::endl;
		return (0);
	}
}