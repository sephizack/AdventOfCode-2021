#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    uint increaseCount = 0;

    int prev, curr;
    cin >> prev;
    while (cin >> curr) {
        increaseCount += curr > prev;
        prev = curr;
    }

    cout << increaseCount << endl;

    return 0;
}

