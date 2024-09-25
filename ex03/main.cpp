#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"
int main( void ) {
Point a (3.4777, 5.656);
Point b(6.3123, 4.4324);
Point c(1.3432, 5.2244);
Point test(3.54, 5.1111);
std::cout << bsp(a, b, c , test) << std::endl;
return 0;
}