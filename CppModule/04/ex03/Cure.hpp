#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure &ref);
	virtual ~Cure();
	Cure	&operator=(const Cure &ref);

	virtual Cure	*clone() const;
	virtual void	use(ICharacter &target);
};

#endif