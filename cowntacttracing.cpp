#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool cow_ends_infected[101];
int cowx[251], cowy[251];

bool is_consistent(int patient_zero, int k) {
    bool infected[101] = {false};
    int num_handshakes[101] = {0};
    infected[patient_zero] = true;
    for (int t = 0; t <= 250; t++) {
        int x = cowx[t], y = cowy[t];
        if (x>0) {
            if (infected[x]) num_handshakes[x]++;
            if (infected[y]) num_handshakes[y]++;
            if (num_handshakes[x] <= k && infected[x]) infected[y] = true;
            if (num_handshakes[y] <= k && infected[y]) infected[x] = true;
        }
    }
    for (int i=1; i<=n; i++)
        if (infected[i] != cow_ends_infected[i]) return false;
    return true;
}


int tracing() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int t;
    string s;
    cin >> n >> t >> s;
    for (int i = 1; i <= n; i++) {
        cow_ends_infected[i] = s[i-1] == '1';
    }

    for (int i = 0; i < t; i++) {
        int x;
        int y;
        int t_;
        cin >> t_ >> x >> y;
        cowx[t_] = x;
        cowy[t_] = y;
    }

    bool possible_i[101] = {false};
    bool possible_K[252] = {false};
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= 251; k++) {
            if (is_consistent(i, k)) {
                possible_i[i] = true;
                possible_K[k] = true;
            }
        }
    }
    int minK = 251, maxK = 0, patientZero = 0;
    for (int K = 0; K <= 251; K++) if (possible_K[K]) maxK = K;
    for (int K = 251; K >= 0; K--) if (possible_K[K]) minK = K;
    for (int i = 1; i <= n; i++) if (possible_i[i]) patientZero++;

    cout << patientZero << " ";
    cout << minK << " ";
    if (maxK == 251) {
        cout << "Infinity" << endl;
    } else {
        cout << maxK << endl;
    }

    return 0;
}