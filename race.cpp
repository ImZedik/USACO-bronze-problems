#include <iostream>

using namespace std;

int solve(int dist, int minspeed) {
    int speedup = 0;
    int slowdown = 0;
    int time = 0;
    for(int speed = 1;; speed++) {
        speedup += speed;
        time++;
        if(speedup + slowdown >= dist) return time;
        if(speed >= minspeed) {
            slowdown += speed;
            time++;
            if(speedup + slowdown >= dist) return time;
        }
    }
}


int race() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cout << solve(k, input) << endl;
    }
    return 0;
}