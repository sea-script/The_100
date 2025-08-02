#include "the_100.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
using std::cout;
//GLOBAL VARIABLES
//the player
player YOU;
//people
std::vector<people> people_vec;
std::vector<people*> club_members_index;
//locarions
town Town_0; //top
town Town_1; //left
town Town_2; //the center
town Town_3; //right
town Town_4; //bottom
town* locations[5] = {&Town_0, &Town_1, &Town_2, &Town_3, &Town_4};

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
    YOU.current_town = locations[2]; //you start at the center
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
        Town_0.residents.push_back(&people_vec[i]);
        Town_1.residents.push_back(&people_vec[i+(200)]);
        Town_2.residents.push_back(&people_vec[i+(200*2)]);
        Town_3.residents.push_back(&people_vec[i+(200*3)]);
        Town_4.residents.push_back(&people_vec[i+(200*4)]);
    }
}

//INIT
void initialize_all(){
    initRandom();
    initialize_player();
    initialize_people();
    initialize_members();
    initialize_towns();
}

std::string which_town(town* x){
    if(x == &Town_0){
        return "North town (0)";
    }else if(x == &Town_1){
        return "West town (1)";
    }else if(x == &Town_2){
        return "Center town (2)";
    }else if(x == &Town_3){
        return "East town (3)";
    }else if(x == &Town_4){
        return "South town (4)";
    }else{
        return "Error";
    }
}

void print_town_info(){
    int member_count = 0;
    for(int i = 0; i<YOU.current_town->residents.size(); i++){
        if(YOU.current_town->residents[i]->member == true){
            member_count++;
        }
    }
    cout << "You are at " << which_town(YOU.current_town) << ".\n";
    cout << "There are: " << YOU.current_town->residents.size() << " residents. \n";
    cout << "Amongst these residents exists " << member_count << " members. \n";

}

int period_per_speed(int speed, int distance){
    //1000 * 60 -> 1min
    return (distance/speed) * 60 * 1000;
}

void travel(){
    cout << "Which town you want to go to? (the distance between 2 adjacent towns is 60km)\n";
    cout << "+--------------------------------------------+\n";
    cout << "|               North town(0)                |\n";
    cout << "|                     |                      |\n";
    cout << "|West town(1)---Center town(2)---East town(3)|\n";
    cout << "|                     |                      |\n";
    cout << "|               South town(4)                |\n";
    cout << "+--------------------------------------------+\n";
    //options (choose) or (quit)
}
