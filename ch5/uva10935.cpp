/* uva10935
 * 2020/11/04
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

void solve(int n) {
    deque<int> q;
    _rep(i, 1, n) q.push_back(i);
    printf("Discarded cards:");
    bool f = true;
    while (sz(q) >= 2) {
        printf("%s %d", f ? "" : ",", q.front());
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
        if (f)
            f = 0;
    }
    printf("\nRemaining card: %d\n", q.front());
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        solve(n);
    }
    return 0;
}