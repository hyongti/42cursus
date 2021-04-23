#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	static std::string challenges[5];
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& original);
	ScavTrap&	operator=(const ScavTrap &original);
	~ScavTrap();

	void	ChallengeNewcomer(void);
};

#endif