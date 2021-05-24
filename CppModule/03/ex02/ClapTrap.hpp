#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	int	_hitPoints;
	int	_maxHitPoints;
	int	_energyPoints;
	int	_maxEnergyPoints;
	int	_level;
	int	_meleeAttackDamage;
	int	_rangedAttackDamage;
	int	_armorDamageReduction;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &from);
	~ClapTrap();
	ClapTrap	&operator=(const ClapTrap &rvalue);

	std::string		getName(const ClapTrap &original);
	unsigned int	rangedAttack(std::string const &target);
	unsigned int	meleeAttack(std::string const &target);
	void	OutputInRed(std::string name);
	void	OutputInGreen(std::string name);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif