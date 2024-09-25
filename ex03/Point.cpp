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

bool no_lign(Point const a, Point const b, Point const c)
{
    if (a.getX() > b.getX() || a.getX() < b.getX())
        return true;
    else if (a.getX() > c.getX() || a.getX < c.getX())
        return true;
    else if (b.getX() > c.getX() || b.getX() < c.getX())
        return true;
    else
        return false;
}

bool no_summit(Point const a, Point const b, Point const c)
{
    if (a.getY() > b.getY() || a.getY() < b.getY())
        return true;
    else if (a.getY() > c.getY() || a.getY < c.getY())
        return true;
    else if (b.getY() > c.getY() || b.getY() < c.getY())
        return true;
    else
        return false;
}

float max_pointX(Point const a, Point const b, Point const c)
{
    if (a.getX() > b.getX())
    {
        if(a.getX > c.getX())
            return a.getX();
        else
            return c.getX();
    }
    else if (b.getX() > c.getX())
        return b.getX();
    else
        return c.getX();
}

float max_pointY(Point const a, Point const b, Point const c)
{
    if (a.getY() > b.getY())
    {
        if(a.getY > c.getY())
            return a.getX();
        else
            return c.getX();
    }
    else if (b.getY() > c.getY())
        return b.getX();
    else
        return c.getX();
}

float min_pointX(Point const a, Point const b, Point const c)
{
    if (a.getX() < b.getX())
    {
        if(a.getX < c.getX())
            return a.getX();
        else
            return c.getX();
    }
    else if (b.getX() < c.getX())
        return b.getX();
    else
        return c.getX();
}

float min_pointY(Point const a, Point const b, Point const c)
{
    if (a.getY() < b.getY())
    {
        if(a.getY < c.getY())
            return a;
        else
            return c;
    }
    else if (b.getY() < c.getY())
        return b;
    else
        return c;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (!no_lign(a, b, c) && !no_summit(a, b, c))
        return false;
    if (point.getX() < max_pointX(a, b, c))
    {
        if (point.getX() > min_pointX(a, b, c))
        {
            if (point.getY() < max_pointY(a, b, c))
            {
                if (point.getY() > min_pointY(a, b, c))
                    return true;
            }
        }
    }
    return false;
}