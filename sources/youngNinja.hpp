#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP
# include "ninja.hpp"
using namespace std;
using namespace ariel;

class YoungNinja:public Ninja
{
    public:
    YoungNinja();
    YoungNinja(string, Point);
};
#endif