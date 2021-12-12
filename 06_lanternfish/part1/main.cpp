#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
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

    vector<uint8_t> fishes;

    char c;
    uint n;
    do {
        // We have to use an int here, if we use a char/int8, we'll get the char and not the number value
        cin >> n;
        fishes.push_back(n);
    } while (cin >> c);

    uint newFishes = 0;
    REP(i, 80) {
        for (uint8_t& fish : fishes) {
            if (fish == 0) {
                fish = 6;
                ++newFishes;
            } else {
                --fish;
            }
        }
        fishes.resize(fishes.size() + newFishes, 8);
        newFishes = 0;
    }

    cout << fishes.size() << endl;

    return 0;
}

