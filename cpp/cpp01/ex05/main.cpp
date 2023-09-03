#include "Harl.hpp"

int main(void)
{
    Harl test1;

    test1.complain("DEBUG");
    std::cout << "----------" << std::endl;
    test1.complain("ERROR");
    std::cout << "----------" << std::endl;
    test1.complain("WARNING");
    std::cout << "----------" << std::endl;
    test1.complain("INFO");
    std::cout << "----------" << std::endl;
    test1.complain("qskjfdnkfsdkfds");
}