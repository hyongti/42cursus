#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad: public ISquad
{
private:
	int	count;
	ISpaceMarine **units;
public:
	Squad();
	Squad(const Squad &ref);
	virtual ~Squad();
	Squad &operator=(const Squad &ref);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
};

#endif