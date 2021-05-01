#include "Squad.hpp"

Squad::Squad(): count(0), units(NULL)
{
}

Squad::Squad(const Squad &ref): count(0), units(NULL)
{
	for (int i = 0; i < ref.getCount(); i++)
		this->push(ref.getUnit(i)->clone());
}

Squad::~Squad()
{
	if (this->units != NULL)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
	}
}

Squad		&Squad::operator=(const Squad &ref)
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
		this->units = NULL;
	}
	for (int i = 0; i < ref.getCount(); i++)
		this->push(ref.getUnit(i)->clone());
	return (*this);
}

int			Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine	*Squad::getUnit(int index) const
{
	if (count == 0 || index < 0 || index >= count)
		return (NULL);
	else
	{
		return (units[index]);
	}
	
}

int			Squad::push(ISpaceMarine *unit)
{
	if (this->units != NULL)
	{
		for (int i = 0; i < this->count; i++)
		{
			if (this->units[i] == unit)
				return (this->count);
			ISpaceMarine **copy = new ISpaceMarine*[this->count + 1];
			for (int i = 0; i < this->count; i++)
				copy[i] = this->units[i];
			delete[] this->units;
			this->units = copy;
			this->units[this->count] = unit;
			this->count += 1;
		}
	}
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->count = 1;
	}
	return (this->count);
}