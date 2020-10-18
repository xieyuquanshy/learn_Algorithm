/* uva232
 * 2020/10/18
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
#define txt

int n, m;
char a[20][20];
int iss[20][20];
bool ause[20][20], duse[20][20];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            a[i][j] = '*';
        }
    }
    int kase = 1;
    while (~scanf("%d", &n) && n) {
        mem(ause, 0);
        mem(duse, 0);
        mem(iss, 0);
        scanf("%d", &m);
        getchar();
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%c", &a[i][j]);
                while (a[i][j] == '\n') scanf("%c", &a[i][j]);
                if (a[i][j] != '*' &&
                    (a[i][j - 1] == '*' || a[i - 1][j] == '*'))
                    iss[i][j] = cnt++;
            }
            getchar();
        }

        if (kase != 1) printf("\n");
        printf("puzzle #%d:\nAcross\n", kase++);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (iss[i][j] && !ause[i][j]) {
                    int tj = j;
                    printf("%3d.", iss[i][j]);
                    while (tj <= m && a[i][tj] != '*') {
                        ause[i][tj] = 1;
                        printf("%c", a[i][tj++]);
                    }
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (iss[i][j] && !duse[i][j]) {
                    int ti = i;
                    printf("%3d.", iss[i][j]);
                    while (ti <= n && a[ti][j] != '*') {
                        duse[ti][j] = 1;
                        printf("%c", a[ti++][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}