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

    uint count1478 = 0;

    string pattern;
    while (!cin.eof()) {
        cin.ignore(INT_MAX, '|');
        REP(i, 4) {
            cin >> pattern;
            switch (pattern.size()) {
            case 2:
            case 3:
            case 4:
            case 7:
                count1478 += 1;
            }
        }
    }

    cout << count1478 << endl;

    return 0;
}

