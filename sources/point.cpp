#include "point.hpp"
using namespace ariel;

// Constructor:
Point::Point(double other_x, double other_y)
{
    x = other_x;
    y = other_y;
};
double Point::distance(Point other)
{
    return 0;
};
string Point::print()
{
    return "(x,y)";
};
Point Point::moveTowards(Point srce, Point dst, double dist)
{
    Point point = Point(1,1);
    return point;
};
bool Point::operator==(const Point& other) const
{
    return false;       
};