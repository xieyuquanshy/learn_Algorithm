/* uva1595
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
const int N = 2e4 + 10;
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

map<pair<int, int>, bool> my;

bool check(const int &u) {
    for (auto it = my.begin(); it != my.end(); ++it) {
        auto tmp = make_pair(u - it->first.first, it->first.second);
        if (!my.count(tmp))
            return false;
    }
    return true;
}

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
        my.clear();
        int n;
        cin >> n;
        int max_x = -20000, min_x = 20000;
        _for(i, 0, n) {
            int x, y;
            cin >> x >> y;
            x += 10000, y += 10000;
            my[make_pair(x, y)] = 1;
            max_x = max(max_x, x);
            min_x = min(min_x, x);
        }
        int u = (max_x + min_x);
        bool ok = 1;
        ok = check(u);

        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}