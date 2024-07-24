#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->value >> Fixed::fractionalBits;
}

