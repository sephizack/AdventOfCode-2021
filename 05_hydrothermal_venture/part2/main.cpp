#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

#define sign(x) ((x > 0) - (x < 0))

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    typedef pair<int, int> Point;
    typedef pair<Point, Point> Line;

    vector<Line> lines;
    int maxX = 0, maxY = 0;

    // Parsing input
    int x1, x2, y1, y2;
    while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
        lines.push_back({{x1, y1}, {x2, y2}});
        maxX = max(maxX, max(x1, x2));
        maxY = max(maxY, max(y1, y2));
    }

    // Creating grid
    vector<vector<int>> grid(maxY + 1);
    for (auto& arr : grid) {
        arr = vector(maxX + 1, 0);
    }

    // Populating lines
    for (const auto& line : lines) {
        int x1 = line.first.first;
        int y1 = line.first.second;
        int x2 = line.second.first;
        int y2 = line.second.second;

        if (x1 == x2) {
            int minY = min(y1, y2), maxY = max(y1, y2);
            for (int y = minY; y <= maxY; ++y) {
                grid[y][x1] += 1;
            }
        } else if (y1 == y2)  {
            int minX = min(x1, x2), maxX = max(x1, x2);
            for (int x = minX; x <= maxX; ++x) {
                grid[y1][x] += 1;
            }
        } else {
            int deltaX = sign(x2 - x1);
            int deltaY = sign(y2 - y1);
            for (int x = x1, y = y1; ; x += deltaX, y += deltaY) {
                grid[y][x] += 1;
                if (x == x2 && y == y2) {
                    break;
                }
            }
        }
    }

    // Counting superpositions
    uint atLeastTwo = 0;
    for (auto& arr : grid) {
        for (int& i : arr) {
            if (i >= 2) {
                ++atLeastTwo;
            }
        }
    }

    cout << atLeastTwo << endl;

    return 0;
}

