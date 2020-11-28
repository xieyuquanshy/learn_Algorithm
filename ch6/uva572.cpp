/* uva572
 * 2020/11/28
 * 星期六 20:27
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

int n, m;
char _map[110][110];

int dir[][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, -1, 1, 1, -1, 1, -1, -1};

void dfs(int x, int y) {
    _for(i, 0, 8) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && _map[nx][ny] == '@') {
            _map[nx][ny] = '*';
            dfs(nx, ny);
        }
    }
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (~scanf("%d%d", &n, &m) && n) {
        getchar();
        _for(i, 0, n) {
            _for(j, 0, m) { scanf("%c", &_map[i][j]); }
            getchar();
        }
        int ans = 0;
        _for(i, 0, n) {
            _for(j, 0, m) {
                if (_map[i][j] == '@') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}