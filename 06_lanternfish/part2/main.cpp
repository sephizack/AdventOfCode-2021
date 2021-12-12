#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <ostream>

using namespace std;

#define FOR(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define RFOR(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define REP(i, n) FOR(i, 0, n, 1)
#define RREP(i, n) RFOR(i, n, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    array<uint64_t, 9> fishes;
    fishes.fill(0);

    char c;
    uint n;
    do {
        cin >> n;
        fishes[n] += 1;
    } while (cin >> c);

    REP(i, 256) {
        // Rotation to the right
        rotate(fishes.begin(), fishes.begin() + 1, fishes.end());
        // With the rotation, we put the old fish[0] in fish[8], which represent the new fishes.
        // However, the old fishes must be on 6, so we add them (actually "creating" the new fishes)
        fishes[6] += fishes[8];
    }

    cout << accumulate(all(fishes), 0ul) << endl;

    return 0;
}

