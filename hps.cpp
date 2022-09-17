#include <iostream>

using namespace std;

int hps() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; cin >> n;
    int rounds[n][2];
    for (int i = 0; i < n; i++) {
        cin >> rounds[i][0] >> rounds[i][1];
    }
    int wins1 = 0;
    int wins2 = 0;
    for (int i = 0; i < n; i++) {
        if ((rounds[i][0] == 1 && rounds[i][1] == 2) ||
            (rounds[i][0] == 2 && rounds[i][1] == 3) ||
            (rounds[i][0] == 3 && rounds[i][1] == 1)) {
            wins1++;
        }
        if ((rounds[i][0] == 1 && rounds[i][1] == 3) ||
            (rounds[i][0] == 3 && rounds[i][1] == 2) ||
            (rounds[i][0] == 2 && rounds[i][1] == 1)) {
            wins2++;
        }
    }
    cout << max(wins1, wins2) << endl;
}