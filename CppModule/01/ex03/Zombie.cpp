#include "Zombie.hpp"

void	Zombie::InitZombie(std::string name, std::string type)
{
	std::cout << "Zombie constructor is called" << std::endl;
	this->name = name;
	this->type = type;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor is called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}
