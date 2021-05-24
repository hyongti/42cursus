#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
protected:
	int			hp;
	std::string	type;
public:
	Enemy();
	Enemy(int hp, std::string const &type);
	Enemy(const Enemy &ref);
	virtual ~Enemy();
	Enemy	&operator=(const Enemy &ref);

	std::string	getType() const;
	int		getHP() const;
	void	setHP(int hp);
	virtual void takeDamage(int);
};

#endif