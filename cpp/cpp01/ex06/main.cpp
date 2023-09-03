#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Complain should take only 1 argument : " << std::endl;
	    std::cout << "DEBUG, INFO, WARNING or ERROR" << std::endl;
        return (0);
    }
    Harl harl;
    harl.complain(argv[1]);
}