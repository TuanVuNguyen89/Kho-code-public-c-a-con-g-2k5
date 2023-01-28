/**
*    Author :  Nguyen Tuan Vu
*    Created : 28.12.2022
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define MASK(x) ((1ll)<<(x))
#define BIT(x, i) (((x)>>(i))&(1))
#define ALL(v)  (v).begin(), (v).end()
#define REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i)
#define db(val) "["#val" = "<<(val)<<"] "
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {return l + rng() % (r - l + 1);}

void file(){
    #define TASK "TASK"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}

const int N = 3e5 + 5;
int n, m, dp[N][26], deg[N];
string s;
vector <int> adj[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();

    cin >> n >> m >> s; s = ' ' + s;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue <int> q;
    FOR(i, 1, n) if (deg[i] == 0) q.push(i), dp[i][s[i] - 'a'] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            deg[v]--;
            REP(i, 26) maximize(dp[v][i], dp[u][i] + (s[v] - 'a' == i));
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    FOR(i, 1, n) if (deg[i]) return cout << -1, 0;
    int ans = 0;
    FOR(i, 1, n) REP(j, 26) maximize(ans, dp[i][j]);
    cout << ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/