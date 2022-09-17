#include <iostream>

using namespace std;

int index(int *arr, int query, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == query) {
            return i;
        }
    }
    return -1;
}

int gymnastics() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    int performance[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> performance[i][j];
        }
    }
    int amount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            bool good = true;
            for (int l = 0; l < k; l++) {
                if (index(performance[l], i + 1, n) <= index(performance[l], j + 1, n)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                amount++;
            }

        }
    }
    cout << amount << endl;
    return 0;
}