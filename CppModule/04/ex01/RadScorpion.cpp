#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &ref): Enemy(ref)
{
	*this = ref;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPORTCH *" << std::endl;
}

RadScorpion		&RadScorpion::operator=(const RadScorpion &ref)
{
	Enemy::operator=(ref);
	return (*this);
}
