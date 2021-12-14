#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <numeric>
#include <ostream>
#include <unordered_map>
#include <utility>

using namespace std;

#define FOR(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define RFOR(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define REP(i, n) FOR(i, 0, n, 1)
#define RREP(i, n) RFOR(i, n, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define RFOREACH(it, l) for (auto it = l.rbegin(); it != l.rend(); it++)
#define IN(A, B, C) (B <= A && A <= C)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
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

    typedef pair<int, int> Coordinates;

    auto hashPair = [](const Coordinates& p) -> size_t { return p.first ^ p.second; };
    unordered_map<Coordinates, Coordinates, decltype(hashPair)> bassins (10, hashPair);
    unordered_map<Coordinates, int, decltype(hashPair)> bassinsSize (10, hashPair);

    vector<pair<Coordinates, Coordinates>> toPropagate;

    // Populate low points
    REP(i, (int) heights.size()) {
        const auto& arr = heights[i];
        REP(j, (int) arr.size()) {
            const int8_t height = heights[i][j];
            if (height < getHeight(i-1, j) && height < getHeight(i+1, j) && height < getHeight(i, j-1) && height < getHeight(i, j+1)) {
                bassins.insert({{i, j}, {i, j}});
                bassinsSize.insert({{i, j}, 1});
                toPropagate.push_back({{i-1, j  }, {i, j}});
                toPropagate.push_back({{i+1, j  }, {i, j}});
                toPropagate.push_back({{i,   j-1}, {i, j}});
                toPropagate.push_back({{i,   j+1}, {i, j}});
            }
        }
    }

    // Propagate bassins
    while (!toPropagate.empty()) {
        const auto [curr, bassin] = toPropagate.back(); toPropagate.pop_back();
        const auto [i, j] = curr;
        const int8_t height = getHeight(i, j);

        if (height < 9 && bassins.count(curr) == 0) {
            bassins.emplace(curr, bassin);
            ++bassinsSize[bassin];
            toPropagate.push_back({{i-1, j  }, bassin});
            toPropagate.push_back({{i+1, j  }, bassin});
            toPropagate.push_back({{i,   j-1}, bassin});
            toPropagate.push_back({{i,   j+1}, bassin});
        }
    }

    // Sorting to take the first three
    vector<int> sizes;
    for (const auto& [_, size] : bassinsSize) {
        sizes.push_back(size);
    }
    sort(all(sizes), greater<>());

    cout << (sizes.at(0) * sizes.at(1) * sizes.at(2)) << endl;

    return 0;
}

