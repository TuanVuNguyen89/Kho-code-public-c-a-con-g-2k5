/**
*    Author :  Nguyen Tuan Vu
*    Created : 14.04.2022
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

const int N = 1e4 + 5;
int n, h[N], c[N];

long long f(int x) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += 1ll*abs(x - h[i])*c[i];
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        int l = 0, r = 1e4 + 1;
        while (r - l > 2) {
            int mid1 = (2*l + r)/3;
            int mid2 = (l + 2*r)/3;
            if (f(mid1) <= f(mid2)) r = mid2;
            else l = mid1;
        }
        cout << min({f(l), f(l + 1), f(r)}) << '\n';
    }
	return 0;
}
