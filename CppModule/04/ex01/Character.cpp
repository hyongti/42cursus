#include "Character.hpp"

Character::Character(std::string const &name): name(name), ap(40)
{
}

Character::Character(const Character &ref)
{
	*this = ref;
}

Character::~Character()
{
}

Character		&Character::operator=(const Character &ref)
{
	this->name = ref.name;
	this->ap = ref.ap;
	this->weapon = ref.weapon;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Character const &ref)
{
	os << ref.getName() << " has " << ref.getAP() << " AP and ";
	if (ref.getWeapon())
		os << "wields a " << ref.getWeapon()->getName() << std::endl;
	else
		os << "is unarmed" << std::endl;
	return (os);
}

void			Character::recoverAP(void)
{
	if (this->ap < 30)
		this->ap += 10;
	else
		this->ap = 40;
}

void			Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void			Character::attack(Enemy *enemy)
{
	if (this->weapon)
	{
		if (this->ap > weapon->getAPCost())
		{
			std::cout << name << " attacks " << enemy->getType()
				<< "with a " << this->weapon->getName() << std::endl;
			this->ap -= weapon->getAPCost();
			this->weapon->attack();
			enemy->takeDamage(this->weapon->getDamage());
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
}

std::string		Character::getName(void) const
{
	return (this->name);
}

int				Character::getAP(void) const
{
	return (this->ap);
}

AWeapon			*Character::getWeapon(void) const
{
	return (this->weapon);
}