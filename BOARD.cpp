#include <bits/stdc++.h>
using namespace std;

const int Dx[] = {-1, 1, 0, 0};
const int Dy[] = {0, 0, -1, 1};
const int MAXN = 1e3 + 5;
int n, m, a[MAXN][MAXN], deg[MAXN * MAXN], dp[MAXN];
vector <int> adj[MAXN];

int ID(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }    
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + Dx[k];
                int y = j + Dy[k];
                if (x >= 1 && y >= 1 && x <= n && y <= m && a[i][j] < a[x][y]) {
                    deg[ID(x, y)]++;
                    adj[ID(i, j)].push_back(ID(x, y));
                }
            }
        }
    
    queue <int> q;
    for (int i = 1; i <= n * m; i++) if (deg[i] == 0) q.push(i), dp[i] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            deg[v]--;
            dp[v] = max(dp[v], dp[u] + 1);
            if (deg[v] == 0) q.push(v);
        }
    }

    cout << *max_element(dp + 1, dp + n + 1);
}