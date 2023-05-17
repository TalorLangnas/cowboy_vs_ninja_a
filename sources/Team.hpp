#ifndef TEAM_HPP
#define TEAM_HPP
#include "character.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
#include "oldNinja.hpp"
#include "point.hpp"
#include "trainedNinja.hpp"
#include "youngNinja.hpp"
using namespace std;
using namespace ariel;

class Team
{
    private:
    Character* characters_team;
    Character& team_leader;
    int serial_number; // range: [1,10], given for each team memmber when signed to the team.
    int total_members;

    public:
    // Constructors:
    
    Team(Character*);
    // copy:
    Team(const Team&);
    virtual ~Team();
// Move constructor (for tidy):
    Team(Team&&) noexcept;    

// Team Methods:
// Move assignment operator (for tidy):
    Team& operator=(Team&&)noexcept;

    // copy assignment operator
    Team &operator=(const Team &) noexcept;

    virtual void add(Character*); // recives pointer to Character and add it to the team.
    virtual void attack(Team*); // attacks other team, first attack the leader and the the closest 
                        // team member until one of the teams are died.
    int stillAlive(); // returns the number of alives team members.
    virtual void print();
    Character& get_team_leader();
    int get_size();

    // inner class for iterator//

    // class iterator
    // {

    // };

   
};


#endif