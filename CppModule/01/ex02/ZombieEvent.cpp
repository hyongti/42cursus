#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

void	ZombieEvent::randomChump(void)
{
	std::string	NameList[] = {"hyeonkim", "kilee", "hyeonski", "taewkim", "hyopark", "cjang", "napark", "junghkim"};

	int			index;

	srand(time(NULL));
	index = rand() % 8;
	// 하드코딩보다는 배열 길이 구해서 넣어주기
	Zombie		zombie(NameList[index], type);
	zombie.announce();
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name, type);
	return (zombie);
}