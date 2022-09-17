#include <iostream>
#include <algorithm>

using namespace std;

int daisychains() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    int amount = 0;
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            int sum = 0;
//            cout << "Adding from " << start << " to " << end << endl;
            for (int i = start; i <= end; i++) {
                sum += arr[i];
            }
//            cout << "sum: " << sum << endl;
            if (sum % (end - start + 1) != 0) continue;
            int average = (sum / (end - start + 1));
//            cout << "average: " << average << endl;
//            cout << "start: " << start << " end: " << end << endl;
            for (int i = start; i <= end; i++) {
                if (arr[i] == average) {
                    amount++;
                    break;
                }
            }
        }
    }
    cout << amount << endl;
}