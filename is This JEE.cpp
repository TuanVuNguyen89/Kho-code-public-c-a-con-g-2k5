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

#define pi 3.14159265358979323846264338
#define eps 0.000000000000000001

using namespace std;

void file(){
	#define TASK ""
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

double b, c;

double f(double x) {
    return 1.0 * (x * x + b * x + c) / sin(x);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	int t; cin >> t;
	while (t--) {
	    cin >> b >> c;
        double l = eps, r = pi/2 - eps;
        for (int i = 1; i <= 60; i++) {
            double mid1 = (2.0 * l + r)/3.0;
            double mid2 = (l + 2.0 * r)/3.0;
            if (f(mid1) <= f(mid2)) r = mid2;
            else l = mid1;
        }
        cout << fixed << setprecision(6) << min(f(l), f(r)) << '\n';
    }
	return 0;
}
