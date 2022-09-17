#include <iostream>

using namespace std;

bool cows[1001][1001];

int changeX[] {1, -1, 0, 0};
int changeY[] {0, 0, 1, -1};

bool updateComfortable(int x, int y) {
    if (cows[x][y] == 0) return false;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (changeX[i] + x >= 0 && changeY[i] + y >= 0 && changeX[i] + x < 1001 && changeY[i] + y < 1001) {
            if (cows[changeX[i] + x][changeY[i] + y]) {
                count++;
            }
        }
    }
    return count == 3;
}

int comfortablecows() {
    int n;
    cin >> n;
    int a, b;
    int comfortable = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (a + changeX[j] >= 0 && b + changeY[j] >= 0) {
                if (updateComfortable(a + changeX[j], b + changeY[j])) count++;
            }
        }

        int newCount = 0;
        cows[a][b] = true;

        for (int j = 0; j < 4; j++) {
            if (a + changeX[j] >= 0 && b + changeY[j] >= 0) {
                if (updateComfortable(a + changeX[j], b + changeY[j])) newCount++;
            }
        }
        if (updateComfortable(a, b)) newCount++;
        comfortable += newCount - count;

        cout << comfortable << endl;
    }
}