#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    a = 10;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << "a=" << a.getRawBits() << std::endl;
    std::cout << "b=" << b.getRawBits() << std::endl;
    std::cout << "c=" << c.getRawBits() << std::endl;
    std::cout << a.toInt() << std::endl;

    std::cout << "-----------" << std::endl;
    std::cout << a << std::endl;
    std::cout << "-----------" << std::endl;
    int x = 10;
    std::cout << x << std::endl;
    x = x << 2;
    std::cout << x << std::endl;

}