#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
protected:
	std::string	name;
public:
	Victim();
	Victim(std::string name);
	Victim(const Victim &ref);
	virtual ~Victim();
	Victim	&operator=(const Victim &ref);

	std::string	getName() const;
	virtual void	getPolymorphed() const;
};

std::ostream&	operator<<(std::ostream &os, const Victim &ref);

#endif
