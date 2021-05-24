#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->name = name;
	std::cout << "Pony constructor is called" << std::endl;
	std::cout << this->name << std::endl;
}

Pony::~Pony()
{
	std::cout << this->name << std::endl;
	std::cout << "Pony Destructor is called" << std::endl;
}
