#include <iostream>
#include <cstdio>

using namespace std;

int wordprocessor() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    unsigned long currentWidth = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (currentWidth + s.length() > k) {
            cout << endl;
            currentWidth = 0;
        } else if (i != 0) {
            cout << " ";
        }
        cout << s;
        currentWidth += s.length();
    }
}