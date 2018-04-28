#include <iostream>
#include "Tortuga.h"

using namespace std;

#include <SDL.h>
//#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
    Tortuga myTortuga;
    DLinkedList<string> *curvaDeDragon = myTortuga.flechaDeSierpinski(4);
    cout << curvaDeDragon->printList() << endl;
    myTortuga.draw(curvaDeDragon);
    return 0;
}
