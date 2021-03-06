/* uva1225
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

int dcnt[10];

void solve(int &n) {
    mem(dcnt, 0);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x) {
            dcnt[x % 10]++;
            x /= 10;
        }
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        solve(n);
        for (int i = 0; i < 10; ++i) {
            printf("%d%s", dcnt[i], i == 9 ? "\n" : " ");
        }
    }
    return 0;
}