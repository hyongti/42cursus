#include "FragTrap.hpp"

std::string	FragTrap::skillset[5] = {
	"Drop the Hammer",
	"Coinsidental Combustion",
	"Hyperion Punch",
	"Repulsive",
	"Second Wind"
};

void	FragTrap::OutputInRed(std::string name)
{
	std::cout << "\033[1;31m" << name << "\033[0m";
}

void	FragTrap::OutputInGreen(std::string name)
{
	std::cout << "\033[1;32m" << name << "\033[0m";
}

FragTrap::FragTrap()
{
	srand(time(NULL));
	for(int i = 0; i < 8; i++)
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
	std::cout << " was created" << std::endl;
}

FragTrap::FragTrap(std::string name): _name(name)
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
	std::cout << " was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original)
{
	*this = original;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(original._name);
	std::cout << " was created" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &original)
{
	this->_name = original._name;
	this->_hitPoints = original._hitPoints;
	this->_maxHitPoints = original._maxHitPoints;
	this->_maxEnergyPoints = original._maxEnergyPoints;
	this->_energyPoints = original._energyPoints;
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
	std::cout << " was destroyed" << std::endl;
}

std::string		FragTrap::getName(const FragTrap &original)
{
	return (original._name);
}

unsigned int	FragTrap::rangedAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at range, causing "
		<< _rangedAttackDamage << " points of damage" << std::endl;
	return (_rangedAttackDamage);
}

unsigned int	FragTrap::meleeAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at melee, causing "
		<< _meleeAttackDamage << " points of damage" << std::endl;
	return (_meleeAttackDamage);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int	damage = amount - _armorDamageReduction;

	if (amount == 0)
		return ;
	if (_hitPoints == 0)
	{
		OutputInRed(_name);
		std::cout << " was already broken ;(\n" << std::endl;
	}
	else if (damage >= _hitPoints)
	{
		OutputInRed(_name);
		std::cout << " has taken " << _hitPoints << " point(s) of damage!";
		_hitPoints = 0;
		std::cout << " (remaining HP :" << _hitPoints << ")" << std::endl;
		OutputInRed(_name);
		std::cout << " was completely broken\n" << std::endl;
	}
	else
	{
		_hitPoints -= damage;
		OutputInRed(_name);
		std::cout << " has taken " << damage << " point(s) of damage! " << "(remaining HP :"
			<< _hitPoints << ")\n" << std::endl;
	}
	
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + (int)amount >= _maxHitPoints)
		_hitPoints = _maxHitPoints;
	else
		_hitPoints += amount;
	OutputInGreen(_name);
	std::cout << " was repaired (HP: " << _hitPoints << ")\n" << std::endl;  
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