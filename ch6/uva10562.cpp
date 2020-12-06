/* uva10562
 * 2020/12/06
 * 星期天 13:02
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

string ts[210];
int n;

void solve(int row, int col) {
    printf("%c(", ts[row][col]);
    // printf("%d %d\n", row, col);
    if (row + 1 < n && ts[row + 1][col] == '|') {
        int i = col;
        while (i - 1 >= 0 && ts[row + 2][i - 1] == '-') i--;
        while (ts[row + 2][i] == '-' && ts[row + 3][i] != '\0') {
            if (!isspace(ts[row + 3][i])) solve(row + 3, i);
            i++;
        }
    }
    printf(")");
    return;
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    scanf("%d", &T);
    getchar();
    while (T--) {
        string s;
        n = 0;
        while (getline(cin, s) && s[0] != '#') {
            ts[n++] = s;
        }
        printf("(");
        if (n) {
            _for(i, 0, sz(ts[0])) {
                if (ts[0][i] != ' ') {
                    solve(0, i);
                    break;
                }
            }
        }
        printf(")\n");
    }
    // cerr << "Accept!" << endl;
    return 0;
}
/*
(A(B()C(E()F())D(G())))
(e(f()g()))
*/