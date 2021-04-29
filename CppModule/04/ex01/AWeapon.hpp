#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
protected:
	std::string	name;
	int			apcost;
	int			damage;
public:
	AWeapon();
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &ref);
	virtual ~AWeapon();
	AWeapon	&operator=(const AWeapon &ref);

	std::string	getName() const;
	int	getAPCost() const;
	int	getDamage() const;
	virtual void attack() const = 0;
};

#endif