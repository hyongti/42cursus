#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	FragTrap amy("AMY");
	ScavTrap bob("BOB");
	NinjaTrap wayne("WAYNE");
	SuperTrap superman("Clark");

	amy.showData();
	bob.showData();
	wayne.showData();
	superman.showData();

	std::cout << "\n======BATTLE STARTED======" << std::endl;
	bob.takeDamage(amy.meleeAttack("BOB"));
	amy.takeDamage(bob.rangedAttack("AMY"));
	bob.beRepaired(40);
	amy.beRepaired(40);
	bob.takeDamage(amy.vaulthunter_dot_exe("BOB"));
	wayne.takeDamage(amy.vaulthunter_dot_exe("WAYNE"));
	bob.ChallengeNewcomer();
	wayne.ninjaShoebox(amy);
	wayne.ninjaShoebox(bob);

	std::cout << "\n======After battle======" << std::endl;
	amy.showData();
	bob.showData();
	wayne.showData();
	superman.showData();
	std::cout << std::endl;

	return (0);
}