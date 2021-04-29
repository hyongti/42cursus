#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title): name(name), title(title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &ref)
{
	*this = ref;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer		&Sorcerer::operator=(const Sorcerer &ref)
{
	this->name = ref.name;
	this->title = ref.title;
	return (*this);
}

std::string		Sorcerer::getName(void) const
{
	return (this->name);
}

std::ostream&	operator<<(std::ostream &os, const Sorcerer &ref)
{
	os << "I am " << ref.getName() << ", " << ref.getTitle() << ", and I like ponies!" << std::endl;
	return (os);
}

std::string		Sorcerer::getTitle(void) const
{
	return (this->title);
}

void	Sorcerer::getPolymorphed(const Victim &ref) const
{
	ref.getPolymorphed();
}
