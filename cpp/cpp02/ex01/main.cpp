#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    std::cout << "a 0 convert float = " << a << std::endl;
    a = 10;

    std::cout << "a raw = " << a.getRawBits() << std::endl;
 
    std::cout << "a convert = " << a.toInt() << std::endl;
    std::cout << "-----------" << std::endl;

    Fixed b(42.42f);
    std::cout << "b to float = " << b << std::endl;
    std::cout << "b convert = " << b.toInt() << std::endl;

    std::cout << "-----------" << std::endl;
    std::cout << a << std::endl;
    std::cout << "-----------" << std::endl;
    int x = 1;
    std::cout << x << std::endl;
    x = x << 8;
    std::cout << x << std::endl;

}