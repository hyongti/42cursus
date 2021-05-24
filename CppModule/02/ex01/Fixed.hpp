#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(const Fixed &ref);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	
	Fixed&	operator=(const Fixed &ref);
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &os, const Fixed &ref);

#endif