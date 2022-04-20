/**
*    Author :  Nguyen Tuan Vu
*    Created : 19.04.2022
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

template <class X, class Y> bool minimize(X &a, Y b) {
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b) {
    if (a < b) return a = b, true;
    return false;
}

using namespace std;

void file(){
	#define TASK "TASK"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

#define MASK(x) ((1)<<(x))
#define BIT(x, i) (((x)>>(i))&(1))

const int INF = 1e9 + 7;
int n, k, a[20], dp[MASK(12)], cost[MASK(12)];

bool check(int x) {
    for (int i = 0; i <= MASK(n) - 1; i++) {
        dp[i] = INF;
        cost[i] = 0;
        for (int j = 0; j < n; j++) if (BIT(i, j)) cost[i] += a[j + 1];
    }

    dp[0] = 0;
    for (int mask = 1; mask <= MASK(n) - 1; mask++) {
        if (cost[mask] <= x) dp[mask] = dp[0] + 1;
        for (int s = mask; s; s = (s - 1)&mask) 
            if (cost[mask ^ s] <= x) {
                minimize(dp[mask], dp[s] + 1);
            }
    }
    return (dp[MASK(n) - 1] <= k);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 0, r = 12000 + 7;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r;
	return 0;
}
