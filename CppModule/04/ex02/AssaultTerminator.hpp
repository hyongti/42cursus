#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &ref);
	virtual ~AssaultTerminator();
	AssaultTerminator& operator=(const AssaultTerminator &ref);

	virtual AssaultTerminator* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};

#endif