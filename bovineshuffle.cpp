#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int shuffle() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    int shuffle[n];
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> shuffle[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int arr[n];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = a[j];
        }
        for (int j = 0; j < n; j++) {
            // a[shuffle[j] - 1] = arr[j];
            a[j] = arr[shuffle[j] - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}