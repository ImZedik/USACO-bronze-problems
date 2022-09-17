#include <iostream>
#include <cstdio>

using namespace std;

int capacity[3];
int amount[3];

void pour(int a, int b) {
    amount[b] += amount[a];
    amount[a] = 0;
    if (amount[b] > capacity[b]) {
        int value = amount[b] - capacity[b];
        amount[b] = capacity[b];
        amount[a] = value;
    }
    // cout << "Pour " << a+1 << " -> " << b+1 << ": " << amount[0] << " " << amount[1] << " " << amount[2] << endl;
}

int mix() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i] >> amount[i];
    }
    for (int i = 0; i < 33; i++) {
        // 1 -> 2
        pour(0, 1);
        // 2 -> 3
        pour(1, 2);
        // 3 -> 1
        pour(2, 0);
    }
    pour(0, 1);
    cout << amount[0] << endl;
    cout << amount[1] << endl;
    cout << amount[2] << endl;
    return 0;
}