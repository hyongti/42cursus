#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(const Fixed &ref);
	~Fixed();
	
	Fixed&	operator=(const Fixed &ref);
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif