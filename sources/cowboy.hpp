#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "character.hpp"
using namespace std;


class Cowboy: public Character
{   
    private:
    
    int ammo;

    public:

    Cowboy();
    Cowboy(double, double);
    Cowboy(Point);
    Cowboy(string, Point);
    void shoot(Character*);
    bool hasboolets();
    void reload();
    int get_ammo();
    string print();

    //The << operator to print a fraction to an output stream in the format “numerator/denominator”.
    friend std::ostream& operator<< (std::ostream& output, Cowboy& cowboy)
    {
        output << cowboy.print();
        return output;
    };

};


#endif