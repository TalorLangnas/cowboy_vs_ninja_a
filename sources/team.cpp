# include "Team.hpp"



Team::Team(Character *character): team_leader(*character)
{

};
// Copy:
Team::Team(const Team& team): team_leader(team.team_leader)
{

};
Team::~Team()
{

};
// Move constructor (for tidy):
Team::Team(Team&& other)noexcept:team_leader(other.team_leader) 
{

};
Team& Team::operator=(const Team& other) noexcept
{
    *this = other;
    return *this;
};    

// Move assignment operator (for tidy):
Team& Team::operator=(Team&& other)noexcept
{   
    
    return *this;
};

// Team Methods:
void Team::add(Character* character) // recives pointer to Character and add it to the team.
{

}; 
void Team::attack(Team* other)  // attacks other team, first attack the leader and the the closest 
                    // team member until one of the teams are died.
{
    
}; 
int Team::stillAlive()    // returns the number of alives team members.
{
    return 1;
}; 
void Team::print()
{

};
Character& Team::get_team_leader()
{
    return team_leader;    
};
int Team::get_size()
{
    return 1;
};
