#include <iostream>

using namespace std;

int main() {
    int inputNum;
    cin >> inputNum;

    for (int i = 0; i < inputNum; i++){
        //read input
        int cityNum;
        cin >> cityNum;

        string city[100];
        for (int j = 0; j < cityNum; j++){
            cin >> city[i];
        }

        int distance[100][100];
        for (int j = 0; j < cityNum; j++){
            for (int t = 0; t < j; t++){
                cin >> distance[i][j];
            }
        }

    }
}