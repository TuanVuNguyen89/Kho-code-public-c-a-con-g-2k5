/**
*    Author :  Nguyen Tuan Vu
*    Created : 18.04.2022
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

long long n, s;

bool check(long long x) {
    long long y = x;
    while (y) {
        x -= y%10;
        y /= 10;
    }
    return (x >= s);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    cin >> n >> s;
    long long l = s - 1, r = n + 1;
    while (r - l > 1) {
        long long mid = (l + r)>>1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << n - r + 1;
	return 0;
}
