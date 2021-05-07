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
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    int Rooms[H][W];
    for (int i = 0; i < H; i++) {
        string LINE;
        getline(cin, LINE); // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        //cerr << "LINE : " << LINE << endl;
        string delimiter = " ";
        size_t pos = 0;
        string token;
        int j = 0;
        while ((pos = LINE.find(delimiter)) != string::npos) {
            token = LINE.substr(0, pos);
            Rooms[i][j++] = stoi(token);
            LINE.erase(0, pos + delimiter.length());
        }
        //cerr << "LINE : " << LINE << endl;
        Rooms[i][j++] = stoi(LINE);
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        int roomType = Rooms[YI][XI];
        cerr << "roomType = " << roomType << endl;
        
        int XNext = XI;
        int YNext = YI;
        //int roomType = 1;
        switch(roomType)
        {
            case 0:
                break;
            case 1:
                if(POS == "TOP")
                {
                    YNext++;
                }
                else if(POS == "LEFT")
                {
                    YNext++;
                }
                else if(POS == "RIGHT")
                {
                    YNext++;
                }
                break;
            case 2:
                if(POS == "LEFT")
                {
                    XNext++;
                }
                else if(POS == "RIGHT")
                {
                    XNext--;
                }
                break;
            case 3:
                if(POS == "TOP")
                {
                    YNext++;
                }
                break;
            case 4:
                if(POS == "TOP")
                {
                    XNext--;
                }
                else if(POS == "RIGHT")
                {
                    YNext++;
                }
                break;
            case 5:
                if(POS == "TOP")
                {
                    XNext++;
                }
                else if(POS == "LEFT")
                {
                    YNext++;
                }
                break;
            case 6:
                if(POS == "LEFT")
                {
                    XNext++;
                }
                else if(POS == "RIGHT")
                {
                    XNext--;
                }
                break;
            case 7:
                if(POS == "TOP")
                {
                    YNext++;
                }
                else if(POS == "RIGHT")
                {
                    YNext++;
                }
                break;
            case 8:
                if(POS == "LEFT")
                {
                    YNext++;
                }
                else if(POS == "RIGHT")
                {
                    YNext++;
                }
                break;
            case 9:
                if(POS == "TOP")
                {
                    YNext++;
                }
                else if(POS == "LEFT")
                {
                    YNext++;
                }
                break;
            case 10:
                if(POS == "TOP")
                {
                    XNext--;
                }
                break;
            case 11:
                if(POS == "TOP")
                {
                    XNext++;
                }
                break;
            case 12:
                if(POS == "RIGHT")
                {
                    YNext++;
                }
                break;
            case 13:
                if(POS == "LEFT")
                {
                    YNext++;
                }
                break;
            default:
                break;
        }

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        cout << XNext << " " << YNext << endl;
    }
}