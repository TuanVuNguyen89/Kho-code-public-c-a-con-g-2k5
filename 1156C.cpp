/**
*    Author :  Nguyen Tuan Vu
*    Created : 18.04.2022
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

const int N = 2e5 + 5;
int n, z, a[N];
bool dd[N];

bool check(int x) {
    for (int i = 1; i <= x; i++) if (a[n - x + i] - a[i] < z) return false;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	file();
    cin >> n >> z;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + n + 1);

    int l = 0, r = n/2 + 1;
    while (r - l > 1) {
        int mid = (l + r)>>1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
	return 0;
}
