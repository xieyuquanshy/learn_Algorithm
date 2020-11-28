/* uva548
 * 2020/11/25
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define bg begin()
#define ed end()
#define mp make_pair
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define Test

int l[N], r[N], a[N], b[N], n;

int build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return 0;
    int rt = b[r2];
    int p = l1;
    while (p < n and a[p] != rt) p++;
    int cnt = p - l1;
    l[rt] = build(l1, p - 1, l2, l2 + cnt - 1);
    r[rt] = build(p + 1, r1, l2 + cnt, r2 - 1);
    return rt;
}

int ans, v;

void dfs(int u, int sum) {
    sum += u;
    if (!l[u] && !r[u]) {
        if (sum < ans || (sum == ans && u < v)) {
            v = u;
            ans = sum;
        }
        return;
    }
    if (l[u]) dfs(l[u], sum);
    if (r[u]) dfs(r[u], sum);
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        stringstream ss(s1), sss(s2);
        // cout << s1 << endl << s2 << endl;
        int j = 0, x;
        while (ss >> x) a[j++] = x;
        j = 0;
        while (sss >> x) b[j++] = x;
        n = j;
        if (n <= 0) break;
        build(0, n - 1, 0, n - 1);
        ans = v = INF;
        dfs(b[n - 1], 0);
        cout << v << endl;
    }
    return 0;
}