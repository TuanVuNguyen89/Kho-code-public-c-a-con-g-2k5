#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int Mod = 1e9 + 7;
int n, m, deg[MAXN], dp[MAXN];
vector <int> adj[MAXN];
queue <int> List;
vector <int> topo;

void add(int &x, int K) {
    x += K;
    if (x >= Mod) x -= Mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for(int i = 1; i <= n; i++) if (deg[i] == 0) {
        List.push(i);
    }

    dp[1] = 1;
    while (List.size() != 0) {
        int u = List.front();
        topo.push_back(u);
        List.pop();

        for (auto v : adj[u]) {
            deg[v]--;
            add(dp[v], dp[u]);
            if (deg[v] == 0) {
                List.push(v);
            }
        }
    }

    cout << dp[n];
    return 0;
}