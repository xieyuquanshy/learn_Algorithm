/* uva133
 * 2020/10/21
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

bool vis[20];
int n, k, m;
void pos(int &p, int d, int c) {
    while (c--) {
        do {
            p = (p + d + n - 1) % n + 1;
        } while (vis[p]);
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d%d%d", &n, &k, &m) && n) {
        mem(vis, 0);
        int left = n, p1 = n, p2 = 1;
        while (left) {
            pos(p1, 1, k);
            pos(p2, -1, m);
            printf("%3d", p1), left--;
            if (p1 != p2) printf("%3d", p2), left--;
            vis[p1] = vis[p2] = 1;
            if (left) printf(",");
        }
        puts("");
    }
    return 0;
}