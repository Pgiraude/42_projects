#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon(void);
        ~Weapon(void);

        std::string const &getType();
        void    setType(std::string new_type);
    
    private:
        std::string _type;
        
};

#endif