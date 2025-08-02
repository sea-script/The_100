#include <iostream>
#include "the_100.h"

//i think 1000 -> 1sec
using std::cout;

void intro(){
    cout << "...You got a message: \"Member 101, the game started.\", you take a moment to process what you've read...\n";
    cout << "You remember! :)\n";
}

int main()
{
    initialize_all();
    intro();
    cout << "your stats: \n";
    cout << "speed: " << YOU.speed << "\n";
    cout << "stamina: " << YOU.stamina << "\n";
    cout << "money: " << YOU.money << "\n";
    cout << "luck: " << YOU.luck << "\n";

    cout << "all club memebers: \n";
    for(int i = 0; i<club_members_index.size(); i++){
        cout << "memeber " << i+1 << " money: " << club_members_index[i]->money << " is memebre? : " << club_members_index[i]->member << "\n";
    }
    cout << "\n";
    print_town_info();
    travel();
    return 0;
}
