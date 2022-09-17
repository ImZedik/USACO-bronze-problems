#include <iostream>
#include <vector>

using namespace std;

int whereami() {
    // o(n^3)
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    char chars[n];
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    for (int K = 1; K <= n; K++) { // n
        vector<string> substrings;
        bool g = true;
        for (int start = 0; start <= n-K; start++) { // n
            int end = start + K;
            string s;
            for (int j = start; j < end; j++) {
                s.push_back(chars[j]);
            }
            bool good = true;
            for (const string& i : substrings) { // n
                if (i == s) {
                    good = false;
                }
            }
            if (!good) {
                g = false;
                break;
            }
            substrings.push_back(s);
        }
        if (g) {
            cout << K << endl;
//            for (const string& s : substrings) {
//                cout << s << " ";
//            }
            return 0;
        }
    }
    return 69;
}
