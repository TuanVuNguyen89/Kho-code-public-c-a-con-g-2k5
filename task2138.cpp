/**
*    Author :  Nguyen Tuan Vu
*    Created : 18.11.2022
**/
 
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define MASK(x) ((1)<<(x))
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
 
mt19937 jdg(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {return l + jdg() % (r - l + 1);}
 
void file(){
    #define TASK "TASK"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}
 
const int N = 5e4 + 5;
int n, m, deg[N];
vector <int> adj[N];
bitset <N> reach[N];
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();
 
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
        deg[u]++;
    }
 
    queue <int> q;
    FOR(i, 1, n) if (deg[i] == 0) q.push(i);
 
    FOR(i, 1, n) reach[i][i] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
 
        for (auto v : adj[u]) {
            deg[v]--;
            reach[v] |= reach[u];
 
            if (deg[v] == 0) q.push(v);
        }
    }
 
    FOR(i, 1, n) cout << reach[i].count() << ' ';
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