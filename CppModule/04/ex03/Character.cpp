#include "Character.hpp"

Character::Character(std::string name): _name(name), _equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &ref)
{
	*this = ref;
}

Character::~Character()
{
	int	i = -1;

	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
}

Character		&Character::operator=(const Character &ref)
{
	int i;

	i = -1;
	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_name = ref.getName();
	i = -1;
	while (ref._inventory[++i])
		this->equip(ref._inventory[i]->clone());
	return (*this);
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL || this->_equipped > 3)
		return ;
	for (int i = 0; i < this->_equipped; i++)
	{
		if (this->_inventory[i] == m)
			return ;
	}
	this->_inventory[this->_equipped++] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= _equipped)
		return ;
	while (idx < 3)
	{
		this->_inventory[idx] = this->_inventory[idx + 1];
		++idx;
	}
	this->_inventory[idx] = NULL;
	this->_equipped -= 1;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_equipped)
		return ;
	this->_inventory[idx]->use(target);
}