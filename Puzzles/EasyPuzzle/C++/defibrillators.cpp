#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    double U_LON;
    vector<double> lon_d;
    double U_LAT;
    vector<double> lat_d;

    int coma;
    int it;
    vector<string> Name;

    double x, y;
    vector<double> d;

    string DestName;
    double min = 10000;
    int id = 0;
    
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();

    //cerr << LON << " " << LAT << endl;
    coma = LON.find(",");
    LON[coma] = '.';
    coma = LAT.find(",");
    LAT[coma] = '.';
    U_LON = stod(LON) * M_PI / 180;
    U_LAT = stod(LAT) * M_PI / 180;
    //cerr << U_LON << " " << U_LAT << endl;

    int N;
    cin >> N; cin.ignore();

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);

        //Erase first number
        it = DEFIB.find(";");
        DEFIB.erase(0,it+1);
        //Extraction and erase name location
        it = DEFIB.find(";");
        Name.push_back(DEFIB.substr(0,it));
        DEFIB.erase(0,it+1);
        //Erase adress
        it = DEFIB.find(";");
        DEFIB.erase(0,it+1);
        it = DEFIB.find(";");
        DEFIB.erase(0,it+1);
        //Extraction longitude and erase it
        it = DEFIB.find(";");
        coma = DEFIB.find(",");
        DEFIB[coma] = '.';
        lon_d.push_back(stod(DEFIB.substr(0,it-1)) * M_PI / 180);
        DEFIB.erase(0,it+1);
        //Extraction latitude and erase it
        it = DEFIB.find(";");
        coma = DEFIB.find(",");
        DEFIB[coma] = '.';
        lat_d.push_back(stod(DEFIB.substr(0,it-1)) * M_PI / 180);
        DEFIB.erase(0,it+1);
        //cerr << Name[i] << endl;

        //Calculate distance and search the nearess
        x = (lon_d[i] - U_LON)*cos((lon_d[i] + U_LON)/2);
        y = (lat_d[i] - U_LAT);
        d.push_back(sqrt(pow(x,2)+pow(y,2))*6371);
        //cerr << d[i] << endl;
        if(d[i] < min)
        {
            min = d[i];
            id = i;
        }
    }
    
    DestName = Name[id];

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << DestName << endl;
}