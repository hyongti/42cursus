#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string	name;
	int		ap;
	AWeapon	*weapon;
public:
	Character();
	Character(std::string const &name);
	Character(const Character &ref);
	~Character();
	Character	&operator=(const Character &ref);

	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
	std::string	getName() const;
	int			getAP() const;
	AWeapon		*getWeapon() const;
};

std::ostream	&operator<<(std::ostream &os, Character const &ref);

#endif