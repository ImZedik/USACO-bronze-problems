#include <iostream>

using namespace std;

int breedflip() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;
    bool old[n];
    for (int i = 0; i < n; i++) {
        char input;
        cin >> input;
        old[i] = input == 'G';
    }
    bool expected[n];
    for (int i = 0; i < n; i++) {
        char input;
        cin >> input;
        expected[i] = input == 'G';
    }
    int count = 0;
    bool lastMismatched = false;
    for (int i = 0; i < n; i++) {
        if (old[i] == expected[i]) {
            lastMismatched = false;
        }
        if (lastMismatched) {
            continue;
        }
        if (old[i] != expected[i]) {
            count++;
            lastMismatched = true;
        }
    }
    cout << count << endl;
    return 0;
}
