#include <iostream>

using namespace std;

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int billboard() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2; // lawnmower ad
    int x3, y3, x4, y4; // good ad
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int cornerCover = 0;
    if(covered(x1, y1, x3, y3, x4, y4)) cornerCover++;
    if(covered(x1, y2, x3, y3, x4, y4)) cornerCover++;
    if(covered(x2, y1, x3, y3, x4, y4)) cornerCover++;
    if(covered(x2, y2, x3, y3, x4, y4)) cornerCover++;

    if (cornerCover < 2) {
        cout << (x2-x1) * (y2 - y1) << endl;
    }
    else if (cornerCover == 4) {
        cout << 0 << endl;
    } else {
        int maxX = max(x1, x3);
        int minX = min(x2, x4);
        int maxY = max(y1, y3);
        int minY = min(y2, y4);
        cout << (x2 - x1) * (y2 - y1) - (maxX - minX) * (maxY - minY);
    }

    return 0;
}