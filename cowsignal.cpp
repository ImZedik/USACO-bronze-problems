#include <iostream>
#include <cstdio>

using namespace std;

int cowsignal() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int x, y, a;
    cin >> x >> y >> a;
    char image[x][y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            char c;
            cin >> c;
            image[i][j] = c;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int n = 0; n < a; n++) {
            for (int j = 0; j < y; j++) {
                for (int m = 0; m < a; m++) {
                    cout << image[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}