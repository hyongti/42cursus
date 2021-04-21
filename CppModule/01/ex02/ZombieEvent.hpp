#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <time.h>
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string	type;
public:
	void	setZombieType(std::string type);
	void	randomChump();
	Zombie	*newZombie(std::string name);
};

#endif