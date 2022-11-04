#include "../inc/Fixed.hpp"

Fixed::Fixed(): _number(0){
    std::cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed &n){
    std::cout << "Copy constructor called\n";
    *this = n;
}

Fixed::~Fixed(){
    std::cout << "Deconstructor called\n";
};

Fixed &Fixed::operator=(const Fixed &n){
    std::cout << "Assignation operator called\n";
    setRawBits(n.getRawBits());
    return *this;
}


int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called\n";
    return this->_number;

}

void Fixed::setRawBits( int const bits ){
    this->_number = bits;
}