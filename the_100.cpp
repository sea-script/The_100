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
    for(int i = 0; i<sizeof(locations)/sizeof(locations[0]); i++){
        locations[i]->deaths = 0;
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

int period_per_speed(int speed, int distance){ //might nit need it
    //1000 * 60 -> 1min
    return ((float)distance/speed) * 60 * 1000;
}

bool correct_town_choice(std::string player_choice){
    if(player_choice == "0" || player_choice == "1" || player_choice == "2" || player_choice == "3" || player_choice == "4"){
        return true;
    }else{
        return false;
    }
}

int town_to_num(town* current_town){
    if (current_town == &Town_0){
        return 0;
    }else if(current_town == &Town_1){
        return 1;
    }else if(current_town == &Town_2){
        return 2;
    }else if(current_town == &Town_3){
        return 3;
    }else if(current_town == &Town_4){
        return 4;
    }
}

//ACTIONS
void travel(int speed){ //takes either the car's speed, or your running speed
    const int DIST_ADJACENT = 60;   // km
    const int MS_PER_SEC    = 1000; // ms in a second
    const int MINUTES_TO_SECONDS = 60;
    cout << "Which town you want to go to? (the distance between 2 adjacent towns is 60km)\n";
    cout << "+--------------------------------------------+\n";
    cout << "|               North town(0)                |\n";
    cout << "|                     |                      |\n";
    cout << "|West town(1)---Center town(2)---East town(3)|\n";
    cout << "|                     |                      |\n";
    cout << "|               South town(4)                |\n";
    cout << "+--------------------------------------------+\n";

    //where you're at
    cout << "You are at: " << which_town(YOU.current_town) << ".\n";
    int player_choice;
    cout << "Enter the number of the town: \n";
    do{
        cout << ">> ";
        std::cin >> player_choice;
    }while(player_choice>4 || player_choice<0);

    //distance calculation
    int distance;
    if(YOU.current_town == &Town_2){ //if you are at the center, the max distance is 60, and min is 0
        if(player_choice == 2){
            distance = 0;
        }else{
            distance = DIST_ADJACENT; //60 km
        }
    }else{
        if(player_choice == 2){ //if you are not, the max is 120 and min is 0 again
            distance = DIST_ADJACENT;
        }else if(player_choice == town_to_num(YOU.current_town)){
            distance = 0;
        }else{ //other town than yours
            distance = DIST_ADJACENT*2; //120 km :o
        }
    }

    cout << "Traveling to Town (" << player_choice << ")\n";

    cout << "Time to arrive: ";

    //calculating the time
    int time = 0;
    if(player_choice == town_to_num(YOU.current_town)){
        time = 0;
    }else{
        time = (float)((float)distance/(float)speed) * MINUTES_TO_SECONDS * MS_PER_SEC; //every second is 1000 + mins -> secs
    }

    cout << time/MS_PER_SEC << " secs\n";

    //waiting process
    while(time > 0){
        _sleep(MS_PER_SEC);
        time -= MS_PER_SEC;
        cout << time/MS_PER_SEC << " sec\n";
    }

    //done!
    YOU.current_town = locations[player_choice];
    cout << "You are now at " << which_town(YOU.current_town) << " \n";
}

void encounter(){
    int cop_chance = (YOU.current_town->deaths/2); //every 2 kills increases the chance by 1%
    if(cop_chance == 0){
        cop_chance = 1;
    }
    int person_num = getRandom_inRange(0,YOU.current_town->residents.size()-1); // a random civilian

    //if is not in the club
    if(YOU.current_town->residents[person_num]->member == true){
        cout << "Not in the club. \n";
        //if a cop or not
        if(getRandom_inRange(cop_chance, 100) <= cop_chance){ //if the number is less or equal to the chance, then it's a cop (luck doesn't affect this chance)
            cout << "is a cop. \n";
        }else{
            cout << "Not a cop. \n";
        }
    }else{//if is in the club
        cout << "In the club! " << person_num << "\n";
    }
}

void encounter_civilian(){

}

void encounter_cop(){

}

void encounter_memeber(){

}
