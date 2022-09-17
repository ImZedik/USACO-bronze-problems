#include <iostream>

using namespace std;

int countingliars() {
    int n;
    cin >> n;
    bool type[n]; // 0 for less, 1 for greater
    int num[n];
    for (int i = 0; i < n; i++) {
        char c;
        int input;
        cin >> c;
        cin >> input;
        type[i] = c == 'G';
        num[i] = input;
    }
    int minliars = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        // position of bessie is at num[i]
        int liars = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (type[j]) { // greater
                if (num[j] > num[i]) {
                    liars++;
                }
            } else { // less
                if (num[j] < num[i]) {
                    liars++;
                }
            }
        }
        if (liars < minliars) {
            minliars = liars;
        }
    }
    cout << minliars << endl;
    return 0;
}