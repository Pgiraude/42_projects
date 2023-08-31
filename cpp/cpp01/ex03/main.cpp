#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
    {
        Weapon club("crued spike");
    
        HumanA bob("bob", club);
        bob.attack();
    
        club.setType("some other type of club");
        bob.attack();
    }
    std::cout << "----------------" << std::endl;
    {
        Weapon club("crued spike");
    
        HumanB jim("jim");
        jim.setWeapon(club);

        jim.attack();
    
        club.setType("some other type of club");
        jim.attack();
    }
}