#include "Fixed.hpp"

int main(void)
{
	std::cout << "---------- test n°1 ----------" << std::endl << std::endl;
	{
		Fixed a(11.42f);
		std::cout << "a=11.42f raw value = " << a.getRawBits() << std::endl;
		std::cout << "a=11.42f float value = " << a << std::endl;
		std::cout << "a=11.42f int value = " << a.toInt() << std::endl << std::endl;

		Fixed copy_a(a);
		std::cout << "copy_a = a raw value = " << copy_a.getRawBits() << std::endl;
		std::cout << "copy_a = a float value = " << copy_a << std::endl;
		std::cout << "copy_a = a int value = " << copy_a.toInt() << std::endl << std::endl;

		Fixed b(1);
		std::cout << "b=1 raw value = " << b.getRawBits() << std::endl;
		std::cout << "b=1 float value = " << b << std::endl;
		std::cout << "b=1 int value = " << b.toInt() << std::endl << std::endl;
	
		Fixed c;
		std::cout << "c no value define default = 0 raw value = " << c.getRawBits() << std::endl;
		std::cout << "c no value define default = 0 float value = " << c << std::endl;
		std::cout << "c no value define default = 0 int value = " << c.toInt() << std::endl << std::endl;
	}
	std::cout << "---------- test n°2 ----------" << std::endl << std::endl;
	{
		Fixed a;
		Fixed b(10.42f);
		std::cout << "a = 0  b = 10.42f" << std::endl;
		if (a == b)
			std::cout << "a == b" << std::endl;
		if (a != b)
			std::cout << "a != b" << std::endl;
		if (a < b)
			std::cout << "a < b" << std::endl;
		if (a > b)
			std::cout << "a > b" << std::endl;
		if (a <= b)
			std::cout << "a <= b" << std::endl;
		if (a >= b)
			std::cout << "a >= b" << std::endl;
		std::cout << std::endl;

		Fixed c(12.001f);
		Fixed d(12);
		std::cout << "c = 12.001f = 0  d = 12" << std::endl;
		if (c == d)
			std::cout << "c == d" << std::endl;
		if (c != d)
			std::cout << "c != d" << std::endl;
		if (c < d)
			std::cout << "c < d" << std::endl;
		if (c > d)
			std::cout << "c > d" << std::endl;
		if (c <= d)
			std::cout << "c <= d" << std::endl;
		if (c >= d)
			std::cout << "c >= d" << std::endl;
		std::cout << std::endl;

		Fixed e(3);
		Fixed f(3.01f);
		std::cout << "e = 3  f = 3.01f" << std::endl;
		if (e == f)
			std::cout << "e == f" << std::endl;
		if (e != f)
			std::cout << "e != f" << std::endl;
		if (e < f)
			std::cout << "e < f" << std::endl;
		if (e > f)
			std::cout << "e > f" << std::endl;
		if (e <= f)
			std::cout << "e <= f" << std::endl;
		if (e >= f)
			std::cout << "e >= f" << std::endl;
		std::cout << std::endl;
	}
	std::cout << "---------- test n°3 ----------" << std::endl << std::endl;
	{
		Fixed a(1.4f);
		std::cout << "a=1.4f raw value = " << a.getRawBits() << std::endl;
		std::cout << "a=1.4f float value = " << a << std::endl;
		std::cout << "a=1.4f int value = " << a.toInt() << std::endl << std::endl;

		std::cout << "a++ = " << a++ << std::endl;
		std::cout << "after a++ a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "after a-- a = " << a << std::endl << std::endl;

		Fixed b(3.6f);
		std::cout << "b=3.6f raw value = " << b.getRawBits() << std::endl;
		std::cout << "b=3.6f float value = " << b << std::endl;
		std::cout << "b=3.6f int value = " << b.toInt() << std::endl << std::endl;

		std::cout << "++b = " << ++b << std::endl;
		std::cout << "after ++b b = " << b << std::endl;
		std::cout << "--b = " << --b << std::endl;
		std::cout << "after --b b = " << b << std::endl;
	}
	std::cout << "---------- test n°4 ----------" << std::endl << std::endl;
	{
		Fixed a;
		Fixed b(10.42f);
		std::cout << "a = 0  b = 10.42f" << std::endl;
		std::cout << "Max value = " << Fixed::max(a, b) << std::endl;
		std::cout << "Min value = " << Fixed::min(a, b) << std::endl;
	}
	std::cout << "---------- test n°5 ----------" << std::endl << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed(5.05f) * Fixed(2) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
	
		std::cout << b << std::endl;
	
		std::cout << Fixed::max(a, b) << std::endl;
	}
}