#include <iostream>

using namespace std;

int teleport() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int x, y, t1, t2;
    cin >> x >> y >> t1 >> t2;

    int minDistance = 1e9;
    // Case 1: Directly travel from x to y
    int distance1 = abs(x - y);
    if (distance1 < minDistance) {
        minDistance = distance1;
    }

    // Case 2: Travel from x to t1, teleport to t2 then travel to y
    int distance2 = abs(x - t1) + abs(t2 - y);
    if (distance2 < minDistance) {
        minDistance = distance2;
    }

    // Case 3: Travel from x to t2, teleport to t1 then travel to y
    int distance3 = abs(x - t2) + abs(t1 - y);
    if (distance3 < minDistance) {
        minDistance = distance3;
    }

    cout << minDistance << endl;

    return 0;
}