#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	static std::string skillset[5];
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& original);
	FragTrap&	operator=(const FragTrap &original);
	~FragTrap();

	unsigned int	vaulthunter_dot_exe(std::string const & target);
};

#endif