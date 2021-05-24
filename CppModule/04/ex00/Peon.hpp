#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon: public Victim
{
private:
	
public:
	Peon();
	Peon(std::string name);
	Peon(const Peon &ref);
	~Peon();
	Peon	&operator=(const Peon &ref);

	void	getPolymorphed() const;
};

#endif
