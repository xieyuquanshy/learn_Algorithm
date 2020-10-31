/* uva220
 * 2020/10/31
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

char mp[10][10];
char cur;
bool is_legal;
int black, white;
vector<pair<int, int>> pos;
int dir[8][2] = {{0, 1},  {1, 0},  {-1, 0}, {0, -1},
                 {-1, 1}, {1, -1}, {1, 1},  {-1, -1}};

void print() {
    _rep(i, 1, 8) {
        _rep(j, 1, 8) { printf("%c", mp[i][j]); }
        printf("\n");
    }
}

void legal() {
    pos.clear();
    _rep(i, 1, 8) {
        _rep(j, 1, 8) {
            if (mp[i][j] == '-') {
                bool ok = false;
                _for(k, 0, 8) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    int cnt = 0;
                    while (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
                        if (mp[nx][ny] == '-') break;
                        if (mp[nx][ny] != cur) {
                            cnt++;
                        } else if (mp[nx][ny] == cur) {
                            ok = cnt > 0;
                            break;
                        }
                        nx += dir[k][0], ny += dir[k][1];
                    }

                    if (ok) break;
                }
                if (ok) {
                    pos.pb(make_pair(i, j));
                }
            }
        }
    }
    if (!sz(pos)) is_legal = false;
}

void put(int &r, int &c) {
    mp[r][c] = cur;
    if (cur == 'W')
        white++;
    else
        black++;
    _for(k, 0, 8) {
        int nx = r + dir[k][0], ny = c + dir[k][1];
        int cnt = 0;
        bool ok = false;
        while (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8) {
            if (mp[nx][ny] == '-') break;
            if (mp[nx][ny] != cur) {
                cnt++;
            } else if (mp[nx][ny] == cur) {
                ok = cnt > 0;
                break;
            }
            nx += dir[k][0], ny += dir[k][1];
        }
        if (ok) {
            for (int i = r + dir[k][0], j = c + dir[k][1]; mp[i][j] != cur;
                 i += dir[k][0], j += dir[k][1]) {
                mp[i][j] = cur;
                if (cur == 'W')
                    white++, black--;
                else
                    white--, black++;
            }
        }
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    _for(ca, 0, T) {
        if (ca) puts("");
        black = white = 0;
        _rep(i, 1, 8) {
            _rep(j, 1, 8) {
                cin >> mp[i][j];
                if (mp[i][j] == 'W')
                    white++;
                else if (mp[i][j] == 'B')
                    black++;
            }
        }
        string op;
        cin >> cur;
        is_legal = true;
        while (cin >> op && op[0] != 'Q') {
            if (op[0] == 'L') {
                legal();
                if (!is_legal) {
                    printf("No legal move.\n");
                } else {
                    sort(all(pos));
                    _for(i, 0, sz(pos)) {
                        pair<int, int> t = pos[i];
                        printf("(%d,%d)%s", t.first, t.second,
                               i == sz(pos) - 1 ? "\n" : " ");
                    }
                }
            } else if (op[0] == 'M') {
                int r = op[1] - '0', c = op[2] - '0';
                legal();
                if (!is_legal) {
                    cur = cur == 'B' ? 'W' : 'B';
                    is_legal = true;
                }
                put(r, c);
                printf("Black - %2d White - %2d\n", black, white);
                cur = cur == 'B' ? 'W' : 'B';
                is_legal = true;
            }
        }
        print();
    }
    return 0;
}