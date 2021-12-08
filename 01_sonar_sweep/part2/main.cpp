#include <array>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    uint increaseCount = 0;

    array<int, 4> windows;
    windows.fill(0);

    // Initializing the windows
    cin >> windows[0];
    cin >> windows[1];
    cin >> windows[2];
    windows[1] += windows[2];
    windows[0] += windows[1];

    uint i = 0;
    uint depth;
    while (cin >> depth) {
        windows[(i+1)%4] += depth;
        windows[(i+2)%4] += depth;
        windows[(i+3)%4] += depth;

        if (windows[i] < windows[(i+1)%4]) {
            ++increaseCount;
        }
        windows[i] = 0;
        i = (i+1)%4;
    }

    cout << increaseCount << endl;

    return 0;
}

