#include "../inc/Iter.hpp"

int main( void ) {

int tab[] = { 0, 1, 2, 3, 4 };
	Example tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
