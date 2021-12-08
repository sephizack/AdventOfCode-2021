#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int pos = 0, depth = 0;

    string command;
    int arg;
    while (cin >> command >> arg) {
        // Yolo, the commands are different enough
        switch (command[0]) {
        case 'f':
            pos += arg;
            break;
        case 'd':
            depth += arg;
            break;
        case 'u':
            depth -= arg;
            break;
        }
    }

    cout << pos * depth << endl;

    return 0;
}

