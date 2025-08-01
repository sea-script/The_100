// the 100 header file
#ifndef the_100
#define the_100

#include <vector>

struct people{
    int money;
    bool alive;
    bool member;
};

struct player{ //the player type
    int speed;
    int stamina;
    int money;
    int luck;
    //weapon;
};

struct town{
    std::vector<people*> residentes;
};

extern player YOU; //the player itself

extern std::vector<people> people_vec;
extern std::vector<people*> club_members_index;

//each town points to 200 people
extern town Town_1; //top
extern town Town_2; //left
extern town Town_3; //the center
extern town Town_4; //right
extern town Town_5; //bottom

//FUNCTIONS

void initRandom(); //for random numbers
void initialize_player();
void initialize_people();
void initialize_members();
void initialize_towns();
void initialize_all(); //to save space

#endif
