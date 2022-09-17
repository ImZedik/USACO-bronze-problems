#include <iostream>
#include <cmath>

using namespace std;

int getIndex(const char *arr, char query) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] == query) {
            return i;
        }
    }
    return -1;
}

int cowphabet() {
    char a[26];
    for (char & i : a) {
        cin >> i;
    }
    string s;
    cin >> s;
    int letters = 0;
    char current = 0;
    for (char c : s) {
        if (current != 0 && getIndex(a, c) <= getIndex(a, current)) {
            letters += 26 - (getIndex(a, current) - getIndex(a, c));
        } else {
            letters += getIndex(a, c) - getIndex(a, current);
        }
        current = c;
    }
    cout << ceil(letters / 26.0) << endl;
    return 0;
}