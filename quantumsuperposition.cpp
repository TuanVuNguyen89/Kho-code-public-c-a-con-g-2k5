/**
*    Author :  Nguyen Tuan Vu
*    Created : 27.01.2023
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
long long Rand(long long l, long long r) {return l + rng() % (r - l + 1);}

void file(){
    #define TASK "TASK"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}

const int N = 1e3 + 5;
int n[2], m[2], dist[2][N][N], nquery, deg[2][N];
vector <int> adj[2][N];

void topo(int type) {
	queue <int> q;
	FOR(i, 1, n[type]) if (deg[type][i] == 0) q.push(i);
	dist[type][1][0] = 1;

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (auto v : adj[type][u]) {
			deg[type][v]--;
			FOR(i, 0, n[type]) if (dist[type][u][i]) dist[type][v][i + 1] = 1;
			if (deg[type][v] == 0) {
				q.push(v);
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();
    cin >> n[0] >> n[1] >> m[0] >> m[1];
    REP(i, 2) FOR(j, 1, m[i]) {
    	int u, v; cin >> u >> v;
    	deg[i][v]++;
    	adj[i][u].push_back(v);
    	adj[i][v].push_back(u);
    }

    REP(i, 2) topo(i);
    cin >> nquery;
    while (nquery--) {
    	int x; cin >> x;
    	bool ok = 0;

    	FOR(i, 0, x) if (dist[0][n[0]][i] && dist[1][n[1]][x - i]) {
    		ok = 1;
    		break;
    	}

    	cout << (ok ? "Yes\n" : "No\n");
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
