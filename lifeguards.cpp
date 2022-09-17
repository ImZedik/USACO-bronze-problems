#include <iostream>

using namespace std;

int lifeguards() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> lifeguards[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lifeguards[i].first = x;
        lifeguards[i].second = y;
    }

    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        bool covered[1002] = {false};
        int time = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = lifeguards[j].first; k < lifeguards[j].second; k++) {
                covered[k] = true;
            }
        }
        for (bool j : covered) {
            if (j) time++;
        }
        if (time > maxTime) {
            maxTime = time;
        }
    }
    cout << maxTime << endl;
}
