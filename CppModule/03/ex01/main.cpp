#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	Fr4gTP;
	FragTrap	Fr4gTP2("hyeonkim");
	FragTrap	Fr4gTP3("blackhall");

	
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.beRepaired(20);
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));

	ScavTrap	Sc4vTP0;
	ScavTrap	Sc4vTP1("mijeong");
	ScavTrap	Sc4vTP2("kilee");

	Sc4vTP0.ChallengeNewcomer();
	Sc4vTP1.ChallengeNewcomer();
	Sc4vTP2.ChallengeNewcomer();
	Sc4vTP0.takeDamage(Sc4vTP2.rangedAttack(Sc4vTP2.getName(Sc4vTP0)));
	Sc4vTP2.beRepaired(20);
}