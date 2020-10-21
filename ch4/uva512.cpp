/* uva512
 * 2020/10/21
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

int r, c, nr, nc;
int a[55][55], b[55][55];

void init() {
    _rep(i, 1, r) {
        _rep(j, 1, c) { b[i][j] = a[i][j] = (i - 1) * c + j; }
    }
}

void delRow(int row) {
    for (int i = 1; i <= nr; ++i) {
        if (i == row) {
            for (int j = i + 1; j <= nr; ++j) {
                _rep(k, 1, nc) { a[j - 1][k] = a[j][k]; }
            }
            _rep(k, 1, nc) a[nr][k] = 0;
            break;
        }
    }
}

void insRow(int row) {
    for (int i = 1; i <= nr; ++i) {
        if (i == row) {
            for (int j = nr + 1; j >= i + 1; --j) {
                _rep(k, 1, nc) { a[j][k] = a[j - 1][k]; }
            }
            _rep(k, 1, nc) a[i][k] = 0;
            break;
        }
    }
}

void delCol(int col) {
    for (int i = 1; i <= nc; ++i) {
        if (i == col) {
            for (int j = i + 1; j <= nc; ++j) {
                _rep(k, 1, nr) { a[k][j - 1] = a[k][j]; }
            }
            _rep(k, 1, nr) a[k][nc] = 0;
            break;
        }
    }
}

void insCol(int col) {
    _rep(i, 1, nc) {
        if (i == col) {
            for (int j = nc + 1; j >= i + 1; --j) {
                _rep(k, 1, nr) { a[k][j] = a[k][j - 1]; }
            }
            _rep(k, 1, nr) a[k][i] = 0;
            break;
        }
    }
}

void find(int row, int col, int &nrow, int &ncol) {
    _rep(i, 1, nr) {
        _rep(j, 1, nc) {
            if (a[i][j] == b[row][col]) {
                nrow = i;
                ncol = j;
                return;
            }
        }
    }
    nrow = ncol = 0;
    return;
}

void show() {
    _rep(i, 1, nr) {
        _rep(j, 1, nc) { printf("%d ", a[i][j]); }
        printf("\n");
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, T, row, col, kase = 1;
    bool fir = true;
    string op;
    while (~scanf("%d%d", &r, &c) && r) {
        init();
        if (!fir) puts("");
        fir = false;
        scanf("%d", &n);
        nr = r, nc = c;
        vector<int> table;
        while (n--) {
            table.clear();
            cin >> op;
            if (op == "DR") {
                scanf("%d", &T);
                while (T--) {
                    scanf("%d", &row);
                    table.pb(row);
                }
                sort(all(table));
                _for(i, 0, sz(table)) {
                    delRow(table[i] - i);
                    nr--;
                }
            } else if (op == "DC") {
                scanf("%d", &T);
                while (T--) {
                    scanf("%d", &col);
                    table.pb(col);
                }
                sort(all(table));
                _for(i, 0, sz(table)) {
                    delCol(table[i] - i);
                    nc--;
                }
            } else if (op == "IC") {
                scanf("%d", &T);
                while (T--) {
                    scanf("%d", &col);
                    table.pb(col);
                }
                sort(all(table));
                _for(i, 0, sz(table)) {
                    insCol(table[i] + i);
                    nc++;
                }
            } else if (op == "IR") {
                scanf("%d", &T);
                while (T--) {
                    scanf("%d", &row);
                    table.pb(row);
                }
                sort(all(table));
                _for(i, 0, sz(table)) {
                    insRow(table[i] + i);
                    nr++;
                }
            } else if (op == "EX") {
                int r1, c1, r2, c2;
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                swap(a[r1][c1], a[r2][c2]);
            }
            // printf("%d:\n", n);
            // show();
        }
        scanf("%d", &n);
        printf("Spreadsheet #%d\n", kase++);
        while (n--) {
            scanf("%d%d", &row, &col);
            int nrow, ncol;
            find(row, col, nrow, ncol);
            if (a[nrow][ncol])
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", row, col,
                       nrow, ncol);
            else
                printf("Cell data in (%d,%d) GONE\n", row, col);
        }
    }
    return 0;
}