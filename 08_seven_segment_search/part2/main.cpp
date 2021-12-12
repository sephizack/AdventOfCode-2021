#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ostream>

using namespace std;

#define FOR(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define RFOR(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define REP(i, n) FOR(i, 0, n, 1)
#define RREP(i, n) RFOR(i, n, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define RFOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

enum Segments {
    kTop         = 1 << 0,
    kTopLeft     = 1 << 1,
    kTopRight    = 1 << 2,
    kMiddle      = 1 << 3,
    kBottomLeft  = 1 << 4,
    kBottomRight = 1 << 5,
    kBottom      = 1 << 6,
};

typedef bitset<7> Display;

Display toDisplay(string s) {
    Display res;
    for (char c : s) {
        res.set(c - 'a');
    } return res;
}

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    uint total = 0;

    while (!cin.eof()) {
        array<Display, 10> numberToDisplay;
        vector<Display> unknownDisplay235;
        vector<Display> unknownDisplay069;
        REP(i, 10) {
            string s;
            cin >> s;
            switch (s.size()) {
            case 2:
                numberToDisplay[1] = toDisplay(s);
                break;
            case 3:
                numberToDisplay[7] = toDisplay(s);
                break;
            case 4:
                numberToDisplay[4] = toDisplay(s);
                break;
            case 5:
                unknownDisplay235.push_back(toDisplay(s));
                break;
            case 6:
                unknownDisplay069.push_back(toDisplay(s));
                break;
            case 7:
                numberToDisplay[8] = toDisplay(s);
                break;
            }
        }

        // Look for the 3 in 2,3,5 with the 1
        FOREACH(it, unknownDisplay235) {
            if ((*it & numberToDisplay[1]) == numberToDisplay[1]) {
                numberToDisplay[3] = *it;
                unknownDisplay235.erase(it);
                break;
            }
        }
        // Look for the 9 in 0,6,9 with the 3
        FOREACH(it, unknownDisplay069) {
            if ((*it & numberToDisplay[3]) == numberToDisplay[3]) {
                numberToDisplay[9] = *it;
                unknownDisplay069.erase(it);
                break;
            }
        }
        // Look for the 5 in 2,5 with the 9
        FOREACH(it, unknownDisplay235) {
            if ((*it & numberToDisplay[9]) == *it) {
                numberToDisplay[5] = *it;
                unknownDisplay235.erase(it);
                break;
            }
        }
        // The last is the 2
        numberToDisplay[2] = unknownDisplay235.front();
        // Look for the 6 in 0,6 with the 5
        FOREACH(it, unknownDisplay069) {
            if ((*it & numberToDisplay[5]) == numberToDisplay[5]) {
                numberToDisplay[6] = *it;
                unknownDisplay069.erase(it);
                break;
            }
        }
        // The last is the 0
        numberToDisplay[0] = unknownDisplay069.front();

        cin.ignore(INT_MAX, '|');

        uint nb = 0;
        REP(i, 4) {
            nb *= 10;
            string s;
            cin >> s;
            auto d = toDisplay(s);
            REP(j, 10) {
                if (numberToDisplay[j] == d) {
                    nb += j;
                    break;
                }
            }
        }
        total += nb;
    }

    cout << total << endl;

    return 0;
}

