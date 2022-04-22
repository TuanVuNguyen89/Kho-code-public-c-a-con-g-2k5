/**
*    Author :  Nguyen Tuan Vu
*    Created : 22.04.2022
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

long long x, L, n;

long long binpow(int x, long long k) {
    if (k == 0) return 1;
    long long y = binpow(x, k / 2);
    if (y > 1e18 / y) return 2e18;
    else y = y * y;
    if (k & 1) {
        if (y > 1e18 / x) return 2e18;
        else y = y * x;
    }
    return y;
}

bool check(long long mid) {
    long long y = x - mid;
    long long xx = binpow(2, n - 1);
    if (y > 1e18 / xx) y = 2e18;
    else y = y * xx;
    return (y <= L);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	int t; cin >> t;
	while (t--) {
        cin >> x >> L >> n;
        long long l = -1, r = x + 1;

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }

       // cout << check(0);
       // return 0;
        while (r - l > 1) {
            long long mid = (l + r)>>1;
            if (check(mid)) r = mid;
            else l = mid;
            //cout << l << ' ' << r << '\n';
        }

        cout << r << '\n';
	}
	return 0;
}
