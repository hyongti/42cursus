#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
private:
	/* data */
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &originam);
	~NinjaTrap();
	NinjaTrap	&operator=(const NinjaTrap &from);

	void	ninjaShoebox(ClapTrap &ClapTrap);
	void	ninjaShoebox(FragTrap &FragTrap);
	void	ninjaShoebox(ScavTrap &ScavTrap);
	void	ninjaShoebox(NinjaTrap &NinjaTrap);
	unsigned int	meleeAttack(const std::string &target);
	unsigned int	rangedAttack(const std::string &target);
};

#endif