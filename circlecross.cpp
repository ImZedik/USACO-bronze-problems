#include <iostream>

using namespace std;


pair<int, int> indexes(const char *arr, char c) {
    int count = 0;
    pair<int, int> pair;
    for (int i = 0; i < 52; i++) {
        if (count == 2) {
            break;
        }
        if (arr[i] == c) {
            if (count == 0) {
                pair.first = i;
            }
            if (count == 1) {
                pair.second = i;
            }
            count++;
        }
    }
    return pair;
}

int circlecross() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    char chars[52];
    for (char & i : chars) {
        cin >> i;
    }
    int count = 0;
    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = 'A'; c2 <= 'Z'; c2++) {
            if (c1 == c2) {
                continue;
            }
            if (indexes(chars, c1).first < indexes(chars, c2).first && indexes(chars, c2).first < indexes(chars, c1).second && indexes(chars, c1).second < indexes(chars, c2).second) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}