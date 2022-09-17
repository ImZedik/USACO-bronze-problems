#include <iostream>

using namespace std;

int cowroute() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;
    int minCost = 69420;
    for (int i = 0; i < n; i++) {
        int c, cost;
        cin >> cost >> c;
        bool v = false;
        bool good = false;
        for (int j = 0; j < c; j++) {
            int input;
            cin >> input;
            if (!good) {
                if (!v) {
                    if (input == a) {
                        v = true;
                    }
                } else {
                    if (input == b) {
                        good = true;
                    }
                }
            }
        }
        if (good) {
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }
    if (minCost == 69420) {
        cout << -1 << endl;
        return 0;
    }
    cout << minCost << endl;
    return 0;
}