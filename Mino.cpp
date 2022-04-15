/**
*    Author :  Nguyen Tuan Vu
*    Created : 15.04.2022
**/

#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

void file(){
	#define TASK ""
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

long long f(int x) {
    return 2ll*x*x - 12*x + 7;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();

    int test; cin >> test;
    while (test--) {
        int l, r; cin >> l >> r;
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
