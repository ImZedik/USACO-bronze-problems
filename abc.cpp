#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int abc() {
    /*
     a+b = x
     b+c = y
     c+a = z
     a+b+c = (x + y + z) / 2

     a = (x + y + z) / 2 - y
     b = (x + y + z) / 2 - z
     c = (x + y + z) / 2 - x
     */

    // Case 1: a <= b <= c <= a+b <= c+a <= b+c <= a+b+c
    // Case 2: a <= b <= a+b <= c <= c+a <= b+c <= a+b+c

    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    // Case 1: a = arr[0], b = arr[1], c = arr[2]
    /*
     * arr[3] = a + b =  x
     * arr[4] = c + a =  z
     * arr[5] = b + c =  y
     * arr[6] = a + b + c
     */
    int r = (arr[3] + arr[4] + arr[5]) / 2;
    if (arr[0] == r - arr[5] && arr[1] == r - arr[4] && arr[2] == r - arr[3]) {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        return 0;
    }

    // Case 2: a = arr[0], b = arr[1], c = arr[3]
    /*
     * arr[2] = a + b =  x
     * arr[4] = c + a =  z
     * arr[5] = b + c =  y
     * arr[6] = a + b + c
     */
    r = (arr[2] + arr[4] + arr[5]) / 2;
    if (arr[0] == r - arr[5] && arr[1] == r - arr[4] && arr[3] == r - arr[2]) {
        cout << arr[0] << " " << arr[1] << " " << arr[3] << endl;
        return 0;
    }
    return -1;
}