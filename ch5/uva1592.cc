/* uva1592
 * 2020/10/28
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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

int n, m;
map<string, int> sid;
int getId(string s) {
    if (sid.count(s)) return sid[s];
    return sid[s] = sz(sid);
}
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string t, sp;
    while (~scanf("%d%d", &n, &m)) {
        vector<int> table[n + 1];
        sid.clear();
        getchar();
        _for(i, 0, n) {
            getline(cin, t);
            stringstream input(t);
            while (getline(input, sp, ',')) table[i].pb((getId(sp)));
        }
        bool ok = false;
        _for(c1, 0, m - 1) {
            _for(c2, c1 + 1, m) {
                map<pair<int, int>, int> p;
                _for(k, 0, n) {
                    if (p.find({table[k][c1], table[k][c2]}) != p.end()) {
                        ok = true;
                        printf("NO\n%d %d\n%d %d\n",
                               p[{table[k][c1], table[k][c2]}] + 1, k + 1,
                               c1 + 1, c2 + 1);
                        break;
                    } else {
                        p[{table[k][c1], table[k][c2]}] = k;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (!ok) printf("YES\n");
    }
    return 0;
}