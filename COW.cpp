#include <iostream>

using namespace std;

int cow() {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    int n;
    cin >> n;
    char cow[n];
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }

    long long C = 0;
    long long O = 0;
    long long W = 0;

    for (char c : cow) {
        if (c == 'C') {
            C++;
        } else if (c == 'O') {
            O += C;
        } else if (c == 'W') {
            W += O;
        }
    }

    cout << W << endl;
}