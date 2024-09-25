#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>
class Point
{
private:
    Fixed x;
    Fixed y;
public:
    Point();
    Point(float nb_a, float nb_b);
    Point(const Point &other);
    Point &operator=(const Point &other);
    float getX(void);
    float getY(void);
     
   
    ~Point();
};
bool bsp(Point const a, Point const b, Point const c, Point const point);
bool isPointInTriangle(const Point& a, const Point& b, const Point& c, const Point& p);
float area( Point& a,  Point& b, Point& c);
float min_pointY(Point const a, Point const b, Point const c);
float min_pointX(Point const a, Point const b, Point const c);
float max_pointY(Point const a, Point const b, Point const c);
float max_pointX(Point const a, Point const b, Point const c);
bool no_lign(Point const a, Point const b, Point const c);
bool no_summit(Point const a, Point const b, Point const c);
#endif