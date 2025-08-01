#include "the_100.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

//GLOBAL VARIABLES
//the player
player YOU;
//people
std::vector<people> people_vec;
std::vector<people*> club_members_index;
//city
town Town_1; //top
town Town_2; //left
town Town_3; //the center
town Town_4; //right
town Town_5; //bottom

//RNG
void initRandom(){
    std::srand(std::time(0));
}

int getRandom_inRange(int min, int max){
    return (std::rand()%(max - min + 1)) + min;
}

//PLAYER
void initialize_player(){
    YOU.speed = getRandom_inRange(24, 34);
    YOU.stamina = 100;
    YOU.money = 10;
    YOU.luck = getRandom_inRange(0, 100);
}

//PEOPLE
void initialize_people(){
    for(int i = 0; i<1000; i++){
        people p = {getRandom_inRange(10, 100), true, false};
        people_vec.push_back(p);
    }
}

//MEMBERS
void initialize_members(){
    int counter = 100; //tmp
    do{
        int index = getRandom_inRange(0, 999);
        people* ptr = &people_vec[index];
        if(std::find(club_members_index.begin(), club_members_index.end(), ptr) == club_members_index.end()){
            club_members_index.push_back(ptr);
            ptr->member = true;
            counter--;
        }
    }while(counter > 0);
}

//TOWNS
void initialize_towns(){
    for(int i = 0; i<200; i++){
        //residentes is a pointer vector, so it needs addresses
        Town_1.residentes.push_back(&people_vec[i]);
        Town_2.residentes.push_back(&people_vec[i+(200)]);
        Town_3.residentes.push_back(&people_vec[i+(200*2)]);
        Town_4.residentes.push_back(&people_vec[i+(200*3)]);
        Town_5.residentes.push_back(&people_vec[i+(200*4)]);
    }
}

void initialize_all(){
    initRandom();
    initialize_player();
    initialize_people();
    initialize_members();
    initialize_towns();
}
