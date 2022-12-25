#include "../inc/template.hpp"

int main( void ) {

std::cout << "============= INT ===============" << std::endl;
int a = 2;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << "============ SWAP =============" << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl << std::endl;

std::cout << "======= STD::STRING ========" << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << "============ SWAP =============" << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl << std::endl;

std::cout << "=========== OBJECT ============" << std::endl;
Example x(2), y(4);
std::cout << "x = " << x << ", y = " << y << std::endl;

std::cout << "============ SWAP =============" << std::endl;
swap(x, y);
std::cout << "x = " << x << ", y = " << y << std::endl;

std::cout << "============================" << std::endl;
std::cout << "min( y, z ) = " << ::min( x , y ) << std::endl;
std::cout << "max( y, z ) = " << ::max( x , y ) << std::endl;


return 0;
}
