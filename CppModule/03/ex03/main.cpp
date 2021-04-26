#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	FragTrap amy("AMY");
	ScavTrap bob("BOB");
	ClapTrap cat("CAT");
	NinjaTrap wayne("WAYNE");
	NinjaTrap joker("JOKER");

	wayne.ninjaShoebox(amy);
	wayne.ninjaShoebox(bob);
	wayne.ninjaShoebox(cat);
	wayne.ninjaShoebox(joker);

	return (0);
}