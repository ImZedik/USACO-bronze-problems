#include <iostream>
#include <cstdio>

using namespace std;
char farm[500][500];

int clockwisefence() {
    int n;
    cin >> n;

    for (int asdf = 0; asdf < n; asdf++) {
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                farm[i][j] = '\u0000';
            }
        }
        int x = 150, y = 150;
        string s;
        cin >> s;
        int minX = 500;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            farm[x][y] = c;
            if (c == 'N') x--;
            if (c == 'S') x++;
            if (c == 'E') y++;
            if (c == 'W') y--;
            if (x < minX) minX = x;
        }
        bool cw = false;
        for (int i = 0; i < 500; i++) {
            char c = farm[minX][i];
            if (!(c == '\u0000' || c == 'S' || c == 'W')) {
                cout << "CW" << endl;
                cw = true;
                break;
            }
        }
        if (!cw) {
            cout << "CCW" << endl;
        }
    }
    return 0;
}