#include <iostream>

using namespace std;

int cowtip() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    bool tipped[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char input;
            cin >> input;
            tipped[i][j] = input == '1';
        }
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (tipped[i][j]) {
                count++;
                for (int x = 0; x <= i; x++)
                    for (int y = 0; y <= j; y++)
                        tipped[x][y] = !tipped[x][y];
            }
        }
    }
    cout << count << endl;
    return 0;
}
