#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int acowdemia() {
/*
2 4
bob dean elsie mildred
elsie mildred dean bob

 map {dean: 0, elsie: 1, mildred: 2}

 1. elsie <= mildred < dean
 */
    int k, n;
    cin >> k >> n;
    unordered_map<string, int> indexes;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        indexes[s] = i;
    }
    char b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = '?';
        }
    }
    for (int i = 0; i < n; i++) {
        b[i][i] = 'B';
    }

    vector<pair<string, string> > comp; // pair.first is older than pair.second

    for (int i = 0; i < k; i++) {
        string e[n];
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            e[j] = s;
        }
        for (int l = 0; l < n - 1; l++) {
            if (e[l].compare(e[l + 1]) > 0) {
                // e[l+1], e[l+2] to e[n-1] are definitely older than e[l], e[l-1] to e[0]
                for (int m = 0; m <= l; m++) {
                    for (int o = l + 1; o < n; o++) {
                        comp.emplace_back(e[o], e[m]);
                    }
                }
            }
        }
    }

    for (const pair<string, string>& p : comp) {
        b[indexes[p.first]][indexes[p.second]] = '1';
        b[indexes[p.second]][indexes[p.first]] = '0';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
}