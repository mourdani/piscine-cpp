#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Iter.tpp"

class Example {
public:
	Example( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & out, Example const & rhs ) {
    out << rhs.get();
    return out;
}

#endif
