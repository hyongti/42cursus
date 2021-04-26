#include "SuperTrap.hpp"

SuperTrap::SuperTrap(): ClapTrap(), FragTrap(), NinjaTrap()
{
	srand(time(NULL));
	_name = rand() % 26 + 'a';
	for(int i = 0; i < 7; i++)
		_name += rand() % 26 + 'a';
	_hitPoints = this->FragTrap::_hitPoints;
	_maxHitPoints = this->FragTrap::_maxHitPoints;
	_energyPoints = this->NinjaTrap::_energyPoints;
	_maxEnergyPoints = this->NinjaTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = this->NinjaTrap::_meleeAttackDamage;
	_rangedAttackDamage = this->FragTrap::_rangedAttackDamage;
	_armorDamageReduction = this->FragTrap::_armorDamageReduction;
	std::cout << "BbbBbBBBb... SuperTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

SuperTrap::SuperTrap(std::string name): ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	_hitPoints = this->FragTrap::_hitPoints;
	_maxHitPoints = this->FragTrap::_maxHitPoints;
	_energyPoints = this->NinjaTrap::_energyPoints;
	_maxEnergyPoints = this->NinjaTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = this->NinjaTrap::_meleeAttackDamage;
	_rangedAttackDamage = this->FragTrap::_rangedAttackDamage;
	_armorDamageReduction = this->FragTrap::_armorDamageReduction;
	std::cout << "BbbBbBBBb... SuperTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &original)
{
	*this = original;
	std::cout << "BbbBbBBBb... SuperTrap[";
	OutputInGreen(original._name);
	std::cout << "](driven) was created" << std::endl;
}

SuperTrap		&SuperTrap::operator=(const SuperTrap &original)
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

SuperTrap::~SuperTrap()
{
}
