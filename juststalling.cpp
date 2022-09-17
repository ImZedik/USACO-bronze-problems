#include <iostream>
#include <algorithm>

using namespace std;

int count(int o, const int *arr, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= o) {
            c++;
        }
    }
    return c;
}

int stalin() {
    int n;
    cin >> n;
    int heights[n];
    int limits[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> limits[i];
    }
    sort(heights, heights + n, greater<>());
    long long m = 1;
    for (int i = 0; i < n; i++) {
        int c = count(heights[i], limits, n);
        m *= (c - i);
    }
    cout << m << endl;
}