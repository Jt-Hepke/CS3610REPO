#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cout << "Enter numbers: " << endl;
    cin >> n;

    vector<double> x(n);
    double sum = 0;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        sum += x[i];

    }
    double mean = sum / n;
    double sumSquared = 0;
    for (int i = 0; i < n; i++) {
        sumSquared += (x[i] - mean) * (x[i] - mean);
    }
    double f = sumSquared / n;
    double s = f;

    for (int i = 0; i < 20; i++){
        s = (s + f / s) / 2;
    }
    cout << mean << endl;
    cout << s << endl;

    return 0;
}