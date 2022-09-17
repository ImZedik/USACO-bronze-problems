#include <iostream>

using namespace std;

int d0[8] = {0,  0, 1, 1, 1, -1, -1, -1};
int d1[8] = {1, -1, -1, 1, 0, -1, 0, 1};

int moocryption() {
    // n^2 * 52 * 52 * 8 * 2 = o(43264n^2)
    // max n = 50; n^2 = 2500
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    char encrypted[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> encrypted[i][j];
        }
    }
    int maxCount = 0;
    for (char c = 'A'; c <= 'Z'; c++) { // 52
        if (c == 'M') continue;
        for (char c0 = 'A'; c0 <= 'Z'; c0++) { // 52
            if (c0 == 'O') continue;
            if (c == c0) continue;
            int count = 0;
            for (int x = 0; x < n; x++) { // n
                for (int y = 0; y < m; y++) { // m
                    if (encrypted[x][y] == c) {
                        for (int d = 0; d < 8; d++) { // 8
                            int x0 = x;
                            int y0 = y;
                            bool good = true;
                            for (int i = 0; i < 2; i++) { // 2
                                x0 += d0[d];
                                y0 += d1[d];
                                if (x0 > n-1 || x0 < 0 || y0 > m-1 || y0 < 0) {
                                    good = false;
                                    break;
                                }
                                if (encrypted[x0][y0] != c0) {
                                    good = false;
                                    break;
                                }
                            }
                            if (good) count++;
                        }
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
            }
        }
    }
    cout << maxCount << endl;
    return 0;
}
