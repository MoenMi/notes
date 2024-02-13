#include <iostream>
using namespace std;

int main() {
    int n;
    int x[n][n];
    bool allZero;
    for (int i = 0; i <= n; i++) {
        allZero = true;
        for (int j = 0; j <= n; j++) {
            if (x[i][j] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << "First all-zero row is: " << i << endl;
            break;
        }
    }
    return 0;
}