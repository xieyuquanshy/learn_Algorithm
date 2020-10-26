/* uva10474
 * 2020/10/24
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
const int N = 1e4 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define txt

int a[N];

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, q, kase = 1;
    while (~scanf("%d%d", &n, &q) && n) {
        _for(i, 0, n) scanf("%d", a + i);
        sort(a, a + n);
        printf("CASE# %d:\n", kase++);
        while (q--) {
            int x;
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a;
            if (a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}