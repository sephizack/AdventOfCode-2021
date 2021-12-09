#include <array>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> numbers;

    do {
        int i;
        cin >> i;
        numbers.push_back(i);
    } while (cin.get() != '\n');

    typedef array<array<int, 5>, 5> Board;
    vector<Board> boards;

    // Parsing the boards
    // DISCLAIMER: not safe if there is a \n at the end of the file
    while (!cin.eof()) {
        cin.get();
        Board& board = boards.emplace_back();
        for (auto& arr: board) {
            for (int& i : arr) {
                cin >> i;
            }
        }
    }

    // Simulating the draft
    for (int nb : numbers) {
        for (auto it = boards.rbegin(); it != boards.rend(); ++it) {
            auto& board = *it;
            bitset<5> isColumnComplete;
            isColumnComplete.set();
            bool isRowComplete;
            // Mark the drafted number and check completion of the row/column
            for (uint i = 0; i < board.size(); ++i) {
                isRowComplete = true;
                for (uint j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == nb) {
                        board[i][j] = -1;
                    }
                    if (board[i][j] != -1) {
                        isRowComplete = false;
                        isColumnComplete[j] = false;
                    }
                }
                if (isRowComplete) {
                    break;
                }
            }
            // Check if we have a winner
            if (isColumnComplete.any() || isRowComplete) {
                // If the board wins, unless it's the last we remove it from the list
                if (boards.size() > 1) {
                    std::swap(*it, boards.back());
                    boards.pop_back();
                    continue;
                }
                // Compute score
                int score = 0;
                for (uint i = 0; i < board.size(); ++i) {
                    for (uint j = 0; j < board[i].size(); ++j) {
                        if (board[i][j] != -1) {
                            score += board[i][j];
                        }
                    }
                }
                cout << score * nb << endl;
                return 0;
            }
        }
    }

    cout << "No winner !" << endl;

    return 0;
}

