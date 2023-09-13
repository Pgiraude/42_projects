#include "Fixed.hpp"

int main(void)
{
	{
		Fixed b(11.42f);
		std::cout << "b=11.42f raw value = " << b.getRawBits() << std::endl;
		std::cout << "b=11.42f float value = " << b << std::endl;
		std::cout << "b=11.42f int value = " << b.toInt() << std::endl;

		Fixed c(0.9f);
		Fixed e(1);
		if (c >= e)
			std::cout << "OURAAAAAAAA" << std::endl;
		std::cout << "b=11.42f float value = " << c + b << std::endl;
	}
}