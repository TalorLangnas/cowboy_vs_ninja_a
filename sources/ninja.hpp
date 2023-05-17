#ifndef NINJA_HPP
#define NINJA_HPP
#include "character.hpp"
using namespace std;

class Ninja: public Character
{
    private:
    int velocity;

    public:
    Ninja();
    Ninja(double, double);
    Ninja(Point);
    Ninja(string, Point);
    virtual void move(Character*);
    virtual void slash(Character*);
};

#endif