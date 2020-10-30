/* uva136
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
int f[] = {2, 3, 5};
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(1);
    set<ll> s;
    s.insert(1);
    for (int i = 1;; ++i) {
        ll x = q.top();
        q.pop();
        if (i == 1500) {
            printf("The 1500'th ugly number is %lld.\n", x);
            break;
        }
        _for(j, 0, 3) {
            ll tmp = x * f[j];
            if (s.count(tmp)) continue;
            s.insert(tmp);
            q.push(tmp);
        }
    }
    return 0;
}