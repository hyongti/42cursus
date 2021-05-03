#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	int		_count;
	AMateria	*_materia[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &ref);
	virtual ~MateriaSource();
	MateriaSource	&operator=(const MateriaSource &ref);

	virtual void		learnMateria(AMateria*);
	virtual	AMateria	*createMateria(std::string const &type);
};

#endif