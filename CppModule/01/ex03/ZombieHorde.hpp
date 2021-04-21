#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie	*zombie;
	int		n;
public:
	ZombieHorde(int N);
	~ZombieHorde();
	void	announce(void);
};

#endif