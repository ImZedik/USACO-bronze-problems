#include <iostream>

using namespace std;


int square() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int minX = 11;
    int maxX = -1;
    int minY = 11;
    int maxY = -1;

    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        if (x < minX) {
            minX = x;
        }
        if (x > maxX) {
            maxX = x;
        }
        if (y < minY) {
            minY = y;
        }
        if (y > maxY) {
            maxY = y;
        }
    }
    int diffX = maxX - minX;
    int diffY = maxY - minY;
    if (diffX > diffY) {
        cout << diffX * diffX << endl;
    } else {
        cout << diffY * diffY << endl;
    }
    return 0;
}