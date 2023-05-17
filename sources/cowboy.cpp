#include "cowboy.hpp"
using namespace std;

Cowboy::Cowboy()
{

};
Cowboy::Cowboy(double x, double y): Character(x, y)
{

};
Cowboy::Cowboy(Point point): Character(point)
{

};
Cowboy::Cowboy(string other, Point point): Character(other, point)
{

};
void Cowboy::shoot(Character* character)
{

};
bool Cowboy::hasboolets()
{
    return true;
};
void Cowboy::reload()
{
    
};
int Cowboy::get_ammo()
{
    return ammo;
};
string Cowboy::print()
{
    return "cowboy";
};