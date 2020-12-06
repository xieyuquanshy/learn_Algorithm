/* uva10305
 * 2020/12/01
 * 星期二 22:17
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
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

int in[110];
vector<int> e[110];

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
        mem(in, 0);
        _rep(i, 1, n) e[i].clear();
        _for(i, 0, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].pb(v);
            in[v]++;
        }

        queue<int> q;
        _rep(i, 1, n) if (!in[i]) q.push(i);
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.pb(u);
            _for(i, 0, sz(e[u])) {
                if (--in[e[u][i]] == 0) {
                    q.push(e[u][i]);
                }
            }
        }
        _for(i, 0, n) { printf("%d%s", ans[i], i == n - 1 ? "\n" : " "); }
    }
    return 0;
}