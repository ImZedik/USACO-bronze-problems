#include <iostream>
#include <vector>

using namespace std;

int guess() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> characteristics[n];
    for (int i = 0; i < n; i++) {
        string s_;
        int k;
        cin >> s_ >> k;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            characteristics[i].push_back(s);
        }
    }
    int maxSimilar = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) continue;
            int similar = 0;
            for (const string& s : characteristics[i]) {
                for (const string& s2 : characteristics[j]) {
                    if (s == s2) similar++;
                }
            }
            if (similar > maxSimilar) {
                maxSimilar = similar;
            }
        }
    }
    cout << maxSimilar + 1 << endl;
    return 0;
}