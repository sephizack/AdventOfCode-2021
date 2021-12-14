#include <bits/stdc++.h>

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

    return 0;
}

