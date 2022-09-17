#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int blist() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    int times[n][2];
    int buckets[n];
    vector<int> events = {};
    for (int i = 0; i < n; i++) {
        cin >> times[i][0];
        cin >> times[i][1];
        cin >> buckets[i];
        events.push_back(times[i][0]);
        events.push_back(times[i][1]);
    }
    // std::sort(events.begin(), events.end());
    sort(events.begin(), events.begin() + events.size());
    int amount = 0;
    int maxamount = 0;
    for (int time: events) {
        for (int i = 0; i < n; i++) {
            if (times[i][0] == time) {
                // start
                amount += buckets[i];
                if (amount > maxamount) {
                    maxamount = amount;
                }
            }
            if (times[i][1] == time) {
                // end
                amount -= buckets[i];
            }
        }
    }
    cout << maxamount << endl;
    return 0;
}