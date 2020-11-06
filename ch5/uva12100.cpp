/* uva12100
 * 2020/11/06
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
#define Test

struct node {
    int qq, id;
    node() {}
    node(int qq, int id) : qq(qq), id(id) {}
};

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        deque<node> dq;
        _for(i, 0, n) {
            int x;
            cin >> x;
            dq.push_back(node(x, i));
        }
        int t = 1;
        while (1) {
            node u = dq.front();
            dq.pop_front();
            bool ok = false;
            for (auto it = dq.begin(); it != dq.end(); ++it) {
                if (it->qq > u.qq) {
                    dq.push_back(u);
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                if (u.id == m) {
                    printf("%d\n", t);
                    break;
                }
                t++;
            }
        }
    }
    return 0;
}