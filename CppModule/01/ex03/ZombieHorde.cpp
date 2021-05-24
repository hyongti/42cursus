#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	if (N < 0)
		N = 0;
	this->n = N;
	zombie = new Zombie[n];

	std::string	NameList[] = {"hyeonkim", "kilee", "hyeonski", "taewkim", "hyopark", "cjang", "napark", "junghkim"};

	int			index;
	srand(time(NULL));
	for (int i = 0; i < this->n; i++)
	{
		index = rand() % 8;
		zombie[i].initZombie(NameList[index], "cadet");
	}
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->n; i++)
		zombie[i].announce();
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "ZombieHorde destructor is called" << std::endl;
	delete[] zombie;
	std::cout << "all zombie object deleted" << std::endl;
}
