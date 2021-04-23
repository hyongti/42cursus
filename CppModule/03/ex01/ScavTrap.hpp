#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
private:
	std::string	_name;
	int	_hitPoints;
	int	_maxHitPoints;
	int	_energyPoints;
	int	_level;
	int	_meleeAttackDamage;
	int	_rangedAttackDamage;
	int	_armorDamageReduction;
	static std::string challenges[5];
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& original);
	ScavTrap&	operator=(const ScavTrap &original);
	~ScavTrap();

	std::string		getName(const ScavTrap &original);
	unsigned int	rangedAttack(std::string const &target);
	unsigned int	meleeAttack(std::string const &target);
	void	OutputInRed(std::string name);
	void	OutputInGreen(std::string name);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	ChallengeNewcomer(void);
};

#endif