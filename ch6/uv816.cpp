/* uv816
 * 2020/11/30
 * 星期一 21:41
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

int _map[10][10][5][4];

struct node {
    int x, y, dir;
    node(int x = 0, int y = 0, int dir = 0) : x(x), y(y), dir(dir) {}
} bp, ep;

int get_new_id(int dir, int tr) {
    if (tr == 0)
        return (dir + 3) % 4;
    else if (tr == 2)
        return (dir + 1) % 4;
    return dir;
}

int get_nesw(char ch) {
    if (ch == 'N')
        return 0;
    else if (ch == 'E')
        return 1;
    else if (ch == 'S')
        return 2;
    else
        return 3;
}

int get_lfr(char ch) {
    if (ch == 'L')
        return 0;
    else if (ch == 'F')
        return 1;
    else
        return 2;
}

node walk(int x, int y, int dir, int tr) {
    if ((dir == 0 && tr == 0) || (dir == 2 && tr == 2) || (dir == 3 && tr == 1))
        return node(x, y - 1, get_new_id(dir, tr));

    else if ((dir == 1 && tr == 0) || (dir == 3 && tr == 2) ||
             (dir == 0 && tr == 1))
        return node(x - 1, y, get_new_id(dir, tr));

    else if ((dir == 0 && tr == 2) || (dir == 2 && tr == 0) ||
             (dir == 1 && tr == 1))
        return node(x, y + 1, get_new_id(dir, tr));

    else if ((dir == 1 && tr == 2) || (dir == 3 && tr == 0) ||
             (dir == 2 && tr == 1))
        return node(x + 1, y, get_new_id(dir, tr));
    return node();
}

int tt[10][10][5];
node pre[10][10][5];

void print(node u) {
    vector<node> ans;
    for(;;) {
        ans.pb(u);
        if(tt[u.x][u.y][u.dir]==0) break;
        u = pre[u.x][u.y][u.dir];
    }
    ans.pb(bp);
    int j = 0;
    for (int i = sz(ans) - 1; i >= 0; --i, j++) {
        if (j != 0 && j % 10 == 0) printf("\n"), j = 0;
        if (j == 0) printf(" ");
        printf(" (%d,%d)", ans[i].x, ans[i].y);
    }
    if (j != 0) printf("\n");
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string tn;
    while (cin >> tn && tn != "END") {
        mem(_map, 0);
        mem(tt, -1);

        int bx, by, ex, ey;
        char c_d;
        cin >> bx >> by >> c_d >> ex >> ey;
        int t_d = get_nesw(c_d);
        bp = node(bx, by, t_d);  // begin position

        node abp = walk(bx, by, t_d, 1);
        pre[abp.x][abp.y][abp.dir] = bp;
        tt[abp.x][abp.y][abp.dir] = 0;

        int x, y;
        while (cin >> x && x) {
            cin >> y;
            string op;
            while (cin >> op && op[0] != '*') {
                int d = get_nesw(op[0]);
                _for(j, 1, sz(op)) { _map[x][y][d][get_lfr(op[j])] = 1; }
            }
        }

        queue<node> Q;
        Q.push(abp);
        bool f = false;
        int cnt = 1;
        cout << tn << endl;

        while (!Q.empty()) {
            node u = Q.front(), v;
            Q.pop();

            // printf("%d (%d,%d,%d)\n", cnt++, u.x, u.y, u.dir);
            if (u.x == ex && u.y == ey) {
                f = true;

                print(u);
                break;
            }
            _for(i, 0, 3) {
                v = walk(u.x, u.y, u.dir, i);
                if (_map[u.x][u.y][u.dir][i] && v.x >= 1 && v.y >= 1 &&
                    v.x <= 9 && v.y <= 9 && tt[v.x][v.y][v.dir] < 0) {
                    // able to walk

                    tt[v.x][v.y][v.dir] = tt[u.x][u.y][u.dir] + 1;
                    Q.push(v);
                    pre[v.x][v.y][v.dir] = u;
                }
            }
        }

        if (!f) {
            printf("  No Solution Possible\n");
        }
    }
    return 0;
}