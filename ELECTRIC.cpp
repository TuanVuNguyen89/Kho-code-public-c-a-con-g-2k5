/**
*    Author :  Nguyen Tuan Vu
*    Created : 13.02.2023
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
    #define TASK "ELECTRIC"
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}

const int N = 2e5 + 5;
int n, dp[N], par[N];
vector <int> adj[N];
string s;

void dfs(int u) {
    for (auto v : adj[u]) if (par[u] != v) {
        par[v] = u;
        dfs(v);
    }

    dp[u] = (s[u] == '1' ? -1 : 0);
    for (auto v : adj[u]) if (par[u] != v) {
        dp[u] += max(0, dp[v]);
    }

    maximize(dp[u], (s[u] == '1'));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file();
    cin >> n;
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s; s = ' ' + s;
    dfs(1);
    int ans = 1;
    FOR(u, 1, n) {
        for (auto v : adj[u]) if (par[u] != v) {
            maximize(ans, (s[u] == '1' ? 1 : 0) + dp[v]);
        }

        int res = (s[u] == '1' ? -1 : 0);
        for (auto v : adj[u]) if (par[u] != v) {
            res += dp[v];
            maximize(ans, res);
        }
    }

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
/*
⣿⣿⣿⣿⣿⣿⡷⣯⢿⣿⣷⣻⢯⣿⡽⣻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠸⣿⣿⣆⠹⣿⣿⢾⣟⣯⣿⣿⣿⣿⣿⣿⣽⣻⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣻⣽⡿⣿⣎⠙⣿⣞⣷⡌⢻⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⡄⠹⣿⣿⡆⠻⣿⣟⣯⡿⣽⡿⣿⣿⣿⣿⣽⡷⣯⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣟⣷⣿⣿⣿⡀⠹⣟⣾⣟⣆⠹⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢠⡘⣿⣿⡄⠉⢿⣿⣽⡷⣿⣻⣿⣿⣿⣿⡝⣷⣯⢿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣯⢿⣾⢿⣿⡄⢄⠘⢿⣞⡿⣧⡈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣧⠘⣿⣷⠈⣦⠙⢿⣽⣷⣻⣽⣿⣿⣿⣿⣌⢿⣯⢿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣟⣯⣿⢿⣿⡆⢸⡷⡈⢻⡽⣷⡷⡄⠻⣽⣿⣿⡿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣏⢰⣯⢷⠈⣿⡆⢹⢷⡌⠻⡾⢋⣱⣯⣿⣿⣿⣿⡆⢻⡿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡎⣿⢾⡿⣿⡆⢸⣽⢻⣄⠹⣷⣟⣿⣄⠹⣟⣿⣿⣟⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⢸⣯⣟⣧⠘⣷⠈⡯⠛⢀⡐⢾⣟⣷⣻⣿⣿⣿⡿⡌⢿⣻⣿⣿
⣿⣿⣿⣿⣿⣿⣧⢸⡿⣟⣿⡇⢸⣯⣟⣮⢧⡈⢿⣞⡿⣦⠘⠏⣹⣿⣽⢿⣿⣿⣿⣿⣯⣿⣿⣿⡇⢸⣿⣿⣾⡆⠹⢀⣠⣾⣟⣷⡈⢿⣞⣯⢿⣿⣿⣿⢷⠘⣯⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡈⣿⢿⣽⡇⠘⠛⠛⠛⠓⠓⠈⠛⠛⠟⠇⢀⢿⣻⣿⣯⢿⣿⣿⣿⣷⢿⣿⣿⠁⣾⣿⣿⣿⣧⡄⠇⣹⣿⣾⣯⣿⡄⠻⣽⣯⢿⣻⣿⣿⡇⢹⣾⣿
⣿⣿⣿⣿⣿⣿⣿⡇⢹⣿⡽⡇⢸⣿⣿⣿⣿⣿⣞⣆⠰⣶⣶⡄⢀⢻⡿⣯⣿⡽⣿⣿⣿⢯⣟⡿⢀⣿⣿⣿⣿⣿⣧⠐⣸⣿⣿⣷⣿⣿⣆⠹⣯⣿⣻⣿⣿⣿⢀⣿⢿
⣿⣿⣿⣿⣿⣿⣿⣿⠘⣯⡿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣧⡈⢿⣳⠘⡄⠻⣿⢾⣽⣟⡿⣿⢯⣿⡇⢸⣿⣿⣿⣿⣿⣿⡀⢾⣿⣿⣿⣿⣿⣿⣆⠹⣾⣷⣻⣿⡿⡇⢸⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡇⢹⣿⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠻⡇⢹⣆⠹⣟⣾⣽⣻⣟⣿⣽⠁⣾⣿⣿⣿⣿⣿⣿⣇⣿⣿⠿⠛⠛⠉⠙⠋⢀⠁⢘⣯⣿⣿⣧⠘⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡈⣿⡃⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡙⠌⣿⣆⠘⣿⣞⡿⣞⡿⡞⢠⣿⣿⣿⣿⣿⡿⠛⠉⠁⢀⣀⣠⣤⣤⣶⣶⣶⡆⢻⣽⣞⡿⣷⠈⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠘⠁⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠛⢿⣄⢻⣿⣧⠘⢯⣟⡿⣽⠁⣾⣿⣿⣿⣿⣿⡃⢀⢀⠘⠛⠿⢿⣻⣟⣯⣽⣻⣵⡀⢿⣯⣟⣿⢀⣿
⣿⣿⣿⣟⣿⣿⣿⣿⣶⣶⡆⢀⣿⣾⣿⣾⣷⣿⣶⠿⠚⠉⢀⢀⣤⣿⣷⣿⣿⣷⡈⢿⣻⢃⣼⣿⣿⣿⣿⣻⣿⣿⣿⡶⣦⣤⣄⣀⡀⠉⠛⠛⠷⣯⣳⠈⣾⡽⣾⢀⣿
⣿⢿⣿⣿⣻⣿⣿⣿⣿⣿⡿⠐⣿⣿⣿⣿⠿⠋⠁⢀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣌⣥⣾⡿⣿⣿⣷⣿⣿⢿⣷⣿⣿⣟⣾⣽⣳⢯⣟⣶⣦⣤⡾⣟⣦⠘⣿⢾⡁⢺
⣿⣻⣿⣿⡷⣿⣿⣿⣿⣿⡗⣦⠸⡿⠋⠁⢀⢀⣠⣴⢿⣿⣽⣻⢽⣾⣟⣷⣿⣟⣿⣿⣿⣳⠿⣵⣧⣼⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣽⣳⣯⣿⣿⣿⣽⢀⢷⣻⠄⠘
⣿⢷⣻⣿⣿⣷⣻⣿⣿⣿⡷⠛⣁⢀⣀⣤⣶⣿⣛⡿⣿⣮⣽⡻⣿⣮⣽⣻⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⢀⢸⣿⢀⡆
⠸⣟⣯⣿⣿⣷⢿⣽⣿⣿⣷⣿⣷⣆⠹⣿⣶⣯⠿⣿⣶⣟⣻⢿⣷⣽⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣯⣟⢀⡇
⣇⠹⣟⣾⣻⣿⣿⢾⡽⣿⣿⣿⣿⣿⣆⢹⣶⣿⣻⣷⣯⣟⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢀⡿⡇⢸⡇
⣿⣆⠹⣷⡻⣽⣿⣯⢿⣽⣻⣿⣿⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⢸⣿⠇⣼⡇
⡙⠾⣆⠹⣿⣦⠛⣿⢯⣷⢿⡽⣿⣿⣿⣿⣆⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠎⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢀⣿⣾⣣⡿⡇
⣿⣷⡌⢦⠙⣿⣿⣌⠻⣽⢯⣿⣽⣻⣿⣿⣿⣧⠩⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⢰⢣⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⢀⢀⢿⣞⣷⢿⡇
⣿⣽⣆⠹⣧⠘⣿⣿⡷⣌⠙⢷⣯⡷⣟⣿⣿⣿⣷⡀⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣈⠃⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢀⣴⡧⢀⠸⣿⡽⣿⢀
⢻⣽⣿⡄⢻⣷⡈⢿⣿⣿⢧⢀⠙⢿⣻⡾⣽⣻⣿⣿⣄⠌⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢁⣰⣾⣟⡿⢀⡄⢿⣟⣿⢀
⡄⢿⣿⣷⢀⠹⣟⣆⠻⣿⣿⣆⢀⣀⠉⠻⣿⡽⣯⣿⣿⣷⣈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣠⠘⣯⣷⣿⡟⢀⢆⠸⣿⡟⢸
⣷⡈⢿⣿⣇⢱⡘⢿⣷⣬⣙⠿⣧⠘⣆⢀⠈⠻⣷⣟⣾⢿⣿⣆⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣠⡞⢡⣿⢀⣿⣿⣿⠇⡄⢸⡄⢻⡇⣼
⣿⣷⡈⢿⣿⡆⢣⡀⠙⢾⣟⣿⣿⣷⡈⠂⠘⣦⡈⠿⣯⣿⢾⣿⣆⠙⠻⠿⠿⠿⠿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢋⣠⣾⡟⢠⣿⣿⢀⣿⣿⡟⢠⣿⢈⣧⠘⢠⣿
⣿⣿⣿⣄⠻⣿⡄⢳⡄⢆⡙⠾⣽⣿⣿⣆⡀⢹⡷⣄⠙⢿⣿⡾⣿⣆⢀⡀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⣀⣠⣴⡿⣯⠏⣠⣿⣿⡏⢸⣿⡿⢁⣿⣿⢀⣿⠆⢸⣿
⣿⣿⣿⣿⣦⡙⣿⣆⢻⡌⢿⣶⢤⣉⣙⣿⣷⡀⠙⠽⠷⠄⠹⣿⣟⣿⣆⢙⣋⣤⣤⣤⣄⣀⢀⢀⢀⢀⣾⣿⣟⡷⣯⡿⢃⣼⣿⣿⣿⠇⣼⡟⣡⣿⣿⣿⢀⡿⢠⠈⣿
⣿⣿⣿⣿⣿⣷⣮⣿⣿⣿⡌⠁⢤⣤⣤⣤⣬⣭⣴⣶⣶⣶⣆⠈⢻⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣷⣶⣤⣌⣉⡘⠛⠻⠶⣿⣿⣿⣿⡟⣰⣫⣴⣿⣿⣿⣿⠄⣷⣿⣿⣿
*/
