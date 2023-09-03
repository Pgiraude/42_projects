#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl
{
    public:
        void    complain(std::string);
        Harl(void);
        ~Harl(void);

    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif