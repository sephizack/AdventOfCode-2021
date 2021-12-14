#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iterator>
#include <ostream>

using namespace std;

#define FOR(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define RFOR(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define REP(i, n) FOR(i, 0, n, 1)
#define RREP(i, n) RFOR(i, n, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define RFOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) (B <= A && A <= C)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int8_t>> heights(1);

    for (char c = cin.get(); !cin.eof(); c = cin.get()) {
        if (c == '\n') {
            heights.emplace_back();
            continue;
        }
        heights.back().push_back(c - '0');
    }

    auto getHeight = [&](size_t i, size_t j) -> int8_t {
        if(!IN(i, 0, heights.size()-1) || !IN(j, 0, heights[i].size()-1)) {
            return 127;
        }
        return heights[i][j];
    };

    uint risk = 0;
    REP(i, (int) heights.size()) {
        const auto& arr = heights[i];
        REP(j, (int) arr.size()) {
            const int8_t height = heights[i][j];
            if (height < getHeight(i-1, j) && height < getHeight(i+1, j) && height < getHeight(i, j-1) && height < getHeight(i, j+1)) {
                risk += height+1;
            }
        }
    }

    cout << risk << endl;

    return 0;
}

