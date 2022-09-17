#include <iostream>

using namespace std;

int triangles() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> pairs[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pairs[i].first = x;
        pairs[i].second = y;
    }
    int maxArea = 0;
    for (pair<int, int> vertex: pairs) {
        for (pair<int, int> vertex2: pairs) {
            if (vertex == vertex2) continue;
            if (vertex2.first == vertex.first) {
                for (pair<int, int> vertex3 : pairs) {
                    if (vertex == vertex3 || vertex2 == vertex3) continue;
                    if (vertex3.second == vertex.second) {
                        int twoTimesArea = abs(vertex2.second - vertex.second) * abs(vertex3.first - vertex.first);
                        if (twoTimesArea > maxArea) {
                            maxArea = twoTimesArea;
                        }
                    }
                }
            }
        }
    }
    cout << maxArea << endl;
    return 0;
}
