#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
	// _value = ref.getRawBits();
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	_value = val<<_bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(val*(1<<_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &ref)
{
	std::cout << "Assignation operator called" << '\n';
	_value = ref._value;
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	_value = raw;
}

int		Fixed::toInt(void) const
{
	return (_value>>_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1<<_bits));
}

std::ostream&	operator<<(std::ostream &os, const Fixed &ref)
{
	return (os << ref.toFloat());
}