/* uva540
 * 2020/10/25
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
const int N = 1e3 + 10;
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

map<int, int> mt;
int n;

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int kase = 1;
    while (~scanf("%d", &n) && n) {
        mt.clear();
        _for(i, 0, n) {
            int x, t;
            scanf("%d", &t);
            while (t--) {
                scanf("%d", &x);
                mt[x] = i;
            }
        }
        printf("Scenario #%d\n", kase++);
        string op;
        int x;
        queue<int> q, q2[N];
        while (cin >> op && op[0] != 'S') {
            if (op[0] == 'E') {
                scanf("%d", &x);
                if (q2[mt[x]].empty()) q.push(mt[x]);
                q2[mt[x]].push(x);
            } else {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty()) q.pop();
            }
        }
        printf("\n");
    }
    return 0;
}