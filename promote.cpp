#include <iostream>

using namespace std;

int promote() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int pB, pA, gB, gA, sB, sA, bB, bA;
    cin >> bB >> bA >> sB >> sA >> gB >> gA >> pB >> pA;
    cout << (gA + pA + sA) - (gB + pB + sB) << endl;
    cout << (gA + pA) - (gB + pB) << endl;
    cout << pA - pB << endl;
    return 0;
}