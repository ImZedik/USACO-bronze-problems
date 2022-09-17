#include <iostream>

using namespace std;

int variableIndex(char c) {
    char variables[] = {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
    for (int i = 0; i < 7; i++) {
        if (variables[i] == c) {
            return i;
        }
    }
    return -1;
}

int geteven() {
    freopen("geteven.in", "r", stdin);
    freopen("geteven.out", "w", stdout);
    int n;
    cin >> n;
    int evenodd[7][2];

    for (auto & i : evenodd) {
        for (int & j : i) {
            j = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        char c;
        int input;
        cin >> c >> input;
        int index = variableIndex(c);
        evenodd[index][abs(input) % 2]++;
    }

    int sum = 0;
    for (int b = 0; b < 2; b++) {
        for (int e = 0; e < 2; e++) {
            for (int s = 0; s < 2; s++) {
                for (int i = 0; i < 2; i++) {
                    for (int g = 0; g < 2; g++) {
                        for (int o = 0; o < 2; o++) {
                            for (int m = 0; m < 2; m++) {
                                if (((b+e+s+s+i+e) * (g+o+e+s) * (m+o+o)) % 2 == 0) {
                                    int product = 1;
                                    product *= evenodd[variableIndex('B')][b];
                                    product *= evenodd[variableIndex('E')][e];
                                    product *= evenodd[variableIndex('S')][s];
                                    product *= evenodd[variableIndex('I')][i];
                                    product *= evenodd[variableIndex('G')][g];
                                    product *= evenodd[variableIndex('O')][o];
                                    product *= evenodd[variableIndex('M')][m];
                                    sum += product;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}
