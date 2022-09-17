#include <iostream>
#include <cstdio>

using namespace std;

int cbarn() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long mindistance = 1e15;
    for (int start = 0; start < n; start++) {
        long distance = 0;
        for (int i = 0; i < n; i++) {
            // Calculate the distance between 'i' and start.
            int end = i;
            if (start > end) {
                end += n;
            }
            long d = end - start;

            // Add the distance to the total.
            distance += d * arr[i];

            if (distance < 0) {
                cerr << "bruh " << distance << endl;
                return 0;
            }
        }
        if (distance < mindistance) {
            mindistance = distance;
        }
    }
    cout << mindistance << endl;
}