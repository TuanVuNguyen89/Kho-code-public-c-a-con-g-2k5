/**
*    Author :  Nguyen Tuan Vu
*    Created : 15.04.2022
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

void file(){
	#define TASK "TASK"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

const int N = 3e5 + 5;
const long long INFLL = 1e18 + 7;
int n, m, type[N], cur, War[N], Destroy[N], okay[N];
long long dist[N];
vector <int> Han, So;
vector <pair <int, int>> adj[N];

void Attack(int u, long long K) {
    if (War[u] == cur) return;
    if (dist[u] <= K) {
        Destroy[u] = cur;
        return;
    }

    War[u] = cur;
    for (auto v:adj[u]) Attack(v.second, K);
}

void Rescue(int u) {
    if (Destroy[u] == cur || okay[u] == cur) return;
    okay[u] = cur;
    for (auto v:adj[u]) Rescue(v.second);
}

bool check(long long K) {
    ++cur;
    for (auto x: So) Attack(x, K);
    Rescue(Han[0]);
    for (auto x: Han) if (okay[x] != cur) return false;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
    cin >> n >> m;
    #define li pair <long long, int>
    priority_queue <li, vector <li>, greater <li>> heap;
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
        dist[i] = INFLL;
        if (type[i] == -1) So.push_back(i);
        else if (type[i] == 1) {
            Han.push_back(i);
            dist[i] = 0;
            heap.push({0, i});
        }
    }

    for (int u, v, w, i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    while (heap.size()) {
        long long du = heap.top().first;
        int u = heap.top().second;

        heap.pop();
        if (du != dist[u]) continue;

        for (auto v:adj[u]) {
            if (dist[v.second] > dist[u] + v.first && type[v.second] == 0) {
                dist[v.second] = dist[u] + v.first;
                heap.push({dist[v.second], v.second});
            }
        }
    }

    long long l = -1, r = INFLL - 1;
    while (r - l > 1) {
        long long mid = (l + r)>>1;
        if (check(mid)) r = mid;
        else l = mid;
    }

    if (r == INFLL) r = -1;
    cout << r;
	return 0;
}
