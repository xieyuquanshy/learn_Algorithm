/* uva227
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

char a[10][10];
char b[100];
int bx, by;
bool f;
void solve(char op) {
    if (op == 'A') {
        int x = bx - 1;
        if (x < 0)
            f = false;
        else {
            swap(a[bx][by], a[x][by]);
            bx = x;
        }
    } else if (op == 'B') {
        int x = bx + 1;
        if (x >= 5) {
            f = false;
        } else {
            swap(a[bx][by], a[x][by]);
            bx = x;
        }
    } else if (op == 'L') {
        int y = by - 1;
        if (y < 0) {
            f = false;
        } else {
            swap(a[bx][by], a[bx][y]);
            by = y;
        }
    } else if (op == 'R') {
        int y = by + 1;
        if (y >= 5) {
            f = false;
        } else {
            swap(a[bx][by], a[bx][y]);
            by = y;
        }
    } else {
        f = false;
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int kase = 1;
    for (;;) {
        f = true;
        char ch = getchar();
        while (ch == '\n') {
            ch = getchar();
        }

        if (ch == 'Z') {
            return 0;
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                while (ch == '\n' && j != 4) ch = getchar();
                if (ch == '\n')
                    a[i][j] = ' ';
                else
                    a[i][j] = ch;
                if (a[i][j] == ' ') {
                    bx = i, by = j;
                }
                ch = getchar();
            }
        }

        int k = 0;
        while (1) {
            while (ch == '\n') ch = getchar();
            // cout << ch << endl;
            if (ch == '0') break;
            b[k++] = ch;
            ch = getchar();
        }
        while (ch != '0') ch = getchar();
        for (int i = 0; i < k; ++i) {
            solve(b[i]);
            if (!f) break;
        }
        if (kase != 1) printf("\n");
        printf("Puzzle #%d:\n", kase++);
        if (!f) {
            printf("This puzzle has no final configuration.\n");
        } else {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    printf("%c%s", a[i][j], j == 4 ? "\n" : " ");
                }
            }
        }
    }
    return 0;
}