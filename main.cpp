#include <iostream>
#include "the_100.h"

//i think 1000 -> 1sec
using std::cout;
int main()
{
    initialize_all();
    cout << "your stats: \n";
    cout << "speed: " << YOU.speed << "\n";
    cout << "stamina: " << YOU.stamina << "\n";
    cout << "money: " << YOU.money << "\n";
    cout << "luck: " << YOU.luck << "\n";

    cout << "all club memebers: \n";
    for(int i = 0; i<club_members_index.size(); i++){
        cout << "memeber " << i+1 << " money: " << club_members_index[i]->money << " is memebre? : " << club_members_index[i]->member << "\n";
    }

    //count the memebers in TOWN1 _________________________________________________________
    cout << "number of memebers in town 1: ";
    int counter = 0;
    for(int i = 0; i<Town_1.residentes.size(); i++){
        if(Town_1.residentes[i]->member == true){
            counter++;
        }
    }
    cout << counter << "\n";
    // _______________________________________________________________________________________
    cout << "number of memebers in town 2: ";
    counter = 0;
    for(int i = 0; i<Town_2.residentes.size(); i++){
        if(Town_2.residentes[i]->member == true){
            counter++;
        }
    }
    cout << counter << "\n";
    cout << "number of memebers in town 3: ";
    counter = 0;
    for(int i = 0; i<Town_3.residentes.size(); i++){
        if(Town_3.residentes[i]->member == true){
            counter++;
        }
    }
    cout << counter << "\n";
    cout << "number of memebers in town 4: ";
    counter = 0;
    for(int i = 0; i<Town_4.residentes.size(); i++){
        if(Town_4.residentes[i]->member == true){
            counter++;
        }
    }
    cout << counter << "\n";
    cout << "number of memebers in town 5: ";
    counter = 0;
    for(int i = 0; i<Town_5.residentes.size(); i++){
        if(Town_5.residentes[i]->member == true){
            counter++;
        }
    }
    cout << counter << "\n";
    return 0;
}
