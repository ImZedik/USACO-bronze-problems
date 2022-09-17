#include <iostream>
#include <vector>

using namespace std;

int factory() {
// 3
// 1 2
// 3 1
//
// stations: 1, 2, 3
// current: 2
// {1}
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > links;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        links.emplace_back(a, b);
    }

    while (true) {
        bool changed = false;
        for (pair<int, int> p: links) {
            for (pair<int, int> p2: links) {
                if (p.second == p2.first) {
                    bool exists = false;
                    for (pair<int, int> p3: links) {
                        if (p3.first == p.first && p3.second == p2.second) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        changed = true;
                        links.emplace_back(p.first, p2.second);
                    }
                }
                if (p2.second == p.first) {
                    bool exists = false;
                    for (pair<int, int> p3: links) {
                        if (p3.first == p2.first && p3.second == p.second) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        changed = true;
                        links.emplace_back(p2.first, p.second);
                    }
                }
            }
        }
        if (!changed) break;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> connected;
        for (pair<int, int> p : links) {
            if (p.second == i) {
                bool exists = false;
                for (int j : connected) {
                    if (j == p.first) {
                        exists = true;
                    }
                }
                if (!exists) {
                    connected.push_back(p.first);
                }
            }
        }
        bool good = true;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            bool g = false;
            for (int k : connected) {
                if (j == k) {
                    g = true;
                }
            }
            if (!g) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
