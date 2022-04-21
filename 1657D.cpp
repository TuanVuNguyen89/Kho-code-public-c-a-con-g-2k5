/**
*    Author :  Nguyen Tuan Vu
*    Created : 19.04.2022
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
const int LIM = 1e6 + 5;

int n, lim;
long long dp[LIM];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    cin >> n >> lim;

    for (int c, d, h, i = 1; i <= n; i++) {
        cin >> c >> d >> h;
        dp[c] = max(dp[c], 1ll * d * h);
    }

    for (int i = 1; i <= lim; i++)
        for (int j = i, cnt = 1; j <= lim; j += i, cnt++)
            dp[j] = max(dp[j], dp[i] * cnt);

    for (int i = 1; i <= lim; i++) dp[i] = max(dp[i], dp[i - 1]);

    int query; cin >> query;
    while (query--) {
        long long d, h;
        cin >> d >> h;
        int l = 0, r = lim + 1;
        while (r - l > 1) {
            int mid = (l + r)>>1;
            if (dp[mid] > 1ll * d * h) r = mid;
            else l = mid;
        }

        if (r == lim + 1) r = -1;
        cout << r << ' ';
    }
	return 0;
}
