#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <ostream>

using namespace std;

#define FOR(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define RFOR(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define REP(i, n) FOR(i, 0, n, 1)
#define RREP(i, n) RFOR(i, n, 0, 1)

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> positions;

    char c;
    int n;
    int maxPosition = 0;
    do {
        cin >> n;
        positions.push_back(n);
        maxPosition = (n > maxPosition ? n : maxPosition);
    } while (cin >> c);

    int bestCost = INT_MAX;
    // Due to the since of the input, brute forcing is fast enough
    REP(newPosition, maxPosition) {
        int newCost = 0;
        for (int p : positions) {
            int dist = abs(newPosition - p);
            // Sum from 1 to n (1, 2, 3, 6, 10, 15, 21)
            newCost += (dist * (dist+1)) / 2;
        }
        if (newCost < bestCost) {
            bestCost = newCost;
        }
    }

    cout << bestCost << endl;

    return 0;
}

