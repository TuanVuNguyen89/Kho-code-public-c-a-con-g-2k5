#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, deg[MAXN];
vector <int> adj[MAXN];
priority_queue <int, vector <int>, greater <int>> List_Min;
priority_queue <int> List_Max;
vector <int> topo;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) if (deg[i] == 0) {
        List_Min.push(i);
    }

    while (List_Min.size() != 0) {
        int u = List_Min.top();
        topo.push_back(u);
        List_Min.pop();

        for (auto v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                List_Min.push(v);
            }
        }
    }

    for (auto x : topo) cout << x << ' ';
    cout << '\n';
    topo.clear();
    for (int i = 1; i <= n; i++) {
        for (auto j : adj[i]) {
            deg[j]++;
        }
    }

    for (int i = 1; i <= n; i++) if (deg[i] == 0) {
        List_Max.push(i);
    }

    while(List_Max.size()) {
        int u = List_Max.top();
        topo.push_back(u);
        List_Max.pop();

        for (auto v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                List_Max.push(v);
            }
        }
    }

    for (auto x : topo) cout << x << ' ';
    return 0;
}