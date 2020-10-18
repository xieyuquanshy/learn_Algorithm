/* uva1368
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
char a[55][1010];
char ans[1010];
int cnt[27];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            mem(cnt, 0);
            for (int j = 0; j < n; ++j) {
                cnt[a[j][i] - 'A']++;
            }
            char ch = 'A';
            int mm = cnt[0];
            for (int j = 1; j < 26; ++j) {
                if (cnt[j] > mm) {
                    mm = cnt[j];
                    ch = 'A' + j;
                }
            }
            ans[i] = ch;
            sum += n - mm;
        }
        for (int i = 0; i < m; ++i) printf("%c", ans[i]);
        printf("\n%d\n", sum);
    }
    return 0;
}