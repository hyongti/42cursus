#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage): name(name), apcost(apcost), damage(damage)
{
}

AWeapon::AWeapon(const AWeapon &ref)
{
	*this = ref;
}

AWeapon::~AWeapon()
{
}

AWeapon		&AWeapon::operator=(const AWeapon &ref)
{
	this->name = ref.name;
	this->apcost = ref.apcost;
	this->damage = ref.damage;
	return (*this);
}

std::string	AWeapon::getName() const
{
	return (this->name);
}

int	AWeapon::getAPCost() const
{
	return (this->apcost);
}

int	AWeapon::getDamage() const
{
	return (this->damage);
}
