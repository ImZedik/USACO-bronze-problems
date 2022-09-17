/*
 * LMAO this is angry birds ripoff (angry cows)
 */

#include <iostream>
#include <vector>

using namespace std;

int haybalecount = 0;
vector<int> visitedHayBales;

void explodeHayBale(const int *haybales, int hayBale, int power, int n) {
    // 8 5* 6* 13 3* 4*

    haybalecount++;
    vector<int> next;
    for (int i = 0; i < n; i++) {
        bool visited = false;
        for (int j : visitedHayBales) {
            if (j == haybales[i]) {
                visited = true;
                break;
            }
        }
        if (!visited) {
            if (abs(haybales[i] - hayBale) <= power) {
                visitedHayBales.push_back(haybales[i]);
                next.push_back(haybales[i]);
            }
        }
    }
    for (int i : next) {
        explodeHayBale(haybales, i, power + 1, n);
    }
}

int angry() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n;
    cin >> n;

    int haybales[n];

    for (int i = 0; i < n; i++) {
        cin >> haybales[i];
    }

    int maxHayBaleCount = 0;
    for (int i = 0; i < n; i++) {
        haybalecount = 0;
        visitedHayBales.clear();
        visitedHayBales.push_back(haybales[i]);
        explodeHayBale(haybales, haybales[i], 1, n);
        if (haybalecount > maxHayBaleCount) {
            maxHayBaleCount = haybalecount;
        }
    }
    cout << maxHayBaleCount << endl;
    return 0;
}
