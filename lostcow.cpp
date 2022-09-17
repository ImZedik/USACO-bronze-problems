#include <iostream>
#include <cstdio>

using namespace std;

int lostcow() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    cin >> x >> y;
    int pos = x;
    int d = 0;
    int n = 1;
    while (true) {
        int target = x + n;
        if ((pos <= y && y <= target) || (target <= y && y <= pos)) {
            d += abs(y - pos);
            break;
        }
        int distance = abs(target - pos);
        d += distance;
        pos = target;
        n *= -2;
    }
    cout << d << endl;
    return 0;
}