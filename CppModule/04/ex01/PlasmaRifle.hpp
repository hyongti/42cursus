#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
private:

public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &ref);
	~PlasmaRifle();
	PlasmaRifle	&operator=(const PlasmaRifle &ref);

	void	attack() const;
};

#endif