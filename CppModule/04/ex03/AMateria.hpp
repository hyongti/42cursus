#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string		_type;
	unsigned int	_xp;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &ref);
	virtual ~AMateria();
	AMateria			&operator=(const AMateria &ref);

	std::string const	&getType() const;
	unsigned int		getXP() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif