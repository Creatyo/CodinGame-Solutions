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
    int L;
    cin >> L; cin.ignore();
    int grid[N][N];
    int k = 0;
    
    for (int i = 0; i < N; i++) {
        string LINE;
        getline(cin, LINE);
        k = 0;
        for(int j = 0; j<N;j++){
            if(LINE[k] == 'C'){
                grid[i][j] = L;
            }else{
                grid[i][j] = 0;
            }
            k += 2;
        }
    }
    
    int max_surrounding_cell;
    
    for(int i = L - 1; i > 0; i--)
    {
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < N; y++)
            {
                
                max_surrounding_cell = 0;
                
                for(int x_step = -1; x_step <= 1; x_step++)
                {
                    for(int y_step = -1; y_step <= 1; y_step++)
                    {
                        if(0 <= x + x_step && x + x_step < N && 0 <= y + y_step && y + y_step < N)
                            {
                                max_surrounding_cell = max(max_surrounding_cell, grid[x + x_step][y + y_step]);
                            }
                        }
                    }
                    grid[x][y] = max(grid[x][y], max_surrounding_cell - 1);
            }
        }
    }
    
    int darkSpots = 0;
        
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (grid[x][y] == 0)
                {
                    darkSpots++;
                }
            }
        }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << darkSpots << endl;
}