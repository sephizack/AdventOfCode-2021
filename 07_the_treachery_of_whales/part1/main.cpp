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
    do {
        cin >> n;
        positions.push_back(n);
    } while (cin >> c);

    int bestCost = INT_MAX;
    for (int newPosition : positions) {
        int newCost = 0;
        for (int p : positions) {
            newCost += abs(newPosition - p);
        }
        if (newCost < bestCost) {
            bestCost = newCost;
        }
    }

    cout << bestCost << endl;

    return 0;
}

