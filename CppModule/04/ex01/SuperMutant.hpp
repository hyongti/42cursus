#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant: public Enemy
{
private:

public:
	SuperMutant();
	SuperMutant(const SuperMutant &ref);
	~SuperMutant();
	SuperMutant	&operator=(const SuperMutant &ref);

	void	takeDamage(int damage);
};

#endif