/* uva340
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
const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define txt

int a[N], b[N];

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    int kase = 1;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        printf("Game %d:\n", kase++);
        while (1) {
            int A = 0, B = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &b[i]);
                if (a[i] == b[i]) A++;
            }
            if (b[0] == 0) break;
            // 都出现过 - 位置对 = 都出现过但位置不对
            for (int num = 1; num <= 9; ++num) {
                int c1 = 0, c2 = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i] == num) c1++;
                    if (b[i] == num) c2++;
                }
                B += min(c1, c2);
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}