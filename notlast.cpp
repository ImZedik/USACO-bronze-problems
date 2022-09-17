#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const pair<string, int>& first, const pair<string, int>& second) {
    return first.second < second.second;
}

int notlast() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n;
    cin >> n;
    pair<string, int> sessions[7];
    sessions[0].first = "Bessie";
    sessions[1].first = "Elsie";
    sessions[2].first = "Daisy";
    sessions[3].first = "Gertie";
    sessions[4].first = "Annabelle";
    sessions[5].first = "Maggie";
    sessions[6].first = "Henrietta";
    for (int i = 0; i < n; i++) {
        string s;
        int milk;
        cin >> s >> milk;
        for (auto & session : sessions) {
            if (session.first == s) {
                session.second += milk;
            }
        }
    }
    sort(sessions, sessions + 7, comp);
    int last = sessions[0].second;
    int secondlast = 0;
    bool good = false;
    for (auto & session : sessions) {
        if (session.second > last) {
            good = true;
            secondlast = session.second;
            break;
        }
    }
    if (!good) {
        cout << "Tie" << endl;
        return 0;
    }

    string s = "none";
    for (auto & session : sessions) {
        if (session.second == secondlast) {
            if (s != "none") {
                cout << "Tie" << endl;
                return 0;
            }
            s = session.first;
        }
    }

    cout << s << endl;

//    for (auto & session : sessions) {
//        cout << session.first << " " << session.second << endl;
//    }
    return 0;
}
