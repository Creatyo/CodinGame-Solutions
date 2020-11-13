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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    int Tl = T.length();
            
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        string answer;
        
        for(int l = 0; l < Tl; l++)
        {
            int value;
            if(((int)toupper(T[l])<65)||(((int)toupper(T[l])>91)))
            {
                value = 26;
            }
            else
            {
                value = (int)toupper(T[l]) - 65;
            }
            for (int j = L*value; j < L*(value+1); j++)
            {
                answer += ROW.at(j);
            }
        }
        cout << answer << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}