#pragma once

#include <iostream>
#include <string>

class Fixed {
    private:
        int _number;
        int const static _bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &n);
        ~Fixed();
        Fixed &operator=(const Fixed &n);
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};