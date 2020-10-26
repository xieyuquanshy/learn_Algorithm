/* uva201
 * 2020/10/24
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

int n, line[15][15][15][15];

bool get(int x, int y, int len) {
    if (x + len > n || y + len > n) return 0;
    _for(i, y, y + len) {
        if (!line[x][i][x][i + 1] || !line[x + len][i][x + len][i + 1])
            return 0;
    }
    _for(i, x, x + len) {
        if (!line[i][y][i + 1][y] || !line[i][y + len][i + 1][y + len])
            return 0;
    }
    return 1;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int kase = 1;
    while (~scanf("%d", &n)) {
        int m;
        scanf("%d", &m);
        mem(line, 0);
        if (kase != 1) printf("\n**********************************\n\n");
        while (m--) {
            char s[2];
            int x, y;
            scanf("%s%d%d", s, &x, &y);
            if (s[0] == 'H')
                line[x][y][x][y + 1] = 1;
            else if (s[0] == 'V')
                swap(x, y), line[x][y][x + 1][y] = 1;
        }
        printf("Problem #%d\n\n", kase++);
        bool have = false;
        _rep(i, 1, 9) {
            int cnt = 0;
            _rep(ix, 1, n - i) {
                _rep(jx, 1, n - i) { cnt += get(ix, jx, i); }
            }
            if (cnt) {
                printf("%d square (s) of size %d\n", cnt, i);
                have = true;
            }
        }
        if (!have) printf("No completed squares can be found.\n");
    }
    return 0;
}