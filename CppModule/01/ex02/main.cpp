#include "ZombieEvent.hpp"

int		main(void)
{
	Zombie	zombie1("hyeonkim", "latte");
	zombie1.announce();

	ZombieEvent	zombieEvent1;
	zombieEvent1.setZombieType("jammin");
	Zombie	*zombie2 = zombieEvent1.newZombie("hyeonski");
	zombie2->announce();
	delete(zombie2);

	ZombieEvent	zombieEvent2;
	zombieEvent2.setZombieType("cadet");
	zombieEvent2.randomChump();
}