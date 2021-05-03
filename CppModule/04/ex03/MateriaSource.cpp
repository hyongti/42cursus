#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _count(0)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	*this = ref;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource		&MateriaSource::operator=(const MateriaSource &ref)
{
	for (int i = 0; i < this->_count; i++)
	{
		delete this->_materia[i];
		this->_materia[i] = NULL;
	}
	for (int i = 0; i < ref._count; i++)
		this->learnMateria(ref._materia[i]);
	return (*this);
}

void				MateriaSource::learnMateria(AMateria *m)
{
	if (this->_count > 3 || m == NULL)
		return ;
	this->_materia[this->_count++] = m->clone();
}

AMateria*			MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (0);
}