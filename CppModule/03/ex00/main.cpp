#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	Fr4gTP;
	FragTrap	Fr4gTP2("hyeonkim");
	FragTrap	Fr4gTP3("blackhall");

	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.takeDamage(Fr4gTP2.rangedAttack(Fr4gTP2.getName(Fr4gTP)));
	Fr4gTP.beRepaired(100);
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
	Fr4gTP2.takeDamage(Fr4gTP3.vaulthunter_dot_exe(Fr4gTP3.getName(Fr4gTP2)));
}