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
int n, m, nquery, num[N], low[N], cnt, numComp, compID[N], deg[N];
vector <int> adj[N], adj2[N];
stack <int> s;
bitset <N> reach[N];
 
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    s.push(u);
 
    for (auto v : adj[u]) if (num[v]) {
        minimize(low[u], num[v]);
    }
    else {
        dfs(v);
        minimize(low[u], low[v]);
    }
 
    if (num[u] == low[u]) {
        numComp++;
        while (1) {
            int v = s.top();
            s.pop();
 
            compID[v] = numComp;
            num[v] = low[v] = n + 1;
            if (u == v) break;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();
 
    cin >> n >> m >> nquery;
    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	adj[u].push_back(v);
    }
 
    FOR(i, 1, n) if (num[i] == 0) dfs(i);
 
    FOR(u, 1, n) {
        for (auto v : adj[u]) if (compID[u] != compID[v]) {
            adj2[compID[u]].push_back(compID[v]);
            deg[compID[v]]++;
        }
    }
 
    queue <int> q;
    FOR(i, 1, numComp) {
        if (deg[i] == 0) q.push(i);
        reach[i][i] = 1;
    }
 
    while (q.size()) {
        int u = q.front();
        q.pop();
 
        for (auto v : adj2[u]) {
            deg[v]--;
            reach[v] |= reach[u];
            if (deg[v] == 0) q.push(v);
        }
    }
 
    while (nquery--) {
        int u, v; cin >> u >> v;
        cout << (reach[compID[v]][compID[u]] ? "YES\n" : "NO\n");
    }
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