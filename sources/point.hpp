#ifndef POINT_HPP
#define POINT_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

namespace ariel
{
class Point
{
    private:
    
    double x;
    double y;

    public:
    
    Point(double, double);
    double distance(Point);
    string print();
    Point moveTowards(Point, Point, double);
    bool operator==(const Point& other) const;

};
};
# endif