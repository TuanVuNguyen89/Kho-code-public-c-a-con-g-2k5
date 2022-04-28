/**
*    Author :  Nguyen Tuan Vu
*    Created : 28.04.2022
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

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;
const int Mod2 = 998244353;
const int base = 31;

string s;
int n, Pow[N], Pow2[N], Hash[N], Hash2[N], lazy[N];

int get(int l, int r) {
    return (Hash[r] - 1ll * Hash[l - 1] * Pow[r - l + 1] % Mod + Mod) % Mod;
}

int get2(int l, int r) {
    return (Hash2[r] - 1ll * Hash2[l - 1] * Pow2[r - l + 1] % Mod2 + Mod2) % Mod2;
}

bool check(int st, int len) {
    return ((get(1, len) == get(st, st + len - 1)) && (get2(1, len), get2(st, st + len - 1)));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    cin >> s; n = s.size();
    s = ' ' + s;
    Pow[0] = Pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        Pow[i] = 1ll * Pow[i - 1] * base % Mod;
        Pow2[i] = 1ll * Pow2[i - 1] * base % Mod2;
        Hash[i] = (1ll * Hash[i - 1] * base % Mod + s[i] - 'A' + 1) % Mod;
        Hash2[i] = (1ll * Hash2[i - 1] * base % Mod2 + s[i] - 'A' + 1) % Mod2;
    }

    for (int i = 1; i <= n; i++) {
        int l = 0, r = n - i + 2;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) l = mid;
            else r = mid;
        }
        lazy[1]++; lazy[l + 1]--;
    }

    for (int i = 1; i <= n; i++) lazy[i] += lazy[i - 1];

    vector <pair <int, int>> ans;
    for (int i = 1; i <= n; i++) if (check(n - i + 1, i)){
        ans.push_back({i, lazy[i]});
    }

    cout << ans.size() << '\n';
    for (auto x:ans) cout << x.first << ' ' << x.second << '\n';
	return 0;
}
