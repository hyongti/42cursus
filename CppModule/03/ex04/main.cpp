#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	SuperTrap	anonymous;
	std::cout<<"============================\n";
	SuperTrap	hyeonkim("hyeonkim");
	SuperTrap	hyopark("hyopark");
	SuperTrap	kilee1("kilee");
	SuperTrap	kilee2(kilee1);

	std::cout<<"========================================\n";
	hyeonkim.takeDamage(hyopark.rangedAttack(hyeonkim.getName()));  // hyopark이 hyeonkim angedAttack
	hyeonkim.showData();
	hyopark.takeDamage(hyeonkim.meleeAttack(hyopark.getName()));  // hyeonkim이 hyopark meleeAttack
	hyopark.showData();

	hyeonkim.beRepaired(100);  // hyeonkim 회복
	hyeonkim.showData();
	hyopark.beRepaired(100);  // hyopark 회복
	hyopark.showData();

	std::cout<<"========================================\n";
	std::cout<<"\n===== random attack! =====\n\n";
	for(int i=1; i<=5; i++)
	{
		std::cout<<"----- "<<i<<"th random attack! -----\n";
		hyeonkim.takeDamage(hyopark.vaulthunter_dot_exe(hyeonkim.getName()));  // hyopark이 랜덤무기로 hyeonkim 공격
		hyeonkim.showData();
		hyopark.showData();
	}

	std::cout<<"\n===== ninjaShoebox attack! =====\n\n";
	ClapTrap    mijeong("mijeong");
	FragTrap    ukim("ukim");
	hyeonkim.ninjaShoebox(mijeong);
	hyeonkim.ninjaShoebox(ukim);
	std::cout<<"\n=================================\n\n";
}