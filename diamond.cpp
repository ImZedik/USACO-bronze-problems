#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int diamond() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        int amount = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] >= arr[i] && arr[j] <= arr[i] + k) {
                amount++;
            }
        }
        if (amount > max) {
            max = amount;
        }
    }
    cout << max << endl;
}