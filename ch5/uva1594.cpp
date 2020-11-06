/* uva1594
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
#define txt
#define Quick                                                                  \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);

bool check(vector<int> &v) {
    _for(i, 0, sz(v)) if (v[i]) return 0;
    return 1;
}

void solve(vector<int> &v) {
    int n = sz(v);
    vector<int> b = v;
    _for(i, 0, n) { v[i] = abs(b[i] - b[(i + 1) % n]); }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        _for(i, 0, n) cin >> v[i];
        bool zero = false;
        _rep(t, 1, 1000) {
            if (check(v)) {
                zero = true;
                break;
            }
            solve(v);
        }
        printf("%s\n", zero ? "ZERO" : "LOOP");
    }
    return 0;
}