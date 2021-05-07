#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    
    int elevators[nbElevators+1];
    
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elevators[elevatorFloor] = elevatorPos;
    }
    elevators[exitFloor] = exitPos;
    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();

        if(((clonePos <= elevators[cloneFloor])&&(direction == "RIGHT"))
            ||((clonePos >= elevators[cloneFloor])&&(direction == "LEFT")))
        {
            cout << "WAIT" << endl; // action: WAIT or BLOCK
        }
        else
        {
            cout << "BLOCK" << endl; // action: WAIT or BLOCK
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        //cout << "WAIT" << endl; // action: WAIT or BLOCK
    }
}