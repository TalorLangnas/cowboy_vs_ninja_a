#include <stdbool.h>
#include <string>
#include <iostream>
#include <stdexcept>
# include <typeinfo>
#include <chrono>
#include "doctest.h"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Point")
{   
    // check distance method:
    Point point_1 = Point(1,1);
    Point point_2 = Point(-7.2,10);
    double dist_12 = point_1.distance(point_2);
    double dist_21 = point_2.distance(point_1);
    double dist_11 = point_1.distance(point_1);
    CHECK(dist_12 == dist_21);
    CHECK(dist_11 == 0);

    // Check moveTowards:
    Point point_3 = Point(-10,0);
    Point point_4 = Point(-9,0);
    double dist_34 = point_3.distance(point_4);
    // Point result = moveTowards(point_3, point_4, dist_34);
    // CHECK(result == point_4);

    // check print:
    string str = point_3.print();
    string ans = "(-10,0)";
    CHECK(str == ans);
};

TEST_CASE("Character")
{
    Character character1 = Character();
    Character character2 = Character();
    bool ans1 = character1.isAlive();
    bool ans2 = character2.isAlive();
    CHECK(ans2 == ans1);

    // check distance
    CHECK(character1.distance(character2) == 0);
    
    Point loc1 = character1.getLocation();
    Point loc2 = character2.getLocation();
    CHECK(loc1 == loc2);

    // Check print:
    string name = character1.getName();
    string location = character1.getLocation().print();
    CHECK(name == "C");
    CHECK(location == "(1,1)");

    // Check virtual methods:
    YoungNinja young_ninja = YoungNinja();
    Cowboy cowboy1 = Cowboy();
    TrainedNinja trained_ninja = TrainedNinja();
    OldNinja old_ninja = OldNinja();   
}

TEST_CASE("Check Ninja subclasses")
{
     // Check virtual methods:
    Ninja young_ninja = YoungNinja();
    Character cowboy1 = Cowboy();
    Ninja trained_ninja = TrainedNinja();
    Ninja old_ninja = OldNinja();
    Character *enemy = new Character(1000,1000);

    Point location1 = young_ninja.getLocation();
    young_ninja.move(enemy);
    Point location2 = young_ninja.getLocation();
    CHECK(location1.distance(location2) == 14);
    
    location1 = trained_ninja.getLocation();
    trained_ninja.move(enemy);
    location2 = trained_ninja.getLocation();
    CHECK(location1.distance(location2) == 12);

    location1 = old_ninja.getLocation();
    old_ninja.move(enemy);
    location2 = old_ninja.getLocation();
    CHECK(location1.distance(location2) == 8);

}    

TEST_CASE("shoot method")
{
    Cowboy cowboy = Cowboy();
    Ninja *young_ninja = new YoungNinja();
    Ninja *old_ninja = new OldNinja();
    int hp_before = young_ninja->get_health_point();
    cowboy.shoot(young_ninja);
    int hp_after = young_ninja->get_health_point();
    CHECK(hp_before == hp_after + 10);
    
    for (size_t i = 0; i < 6; i++)
    {
        cowboy.shoot(young_ninja);
    }
    CHECK(cowboy.get_ammo() == 0);
    CHECK_FALSE(cowboy.hasboolets());

    // Check shoot when ammo is == 0
    int current_hp = old_ninja->get_health_point();
    cowboy.shoot(old_ninja);
    CHECK(current_hp == old_ninja->get_health_point()); 
    // Check reload method:
    cowboy.reload();
    CHECK(cowboy.get_ammo() == 6);    
}
TEST_CASE("check slash()")
{
    Ninja *young_ninja = new YoungNinja();
    Cowboy *moshe = new Cowboy();
    int hp_mosh_before = moshe->get_health_point();
    young_ninja->slash(moshe);
    int hp_mosh = moshe->get_health_point();
    CHECK(hp_mosh_before == hp_mosh + 40);
}
TEST_CASE("Team")
{
    Ninja *young_ninja = new YoungNinja();
    Ninja *old_ninja = new OldNinja();
    Cowboy *moshe = new Cowboy();
    Team team1 = Team(young_ninja);
    Team team2 = Team(old_ninja);

    CHECK(team1.stillAlive() == 1);
}
TEST_CASE("add when team is full")
{
    Ninja *young_ninja = new YoungNinja();    
    Cowboy *moshe1 = new Cowboy();
    Team team1 = Team(young_ninja);
    for (size_t i = 0; i < 10; i++)
    {
        team1.add(new OldNinja());
    }
    CHECK_THROWS(team1.add(moshe1)); 
}

TEST_CASE("Attack when all the other team is dead")
{
    Ninja *young_ninja = new YoungNinja();    
    Cowboy *moshe1 = new Cowboy();
    Team team1 = Team(young_ninja);
    Team team2 = Team(moshe1);
    int dur = 3;
    auto startTime = std::chrono::steady_clock::now();
    bool flag = true;
    while(true)
    {
        team1.attack(&team2);
        auto currentTime = chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsedTime >= dur) // if enter its mean that attack didnt stop.
        {   
            flag = false;
            break; // Exit the loop after 5 seconds
        }
    }
    
    CHECK(flag == true);
}

TEST_CASE("Creats empty team")
{
    Character *character;
    Team team = Team(character);
    Character leader = team.get_team_leader(); 
    int size = team.get_size();
    CHECK(size == 0);
}