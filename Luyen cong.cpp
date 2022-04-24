/**
*    Author :  Nguyen Tuan Vu
*    Created : 24.04.2022
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
int n, K, L, query, dp[N][6][6];

struct Data {
    int a, b, c;
} a[N];

struct Query{
    int p, x, y, z;
} Q[N];

void sub1() {
    for (int t = 0; t <= query; t++){

        int id = Q[t].p; a[id].a = Q[t].x; a[id].b = Q[t].y; a[id].c = Q[t].z;

        for (int i = 0; i <= n; i++)
            for (int k = 0; k <= K; k++)
                for (int l = 0; l <= L; l++)
                    dp[i][k][l] = 0;

        for (int i = 0; i < n; i++)
            for (int k = 0; k <= K; k++)
                for (int l = 0; l <= L; l++) {
                    maximize(dp[i + 1][k + 1][l], dp[i][k][l] + a[i + 1].b);
                    maximize(dp[i + 1][k][l + 1], dp[i][k][l] + a[i + 1].c);
                    maximize(dp[i + 1][k][l], dp[i][k][l] + a[i + 1].a);
                }

        cout << dp[n][K][L] << '\n';
    }
}

void sub2() {
    int id = Q[1].p;
    swap(a[n], a[id]);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= K; k++)
            for (int l = 0; l <= L; l++) {
                maximize(dp[i + 1][k + 1][l], dp[i][k][l] + a[i + 1].b);
                maximize(dp[i + 1][k][l + 1], dp[i][k][l] + a[i + 1].c);
                maximize(dp[i + 1][k][l], dp[i][k][l] + a[i + 1].a);
            }

    for (int t = 0; t <= query; t++) {
        int id = Q[t].p;
        if (id != 0) id = n;
        a[id].a = Q[t].x; a[id].b = Q[t].y; a[id].c = Q[t].z;

        cout << max({dp[n - 1][K - 1][L] + a[n].b, dp[n - 1][K][L - 1] + a[n].c, dp[n - 1][K][L] + a[n].a}) << '\n';
    }
}

void sub3() {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i].a;

    set <pair <int, int>> satisfy, rem;

    for (int i = 1; i <= n; i++) {
        satisfy.insert({a[i].b - a[i].a, i});
        if (satisfy.size() > K){
            rem.insert(*satisfy.begin());
            satisfy.erase(satisfy.begin());
        }
    }

    for (int t = 0; t <= query; t++) {

        if (t == 0) {
            int ans = 0;
            for (auto it:satisfy) ans += it.first;
            cout << ans + sum << '\n';
            continue;
        }

        bool ok = 0;
        for (auto it:satisfy) if (it.second == Q[t].p) ok = 1;

        int id = Q[t].p;
        if (ok == 0) rem.erase({a[id].b - a[id].a, id});

        sum -= a[id].a;
        a[id].a = Q[t].x; a[id].b = Q[t].y; a[id].c = Q[t].z; sum += a[id].a;

        if (ok == 0) rem.insert({a[id].b - a[id].a, id});

        if (ok == 1) {
            for (auto it:satisfy) if (it.second == Q[t].p) {
                satisfy.erase(it);
                break;
            }

            satisfy.insert({a[id].b - a[id].a, id});
        }

        if (n > K && (*satisfy.begin()).first < (*(--rem.end())).first) {
                satisfy.insert(*(--rem.end()));
                rem.insert(*satisfy.begin());
                satisfy.erase(satisfy.begin());
                rem.erase(--rem.end());
            }

        int ans = 0;
            for (auto it:satisfy) ans += it.first;

        cout << ans + sum << '\n';
    }
}

int it[4 * N][5][5];

void update(int i, int l, int r, int u, int val1, int val2, int val3){
	if (l > u || r < u) return;
	if (l == r) {
		it[i][0][0] = val1;
		it[i][1][0] = val2;
		it[i][0][1] = val3;
		return;
	}
	int mid = (l + r)>>1;
	update(i<<1, l, mid, u, val1, val2, val3);
	update(i<<1|1, mid + 1, r, u, val1, val2, val3);
	for (int cnt_k = 0; cnt_k <= K; cnt_k++) for (int cnt_l = 0; cnt_l <= L; cnt_l++){
		it[i][cnt_k][cnt_l] = 0;
		for (int b = 0; b <= cnt_k; b++) for (int c = 0; c <= cnt_l; c++)
			maximize(it[i][cnt_k][cnt_l], it[i<<1][b][c] + it[i<<1|1][cnt_k - b][cnt_l - c]);
	}
}

void sub4() {
    for (int i = 1; i <= n; i++) update(1, 1, n, i, a[i].a, a[i].b, a[i].c);
    cout << it[1][K][L] << '\n';
	for (int i = 1; i <= query; i++){
		int p = Q[i].p, x = Q[i].x, y = Q[i].y, z = Q[i].z;
		update(1, 1, n, p, x, y, z);
		cout << it[1][K][L] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
    int T; cin >> T;

    cin >> n >> K >> L >> query;
    for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
    for (int i = 1; i <= query; i++) cin >> Q[i].p >> Q[i].x >> Q[i].y >> Q[i].z;

    if (T == 1) sub1();
    if (T == 2) sub2();
    if (T == 3) sub3();
    if (T == 4) sub4();
	return 0;
}
