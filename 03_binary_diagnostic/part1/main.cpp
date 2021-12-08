#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string nb;
    cin >> nb;
    vector<int> occurences(nb.size(), 0);
    do {
        for (uint i = 0; i < nb.size(); ++i) {
            occurences[i] += (nb[i] == '1' ? 1 : -1);
        }
    } while (cin >> nb);

    int gamma = 0, epsilon = 0;

    for (const int i : occurences) {
        gamma <<= 1;
        epsilon <<= 1;
        if (i >= 0) {
            gamma += 1;
        } else {
            epsilon += 1;
        }
    }

    cout << gamma * epsilon << endl;

    return 0;
}

