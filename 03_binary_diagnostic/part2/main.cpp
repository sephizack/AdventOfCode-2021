#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string nb;
    cin >> nb;
    vector<vector<bool>> numbers;
    do {
        vector<bool> number(nb.size(), false);
        for (uint i = 0; i < nb.size(); ++i) {
            number[i] = (nb[i] == '1');
        }
        numbers.push_back(move(number));
    } while (cin >> nb);

    auto solve = [] (vector<vector<bool>> numbers, bool isOxygen) -> int {
        for (uint i = 0; numbers.size() > 1; ++i) {
            int occurence = 0;
            for (const auto& number : numbers) {
                occurence += (number[i] ? 1 : -1);
            }
            size_t newSize = numbers.size();
            const bool keeping = ((occurence >= 0) ^ isOxygen);
            for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
                if ((*it)[i] != keeping) {
                    swap(*it, numbers[--newSize]);
                }
            }
            numbers.resize(newSize);
        }

        int res = 0;
        for (bool b : numbers.front()) {
            res <<= 1;
            res += b;
        }
        return res;
    };
    int oxygen = solve(numbers, true), co2 = solve(numbers, false);

    cout << oxygen * co2 << endl;

    return 0;
}

