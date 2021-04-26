#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap()
{
	srand(time(NULL));
	_name = rand() % 26 + 'a';
	for(int i = 0; i < 7; i++)
		_name += rand() % 26 + 'a';
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "BbbBbBBBb... NinjaTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "BbbBbBBBb... NinjaTrap[";
	OutputInGreen(_name);
	std::cout << "](driven) was created" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &original)
{
	*this = original;
	std::cout << "BbbBbBBBb... ";
	OutputInGreen(original._name);
	std::cout << "(driven) was created" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
}

NinjaTrap		&NinjaTrap::operator=(const NinjaTrap &original)
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

unsigned int NinjaTrap::meleeAttack(std::string const &target)
{
	OutputInGreen(_name);
	std::cout << " swing is Katana and deals "
			<< _meleeAttackDamage << " points of damage to "
			<< target << "!" << std::endl;
	return (_meleeAttackDamage);
}

unsigned int NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << " throw a Shuriken at "
			<< target << " and deals " << _meleeAttackDamage
			<< " points of damage!" << std::endl;
	return (_rangedAttackDamage);
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	OutputInGreen(_name);
	std::cout << " tries to tickle FragTrap[" << trap.getName()
			<< "] but realize he has no feets." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	if (_energyPoints >= 20)
	{
		_energyPoints -= 20;
		OutputInGreen(_name);
		std::cout << " try to cut trough ScavTrap[" << trap.getName()
				<< "] and damage him for " << _rangedAttackDamage << "!" << std::endl;
		trap.takeDamage(_rangedAttackDamage);
	}
	else
	{
		OutputInGreen(_name);
		std::cout << " is too tired." << std::endl;
	}
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	if (_energyPoints >= 60)
	{
		_energyPoints -= 60;
		OutputInGreen(_name);
		std::cout << " sense the ClapTrap[" << trap.getName()
				<< "] but can't see it." << std::endl;
	}
	else
	{
		OutputInGreen(_name);
		std::cout << " finally see the ClapTrap[" << trap.getName()
				<< "] before falling on the ground." << std::endl;
		takeDamage(_hitPoints + _armorDamageReduction);
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	if ((rand() % 100) > 50)
	{
		OutputInGreen(_name);
		std::cout << " throw Shuriken at Trap[" << trap.getName()
				<< "] and damage him for " << _rangedAttackDamage << "!" << std::endl;
	}
	else
	{
		OutputInGreen(_name);
		std::cout << " throw Shuriken at NinjaTrap[" << trap.getName()
				<< "] but misses" << std::endl;
	}
}