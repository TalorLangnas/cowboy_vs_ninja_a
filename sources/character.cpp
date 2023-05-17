# include "character.hpp"
using namespace std;
using namespace ariel;


    // Constructors:
    Character::Character():location(0,0)
    {

    };
    Character::Character(double x, double y): location(x, y)
    {

    };
    Character::Character(Point point): location(point)
    {
        
    };
    Character::Character(string other, Point point): location(point)
    {

    };
    // copy constructor
    Character::Character(const Character& other) noexcept:location(other.location)
    {

    };
    // copy assignment operator
    Character& Character::operator=(const Character& other) noexcept
    {
        return *this;
    };
    // move constructor
    Character::Character(Character&& other) noexcept: location(other.location)
    {

    };
    // move assignment operator
    Character& Character::operator=(Character&& other) noexcept
    {
        return *this;
    };    

    // Destructor:
    Character::~Character()
    {

    };
    bool Character::isAlive()
    {
        return true;
    };
    double Character::distance(Character& character)
    {
        return 1.0;
    };
    void Character::hit(int )
    {

    };
    string Character::getName()
    {
        return "name";
    };
    Point& Character::getLocation()
    {
        return location;
    };
    void Character::print()
    {

    };
    int Character::get_health_point()
    { 
        return health_point;
    };