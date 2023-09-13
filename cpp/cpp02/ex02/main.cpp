#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		std::cout << "a=0 raw value = " << a.getRawBits() << std::endl;
		std::cout << "a=0 float value = " << a << std::endl;
		std::cout << "a=0 int value = " << a.toInt() << std::endl;
	
		a = 10;
		std::cout << "a=10 raw value = " << a.getRawBits() << std::endl;
		std::cout << "a=10 float value = " << a << std::endl;
		std::cout << "a=10 int value = " << a.toInt() << std::endl;
		std::cout << "-----------" << std::endl;

		Fixed b(-1.42f);
		std::cout << "b=-1.42f raw value = " << b.getRawBits() << std::endl;
		std::cout << "b=-1.42f float value = " << b << std::endl;
		std::cout << "b=-1.42f int value = " << b.toInt() << std::endl;
	}
	std::cout << "-----------" << std::endl;
	std::cout << "-----------" << std::endl;
	{
		Fixed	a;
		Fixed const b(10);
		Fixed const c (42.42f);
		Fixed const d(b);

		a = Fixed(1234.4321f);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
}