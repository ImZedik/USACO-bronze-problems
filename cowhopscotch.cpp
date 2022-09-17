#include <iostream>

using namespace std;

int hopscotch() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    bool field[a][b];
    int count[a][b];
    bool current = false; // false for blue, true for red (because red is better)
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            char c;
            cin >> c;
            count[i][j] = 0;
            if (i == 0 && j == 0) {
                current = c == 'R';
            }
            field[i][j] = c == 'R';
        }
    }

    count[0][0] = 1;

    while (true) {
        bool changed = false;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (i == 0 && j == 0) continue;
                if (field[i][j] == !current) {

                    int sum = 0;
                    for (int i0 = 0; i0 < i; i0++) {
                        for (int j0 = 0; j0 < j; j0++) {
                            if (field[i0][j0] == current) {
                                sum += count[i0][j0];
                            }
                        }
                    }
                    if (count[i][j] != sum) changed = true;
                    count[i][j] = sum;

                }
            }
        }
        if (!changed) break;
        current = !current;
    }

    // cool visualization
    /*
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (field[i][j]) {
                cout << "\033[1;31m" << count[i][j] << "\033[0m ";
            } else {
                cout << "\033[1;34m" << count[i][j] << "\033[0m ";
            }
        }
        cout << endl;
    }
     */
    cout << count[a-1][b-1] << endl;
    return 0;
}