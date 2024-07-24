#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif