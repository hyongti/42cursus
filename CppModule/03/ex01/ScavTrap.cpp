#include "ScavTrap.hpp"

std::string	ScavTrap::challenges[5] = {
	"Did you try to open me?",
	"A single mag won't be enough!",
	"Let's get this party started!",
	"You call yourself a badass?",
	"Did someone feel something?"
};

void	ScavTrap::OutputInRed(std::string name)
{
	std::cout << "\033[1;31m" << name << "\033[0m";
}

void	ScavTrap::OutputInGreen(std::string name)
{
	std::cout << "\033[1;32m" << name << "\033[0m";
}

ScavTrap::ScavTrap()
{
	srand(time(NULL));
	for(int i = 0; i < 8; i++)
		_name += rand() % 26 + 'a';
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(_name);
	std::cout << " was created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): _name(name)
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
	std::cout << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original)
{
	*this = original;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(original._name);
	std::cout << " was created" << std::endl;
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
	std::cout << " was destroyed" << std::endl;
}

std::string		ScavTrap::getName(const ScavTrap &original)
{
	return (original._name);
}

unsigned int	ScavTrap::rangedAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at range, causing "
		<< _rangedAttackDamage << " points of damage" << std::endl;
	return (_rangedAttackDamage);
}

unsigned int	ScavTrap::meleeAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at melee, causing "
		<< _meleeAttackDamage << " points of damage" << std::endl;
	return (_meleeAttackDamage);
}

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + (int)amount >= _maxHitPoints)
		_hitPoints = _maxHitPoints;
	else
		_hitPoints += amount;
	OutputInGreen(_name);
	std::cout << " was repaired (HP: " << _hitPoints << ")\n" << std::endl;  
}

void	ScavTrap::ChallengeNewcomer(void)
{
	OutputInGreen(_name);
	std::cout << ": " << challenges[rand() % 5] << std::endl;
}