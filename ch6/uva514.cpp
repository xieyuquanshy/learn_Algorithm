/* uva514
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

int a[1010];

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    bool f = true;
    while (cin >> n && n) {
        while (~scanf("%d", a + 1)) {
            if (a[1] == 0) break;
            _rep(i, 2, n) scanf("%d", &a[i]);
            stack<int> s;
            int k = 1;  // 当前的数
            bool ok = true;
            _rep(i, 1, n) {
                while (k <= n and k <= a[i])
                    s.push(k++);  // 如果当前的数比a[i]小，那么就加到他
                if (!s.empty() and s.top() == a[i]) {  // 如果加到它
                    s.pop();
                } else if (s.empty() && k == a[i]) {  // 如果刚好相等
                    k++;
                } else {  // 否则不行
                    ok = false;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}