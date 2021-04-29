#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist: public AWeapon
{
private:

public:
	PowerFist();
	PowerFist(const PowerFist &ref);
	~PowerFist();
	PowerFist	&operator=(const PowerFist &ref);

	void	attack() const;
};

#endif