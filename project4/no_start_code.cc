#include <iostream>

using namespace std;

int main() {
    int inputNum;
    cin >> inputNum;

    for (int u = 0; u < inputNum; u++){
        //read input
        int cityNum;
        cin >> cityNum;

        string city[100];
        for (int j = 0; j < cityNum; j++){
            cin >> city[j];
        }

        int distance[100][100];
        for (int j = 0; j < cityNum; j++){
            for (int t = 0; t < cityNum; t++){
                cin >> distance[j][t];
            }
        }

        int d[100]; 
        bool current[100];
        int prev[100];

        for (int j = 0; j < cityNum; j++){
            //intatilize everything
            d[j] = 99999;
            current[j] = false;
            prev[j] = -1;
        }
        d[0] = 0; // distance from itself is 0

        for (int j = 0; j < cityNum; j++) {
            int city = -1; //city at right now
            for(int t = 0; t < cityNum; t++){
                if(!current[t]) { // looking at non used citys
                    if (city == -1 || d[t] < d[city]){
                        city = t;
                    }
                }
            }

            // if no non used citys
            if (city == -1 || d[city] == 99999){
                break;
            }
            //mark city as used
            current[city] = true;

            for (int i = 0; i < cityNum; i++){
                // distance[city][i] means there is a path between the two
                if (distance[city][i] > 0 && !current[i]) {
                    int newDistance = d[city] + distance[city][i];
                    if(newDistance < d[i]) { //shorter path
                        d[i] = newDistance;
                        prev[i] = city; //save the last city
                    }
                }
            }
        }

        int path[100];
        int pathLength = 0;
        int currentpath = cityNum - 1; 

        while (currentpath != -1){
            path[pathLength] = currentpath;
                pathLength++;
                currentpath = prev[currentpath];

        }

        // The pathway is stored backwards so printing is reversed
        for (int i = pathLength - 1; i >= 0; i--){
            cout << city[path[i]];
            if(i != 0){
                cout << " "; // space between cities
            }
        }
        cout << " " << d[cityNum - 1] << endl;
    }
}