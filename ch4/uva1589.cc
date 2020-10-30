/* uva1589
 * 2020/10/29
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

int n, bx, by, rx, ry;
bool lose;
vector<pair<int, int>> p[4];
bool at[15][15], qz[15][15];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void che(int cx, int cy) {
    int ttx = cx, tty = cy + 1;

    while (tty <= 9 && !qz[ttx][tty]) {
        at[ttx][tty++] = 1;
    }
    tty = cy - 1;
    while (tty >= 1 && !qz[ttx][tty]) {
        at[ttx][tty--] = 1;
    }
    tty = cy, ttx = cx - 1;
    while (ttx >= 1 && !qz[ttx][tty]) {
        at[ttx--][tty] = 1;
    }
    ttx = cx + 1;
    while (ttx <= 10 && !qz[ttx][tty]) {
        at[ttx++][tty] = 1;
    }
}

void pao(int px, int py) {
    int ttx = px, tty = py;
    ttx = px - 1;
    while (ttx >= 1) {
        if (!qz[ttx][tty]) {
            ttx--;
            continue;
        }
        ttx--;
        while (ttx >= 1 && !qz[ttx][tty]) {
            at[ttx--][tty] = 1;
        }
        break;
    }
    ttx = px + 1;
    while (ttx <= 10) {
        if (!qz[ttx][tty]) {
            ttx++;
            continue;
        }
        ttx++;
        while (ttx <= 10 && !qz[ttx][tty]) {
            at[ttx++][tty] = 1;
        }
        break;
    }
    ttx = px, tty = py + 1;
    while (tty <= 9) {
        if (!qz[ttx][tty]) {
            tty++;
            continue;
        }
        tty++;
        while (tty <= 9 && !qz[ttx][tty]) {
            at[ttx][tty++] = 1;
        }
        break;
    }
    tty = py - 1;
    while (tty >= 1) {
        if (!qz[ttx][tty]) {
            tty--;
            continue;
        }
        tty--;
        while (tty >= 1 && !qz[ttx][tty]) {
            at[ttx][tty--] = 1;
        }
        break;
    }
}
void ma(int mx, int my) {
    _for(i, 0, 4) {
        int ttx = mx, tty = my;
        if (i == 0) {
            if (ttx - 1 >= 1 && !qz[ttx - 1][tty]) {
                if (ttx - 2 >= 1)
                    at[ttx - 2][tty - 1] = at[ttx - 2][tty + 1] = 1;
            }
        } else if (i == 1) {
            if (tty + 1 <= 9 && !qz[ttx][tty + 1]) {
                if (tty + 2 <= 9)
                    at[ttx - 1][tty + 2] = at[ttx + 1][tty + 2] = 1;
            }
        } else if (i == 2) {
            if (ttx + 1 <= 10 && !qz[ttx + 1][tty]) {
                if (ttx + 2 <= 10)
                    at[ttx + 2][tty - 1] = at[ttx + 2][tty + 1] = 1;
            }
        } else {
            if (tty - 1 >= 1 && !qz[ttx][tty - 1]) {
                if (tty - 2 >= 1)
                    at[ttx - 1][tty - 2] = at[ttx + 1][tty - 2] = 1;
            }
        }
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n >> bx >> by && n) {
        char s[2];
        lose = false;
        mem(at, 0);
        mem(qz, 0);
        _for(i, 1, 4) p[i].clear();
        _for(i, 0, n) {
            int x, y;
            cin >> s >> x >> y;
            if (abs(x - bx) + abs(y - by) == 1) {
                if (s[0] == 'R') che(x, y);
                if (s[0] == 'H') ma(x, y);
                if (s[0] == 'C') pao(x, y);
                continue;
            }
            if (s[0] == 'G')
                rx = x, ry = y;
            else if (s[0] == 'R')
                p[1].pb(make_pair(x, y));
            else if (s[0] == 'H')
                p[2].pb(make_pair(x, y));
            else if (s[0] == 'C')
                p[3].pb(make_pair(x, y));

            qz[x][y] = 1;
        }
        // _for(i, 1, 11) {
        //     _for(j, 1, 10) { printf("%d ", qz[i][j]); }
        //     printf("\n");
        // }
        //先判断能否直接将死
        bool gg = (ry == by);
        if (gg) {
            _for(i, bx + 1, rx) {
                if (qz[i][by]) {
                    gg = false;
                    break;
                }
            }
        }
        if (gg) {
            printf("NO\n");
            continue;
        }
        // 再判断将军
        int ttx = rx - 1, tty = ry;
        while (ttx >= 1 && !qz[ttx][tty]) {
            at[ttx--][tty] = 1;
        }
        // 判断车
        _for(i, 0, sz(p[1])) {
            pair<int, int> t = p[1][i];
            che(t.first, t.second);
        }
        // 判断炮
        _for(i, 0, sz(p[3])) {
            pair<int, int> t = p[3][i];
            pao(t.first, t.second);
        }
        //判断马
        _for(i, 0, sz(p[2])) {
            pair<int, int> t = p[2][i];
            ma(t.first, t.second);
        }

        _for(i, 0, 4) {
            int ttx = bx + dx[i], tty = by + dy[i];
            if (ttx < 1 || ttx > 3 || tty < 4 || tty > 6) continue;
            if (!at[ttx][tty]) {
                lose = true;
                break;
            }
        }
        // cout << endl << endl;

        // _for(i, 1, 11) {
        //     _for(j, 1, 10) { printf("%d ", at[i][j]); }
        //     printf("\n");
        // }

        if (lose) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        // cout << getchar() << endl;
    }
    return 0;
}