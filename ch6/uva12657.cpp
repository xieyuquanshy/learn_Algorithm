/* uva12657
 * 2020/11/22
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

int n, m;
int l[N], r[N];
int r_cnt;

inline void link(int x, int y) { r[x] = y, l[y] = x; }

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int kase = 1, x, y;
    while (~scanf("%d%d", &n, &m)) {
        _rep(i, 1, n) {
            l[i] = i - 1;
            r[i] = (i + 1) % (n + 1);
        }
        l[0] = n;
        r[0] = 1;
        r_cnt = 0;

        while (m--) {
            int op;
            scanf("%d", &op);
            if (op == 4)
                r_cnt = !r_cnt;  // 两次翻转相当于没有翻转
            else {
                scanf("%d%d", &x, &y);
                if (op != 3 && r_cnt) op = 3 - op;  // 翻转过后放左边就是放右边
                if (op == 1 && l[y] == x) continue;
                if (op == 2 && r[y] == x) continue;

                int lx = l[x], rx = r[x], ly = l[y], ry = r[y];

                // 以下都是链表的基本操作
                if (op == 1) {
                    link(lx, rx);
                    link(ly, x);
                    link(x, y);
                } else if (op == 2) {
                    link(lx, rx);
                    link(x, ry);
                    link(y, x);
                } else if (op == 3) {
                    if (r[x] == y) {
                        link(lx, y);
                        link(x, ry);
                        link(y, x);
                    } else if (r[y] == x) {
                        link(ly, x);
                        link(y, rx);
                        link(x, y);
                    } else {
                        link(lx, y);
                        link(ly, x);
                        link(y, rx);
                        link(x, ry);
                    }
                }
            }
        }
        ll sum = 0;
        int k = 0;
        _rep(i, 1, n) {
            k = r[k];
            if (i % 2) sum += k;
        }
        if (r_cnt & 1 && n % 2 == 0) sum = 1ll * n * (n + 1) / 2 - sum;
        printf("Case %d: %lld\n", kase++, sum);
    }
    return 0;
}