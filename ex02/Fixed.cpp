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

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return const_cast<Fixed &>(a);
	return const_cast<Fixed &>(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return const_cast<Fixed &>(a);
	return const_cast<Fixed &>(b);
}


