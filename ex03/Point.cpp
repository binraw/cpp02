#include "Point.hpp"


Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(float nb_a, float nb_b)
{
    this->x = nb_a;
    this->y = nb_b;
}

Point::Point(const Point &other)
{
    *this = other;
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Point::~Point()
{
}

float Point::getX(void)
{
    return this->x.toFloat();
}

float Point::getY(void)
{
    return this->y.toFloat();
}

bool no_lign(Point  a, Point  b, Point  c)
{
    if (a.getX() > b.getX() || a.getX() < b.getX())
        return true;
    else if (a.getX() > c.getX() || a.getX() < c.getX())
        return true;
    else if (b.getX() > c.getX() || b.getX() < c.getX())
        return true;
    else
        return false;
}

bool no_summit(Point  a, Point  b, Point  c)
{
    if (a.getY() > b.getY() || a.getY() < b.getY())
        return true;
    else if (a.getY() > c.getY() || a.getY() < c.getY())
        return true;
    else if (b.getY() > c.getY() || b.getY() < c.getY())
        return true;
    else
        return false;
}

float max_pointX(Point  a, Point  b, Point  c)
{
    if (a.getX() > b.getX())
    {
        if(a.getX() > c.getX())
            return a.getX();
        else
            return c.getX();
    }
    else if (b.getX() > c.getX())
        return b.getX();
    else
        return c.getX();
}

float max_pointY(Point  a, Point  b, Point  c)
{
    if (a.getY() > b.getY())
    {
        if(a.getY() > c.getY())
            return a.getY();
        else
            return c.getY();
    }
    else if (b.getY() > c.getY())
        return b.getY();
    else
        return c.getY();
}

float min_pointX(Point a, Point  b, Point  c)
{
    if (a.getX() < b.getX())
    {
        if(a.getX() < c.getX())
            return a.getX();
        else
            return c.getX();
    }
    else if (b.getX() < c.getX())
        return b.getX();
    else
        return c.getX();
}

float min_pointY(Point  a, Point  b, Point  c)
{
    if (a.getY() < b.getY())
    {
        if(a.getY() < c.getY())
            return a.getY();
        else
            return c.getY();
    }
    else if (b.getY() < c.getY())
        return b.getY();
    else
        return c.getY();
}

float area( Point& a,  Point& b, Point& c) 
{
    return a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()) / 2.0;
}


bool isPointInTriangle(Point& a, Point& b, Point& c, Point& p)
{
    float a_abc = area(a, b, c);
    if (a_abc < 0)
        a_abc *= -1;
    float a_abp = area(a, b, p);
    if (a_abp < 0)
        a_abp *= -1;
    float a_bcp = area(b, c, p);
    if (a_bcp < 0)
        a_bcp *= -1;
    float a_cap = area(c, a, p);
    if (a_cap < 0)
        a_cap *= -1;
    if (a_abc == a_abp + a_bcp + a_cap)
        return true;

    return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point copy_a(a);
    Point copy_b(b);
    Point copy_c(c);
    Point copy_point(point);

    if (isPointInTriangle(copy_a, copy_b, copy_c, copy_point) == true)
        return true;
    return false;
}