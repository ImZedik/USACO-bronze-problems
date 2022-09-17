#include <iostream>
#include <algorithm>

using namespace std;

int pails() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;
    int maxAmount = 0;
    for (int i = 0; i <= m / y; i++) {
        int result = m - y * i;
        int xResult = result - (result % x);
        int amount = xResult + y * i;
        if (amount > maxAmount) {
            maxAmount = amount;
        }
    }
    cout << maxAmount << endl;
}