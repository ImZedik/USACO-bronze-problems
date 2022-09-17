#include <iostream>

using namespace std;

int cownomics() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    char spotty[m][n];
    char plain[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotty[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain[j][i];
        }
    }

//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < awehtygawe; j++) {
//            cout << spotty[i][j] << " ";
//        }
//        cout << endl;
//    }

    int amount = 0;
    for (int i = 0; i < m; i++) {
        bool good = true;
        for (char j: spotty[i]) {
            for (char k: plain[i]) {
                if (j == k) {
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }
        if (good) amount++;
    }
    cout << amount;
    return 0;
}