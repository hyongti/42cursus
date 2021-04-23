#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
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
	static std::string skillset[5];
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& original);
	FragTrap&	operator=(const FragTrap &original);
	~FragTrap();

	std::string		getName(const FragTrap &original);
	unsigned int	rangedAttack(std::string const &target);
	unsigned int	meleeAttack(std::string const &target);
	void	OutputInRed(std::string name);
	void	OutputInGreen(std::string name);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	unsigned int	vaulthunter_dot_exe(std::string const & target);
};

#endif