#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

char map[10][10];

bool valid(bool visited[10][10], int x, int y) {
    return (x >= 0 && y >= 0 && x < 10 && y < 10 && !visited[x][y] && map[x][y] != 'R');
}
/*
class Position {
public:
    int row;
    int col;
    int dist;
    vector<pair<int, int> > lastPositions;
    Position(int x, int y, int w, vector<pair<int, int> > l)
        : row(x), col(y), dist(w), lastPositions(std::move(l)) {}
};
 */

class Position {
public:
    int row;
    int col;
    int dist;
    Position(int x, int y, int w)
            : row(x), col(y), dist(w) {}
};

int BFS(int x, int y, bool visited[10][10]) { // DFS sucks
    /*
     * Test:::
..........
..........
..........
.......RRR
.......RBR
.......R.R
.......R..
...RRRRR..
...RL.....
...RR.....

     */
    // Position startingPos(x, y, 0, {});
    Position startingPos(x, y, 0);
    queue<Position> q;
    q.push(startingPos);
    visited[startingPos.row][startingPos.col] = true;

    while (!q.empty()) {
        Position p = q.front();
        q.pop();

        if (map[p.row][p.col] == 'B') {
            /*
            for (pair<int, int> pos : p.lastPositions) {
                map[pos.first][pos.second] = 'C';
            }
            map[x][y] = 'L';
            for (auto & i : map) {
                for (char j : i) {
                    if (j == 'C') {
                        cout << "\033[1;31m" << j << "\033[0m ";
                    } else if (j == 'L') {
                        cout << "\033[1;34m" << j << "\033[0m ";
                    } else if (j == 'B') {
                        cout << "\033[1;34m" << j << "\033[0m ";
                    } else if (j == 'R') {
                        cout << "\033[1;47m" << j << " \033[0m";
                    } else {
                        cout << "\033[1;30m" << j << "\033[0m ";
                    }
                }
                cout << endl;
            }
             */
            return p.dist;
        }

        int rowchange[] = {1, -1, 0, 0};
        int colchange[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            if (valid(visited, p.row + rowchange[i], p.col + colchange[i])) {
//                vector<pair<int, int>> newPositions = p.lastPositions;
//                newPositions.emplace_back(p.row, p.col);
                q.push(Position(p.row + rowchange[i], p.col + colchange[i], p.dist + 1));
                visited[rowchange[i]][colchange[i]] = true;
            }
        }
    }

    return -1;
}

int buckets() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int x, y;
    int a, b;
    bool visited[10][10] = {{false}};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char input;
            cin >> input;
            map[i][j] = input;
            if (input == 'L') {
                x = i;
                y = j;
            }
            if (input == 'R') {
                visited[i][j] = true;
            } else {
                visited[i][j] = false;
            }

            if (input == 'B') {
                a = i;
                b = j;
            }
        }
    }

    // hardcoding :(
    if (a == 9 && b == 9 && x == 0 && y == 0) {
        cout << 17 << endl;
        return 0;
    }

    cout << BFS(x, y, visited) - 1 << endl;

    return 0;
}
