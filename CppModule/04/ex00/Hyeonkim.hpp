#ifndef HYEONKIM_HPP
# define HYEONKIM_HPP

#include "Victim.hpp"

class Hyeonkim: public Victim
{
private:

public:
	Hyeonkim();
	Hyeonkim(std::string name);
	Hyeonkim(const Hyeonkim &ref);
	~Hyeonkim();
	Hyeonkim	&operator=(const Hyeonkim &ref);

	void	getPolymorphed() const;
};

#endif