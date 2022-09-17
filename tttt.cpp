#include <iostream>
#include <vector>

using namespace std;

vector<char> individualVictory;
vector<pair<char, char>> teamVictory;

char min(const char *arr) {
    char m = arr[0];
    for (int i = 0; i < 3; i++) {
        if (arr[i] < m) {
            m = arr[i];
        }
    }
    return m;
}

char max(const char *arr) {
    char m = arr[0];
    for (int i = 0; i < 3; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

void evaluateVictory(char c1, char c2, char c3) {
    if (c1 == c2 && c2 == c3) {
        for (char c : individualVictory) {
            if (c == c1) {
                return;
            }
        }
        individualVictory.push_back(c1);
    } else if (c1 == c2 || c2 == c3 || c1 == c3) {
        char t_[] = {c1, c2, c3};
        pair<char, char> t;
        t.first = min(t_);
        t.second = max(t_);

        for (pair<char, char> team: teamVictory) {
            if ((team.first == t.first && team.second == t.second) ||
                (team.first = t.second && team.second == t.first)) {
                return;
            }
        }
        teamVictory.push_back(t);
    }
}

int tttt() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    char board[3][3];
    for (auto & i : board) {
        for (char & j : i) {
            cin >> j;
        }
    }
    int x0[] = {0, 1, 2};

    for (int x: x0) {
        evaluateVictory(board[x][0], board[x][1], board[x][2]); // horizontal
        evaluateVictory(board[0][x], board[1][x], board[2][x]); // vertical
    }

    // diagonals
    evaluateVictory(board[0][0], board[1][1], board[2][2]);
    evaluateVictory(board[2][0], board[1][1], board[0][2]);

    cout << individualVictory.size() << endl << teamVictory.size() << endl;

    return 0;
}
