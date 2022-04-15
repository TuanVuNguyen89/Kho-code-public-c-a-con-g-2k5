/**
*    Author :  Nguyen Tuan Vu
*    Created : 13.04.2022
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

#define ld long double
ld xx1, yy1, xx2, yy2, vv1, vv2;

ld dist(ld xx1, ld yy1, ld xx2, ld yy2) {
    return sqrt((xx2 - xx1)*(xx2 - xx1) + (yy2 - yy1)*(yy2 - yy1));
}

ld f(ld x) {
    return dist(xx1, yy1, x, 0)/vv1 + dist(x, 0, xx2, yy2)/vv2;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
    int t; cin >> t;
    while (t--) {
        cin >> xx1 >> yy1 >> xx2 >> yy2 >> vv1 >> vv2;
        if (xx1 > xx2) swap(xx1, xx2);
        ld l = xx1, r = xx2;
        for (int i = 1; i <= 100; i++) {
            ld mid1 = (2.0*l + r)/3.0;
            ld mid2 = (l + 2.0*r)/3.0;
            if (f(mid1) <= f(mid2)) r = mid2;
            else l = mid1;
        }
       // cout << fixed << setprecision(5) << l << ' ' << f(l) << '\n';
        cout << fixed << setprecision(5) << min(f(l), f(r)) << '\n';
    }
	return 0;
}
