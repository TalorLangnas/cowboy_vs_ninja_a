#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <climits>
#include "point.hpp"
using namespace std;
using namespace ariel;



class Character
{
    private:
    Point location;
    string name;
    int health_point;

    public:
    // Constructors:
    Character();
    Character(double, double);
    Character(Point);
    Character(string , Point);
    // copy constructor
    Character(const Character&) noexcept;
    // copy assignment operator
    Character& operator=(const Character &) noexcept;
    // move constructor
    Character(Character &&) noexcept;
    // move assignment operator
    Character& operator=(Character &&) noexcept;
    // Destructor:
    virtual ~Character();
    bool isAlive();
    double distance(Character&);
    virtual void hit(int);
    string getName();
    Point& getLocation();
    void print();
    virtual int get_health_point();
};






#endif