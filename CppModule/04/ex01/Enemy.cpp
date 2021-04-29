#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type): hp(hp), type(type)
{
}

Enemy::Enemy(const Enemy &ref)
{
	*this = ref;
}

Enemy::~Enemy()
{
}

Enemy		&Enemy::operator=(const Enemy &ref)
{
	this->hp = ref.hp;
	this->type = ref.type;
	return (*this);
}

int	Enemy::getHP(void) const
{
	return (this->hp);
}

void	Enemy::setHP(int hp)
{
	this->hp = hp;
}

std::string	Enemy::getType(void) const
{
	return (this->type);
}

void	Enemy::takeDamage(int damage)
{
	if (damage > 0)
	{
		if (this->hp >= damage)
			this->hp -= damage;
		else
			this->hp = 0;
	}
}
