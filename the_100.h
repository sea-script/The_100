// the 100 header file
#ifndef the_100
#define the_100

#include <vector>

struct people{
    int money;
    bool alive;
    bool member;
};

struct town{
    std::vector<people*> residents;
    //deaths
};

struct player{ //the player type
    int speed;
    int stamina;
    int money;
    int luck;
    town* current_town;
    //weapon;
};

extern player YOU; //the player itself

extern std::vector<people> people_vec;
extern std::vector<people*> club_members_index;

//each town points to 200 people
extern town Town_0; //top
extern town Town_1; //left
extern town Town_2; //the center
extern town Town_3; //right
extern town Town_4; //bottom
extern town* locations[5];

//FUNCTIONS

void initRandom(); //for random numbers
void initialize_player();
void initialize_people();
void initialize_members();
void initialize_towns();
void initialize_all(); //to save space

//printing func
void print_town_info();
void travel();

#endif



