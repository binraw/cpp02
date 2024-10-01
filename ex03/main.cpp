#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"
int main( void )
 {

Point a (3.4777, 5.656);
Point b(6.3123, 4.4324);
Point c(1.3432, 5.2244);



Point test(3.54, 5.1111);
std::cout << "Correct :" << std::endl;
std::cout << bsp(a, b, c , test) << std::endl;
std::cout << "Wrong :" << std::endl;
Point wrong_test(0.45355, 10.654654);
std::cout << bsp(a, b, c , wrong_test) << std::endl;
std::cout << "Wrong :" << std::endl;
Point wrong_test1(32, 64);
std::cout << bsp(a, b, c , wrong_test1) << std::endl;


Point A (0.0f, 0.0f); 
Point B(5.0f, 0.0f); 
Point C(0.0f, 5.0f); 
Point P(1.0f, 1.0f);
std::cout << "Correct :" << std::endl;
std::cout << bsp(A, B, C , P) << std::endl;

Point point1(1, 1); 
Point point2(5, 1); 
Point point3(3, 4); 
Point PP(2, 2);
std::cout << "Correct :" << std::endl;
std::cout << bsp(point1, point2, point3 , PP) << std::endl;
return 0;
}