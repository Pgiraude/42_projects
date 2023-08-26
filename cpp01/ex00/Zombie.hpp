#ifndef ZOMBIE_H
    #define ZOMBIE_H

#include <string>

class Zombie
{
    private:
        std::string name();

    public:
        void    annonce(void);
        Zombie();
        ~Zombie();
};

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}

#endif