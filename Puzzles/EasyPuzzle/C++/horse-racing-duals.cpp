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
    int N;
    cin >> N; cin.ignore();
    vector<int> H;
    H.reserve(N);
    H.assign(N,0);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        H[i] = Pi;
    }
    
    sort(H.begin(), H.end());

    int diff = 10000000;
    for (int i = 0; i < N-1; i++) {
        if((H[i+1] - H[i]) < diff)
        {
            diff = H[i+1] - H[i];
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << diff << endl;
}