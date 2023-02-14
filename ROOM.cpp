/**
*    Author :  Nguyen Tuan Vu
*    Created : 12.02.2023
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
    #define TASK "ROOM"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}

const int N = 1e3 + 5;
int n, m, a[N][N], b[N + N];

bool mark(int u, int v) {
	if (a[u][v] == 0) return true;
	if (b[u + v] == 1) return false;

	queue <pair <int, int>> q;
	q.push({u, v});
	while (q.size()) {
		int u = q.front().first;
		int v = q.front().second;
		q.pop();

		if (a[u][v] == 1) {
			b[u + v]--;
			a[u][v] = 0;

			if (a[u - 1][v + 1] == 0) {
				q.push({u - 1, v});
				q.push({u, v + 1});
			}

			if (a[u + 1][v - 1] == 0) {
				q.push({u, v - 1});
				q.push({u + 1, v});
			}
		}
	}

	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) {
    	b[i + j]++;
    	a[i][j] = 1;
    }

    FOR(i, 1, n) FOR(j, 1, m) {
    	int x; cin >> x;
    	if (x == 1) mark(i, j);
    }

    int nquery; cin >> nquery;
    while (nquery--) {
    	int u, v; cin >> u >> v;
    	cout << mark(u, v) << '\n';
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
