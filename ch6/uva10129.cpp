/* uva10129
 * 2020/12/04
 * 星期五 20:54
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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

int _map[30][30];
set<int> alp;
bool vis[30];
int deg[30];

void dfs(int u) {
    if (!vis[u]) {
        vis[u] = 1;
        for (auto v : alp) {
            if (_map[u][v] && !vis[v]) {
                dfs(v);
            }
        }
    }
}

void init() {
    mem(_map, 0);
    alp.clear();
    mem(vis, 0);
    mem(deg, 0);
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        init();
        int n;
        cin >> n;
        _for(i, 0, n) {
            string s;
            cin >> s;
            char u = s[0], v = s.back();
            alp.insert(u - 'a');
            alp.insert(v - 'a');
            _map[u - 'a'][v - 'a'] = _map[v - 'a'][u - 'a'] = 1;
            deg[u - 'a']--;
            deg[v - 'a']++;
        }
        dfs(*(alp.begin()));
        if (sz(alp) != accumulate(vis, vis + 26, 0)) {
            cout << "The door cannot be opened.\n";
            continue;
        }
        int even = 0, st = -1, ee = -1;
        for (auto u : alp) {
            if (!deg[u])
                even++;
            else if (deg[u] == -1 && st == -1) {
                st = u;
            } else if (deg[u] == 1 && ee == -1) {
                ee = u;
            } else {
                even = st = ee = -1;
                break;
            }
        }
        if (even == sz(alp) || (even == sz(alp) - 2 && st != -1 && ee != -1)) {
            cout << "Ordering is possible.\n";
        } else {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}