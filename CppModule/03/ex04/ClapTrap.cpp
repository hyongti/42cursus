#include "ClapTrap.hpp"

void	ClapTrap::OutputInRed(std::string name)
{
	std::cout << "\033[1;31m" << name << "\033[0m";
}

void	ClapTrap::OutputInGreen(std::string name)
{
	std::cout << "\033[1;32m" << name << "\033[0m";
}

ClapTrap::ClapTrap()
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
	std::cout << "BbbBbBBBb... ClapTrap[";
	OutputInGreen(_name);
	std::cout << "](base) was created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "BbbBbBBBb... ClapTrap[";
	OutputInGreen(_name);
	std::cout << "](base) was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	*this = original;
	std::cout << "BbbBbBBBb... ClapTrap[";
	OutputInGreen(original._name);
	std::cout << "](base) was created" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &original)
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

ClapTrap::~ClapTrap(void)
{
	std::cout << "pop!!! ClapTrap[";
	OutputInGreen(_name);
	std::cout << "](base) was destroyed" << std::endl;
}

std::string		ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::rangedAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at range, causing "
		<< _rangedAttackDamage << " points of damage" << std::endl;
	return (_rangedAttackDamage);
}

unsigned int	ClapTrap::meleeAttack(std::string const& target)
{
	OutputInGreen(_name);
	std::cout << " attacks ";
	OutputInRed(target);
	std::cout << " at melee, causing "
		<< _meleeAttackDamage << " points of damage" << std::endl;
	return (_meleeAttackDamage);
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + (int)amount >= _maxHitPoints)
		_hitPoints = _maxHitPoints;
	else
		_hitPoints += amount;
	OutputInGreen(_name);
	std::cout << " was repaired (HP: " << _hitPoints << ")\n" << std::endl;  
}

void	ClapTrap::showData(void)
{
	std::cout << "====" << this->_name << "====" << std::endl;
	std::cout << this->_hitPoints << std::endl;
	std::cout << this->_maxHitPoints << std::endl;
	std::cout << this->_energyPoints << std::endl;
	std::cout << this->_maxEnergyPoints << std::endl;
	std::cout << this->_meleeAttackDamage << std::endl;
	std::cout << this->_rangedAttackDamage << std::endl;
	std::cout << this->_armorDamageReduction << std::endl;
}