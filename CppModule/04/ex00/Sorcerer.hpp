#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
protected:
	std::string	name;
	std::string	title;
public:
	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &from);
	~Sorcerer();
	Sorcerer&	operator=(const Sorcerer &ref);

	std::string	getName() const;
	std::string getTitle() const;
	void	getPolymorphed(const Victim &ref) const;
};

std::ostream&	operator<<(std::ostream &os, const Sorcerer &ref);

#endif
