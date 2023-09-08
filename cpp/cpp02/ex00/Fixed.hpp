#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed &copy);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        

    private:
        int _nb;
};





#endif